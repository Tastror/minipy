%{

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>

#include "compiler_bison.h"
#include "../src/log.h"
#include "../src/lexer.h"

int yycolumnno = 1;
size_t last_string_length;
std::string last_string;

bool block_depth_init = false;
int last_block_depth = 0;

struct BlockCell {
    bool use_tab = false;
    std::vector<int> depth_vector;
    int total_depth = 0;
    int total_num = 0;
    BlockCell() {};
    ~BlockCell() {};
    void to_tab() { use_tab = true; }
    void to_space() { use_tab = false; }
    void add(int num) {
        depth_vector.push_back(num);
        total_num += num;
        total_depth++;
    }
    bool del(int times) {
        for (int i = 0; i < times; ++i) {
            if (depth_vector.empty()) {
                return false;
            }
            total_depth--;
            total_num -= depth_vector.back();
            depth_vector.pop_back();
        }
        return true;
    }
    void clear() {
        depth_vector.clear();
        total_depth = total_num = 0;
    }
    // check whether_use_tab(num) == whether_use_tab(use_tab) first
    // -1: not valid
    int get_absolute_depth(int num) {
        if (total_num == num) return total_depth;
        if (num == 0) return 0;
        int res = 0;
        for (unsigned long long i = 0; i < depth_vector.size(); ++i) {
            res += depth_vector[i];
            if (res == num) return i;
        }
        return -1;
    }
} block_depth_cell;

bool totally_new_line = true;
bool no_eof_yet = true;
int tmp_dent = 0;
Token* last_ptr = nullptr;



#define YY_USER_INIT { BEGIN(NEW_LINE_COUNT); }

#define IDN yylval.token_ptr->content.indent_num



#define SET_TOKEN_LINE_COLUMN do { \
    yylval.token_ptr->lineno = yylineno; \
    yylval.token_ptr->columnno = yycolumnno; \
} while(0)



#define LOG_TOKEN(type_string) do { \
    Logger << Log::info \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": " << type_string << ": " << yytext << Log::endl; \
} while(0)

#define LOG_TOKEN_WITH_VALUE(type_string, data) do { \
    Logger << Log::info \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": " << type_string << ": " << yytext \
        << ", value = " << data << Log::endl; \
} while(0)

#define LOG_TOKEN_NEWLINE() do { \
    Logger << Log::info \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": newline" << Log::endl; \
} while(0)

#define LOG_TOKEN_DENT() do { \
    Logger << Log::info \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": tab/space after a new line: " \
        << IDN.space_num << " space(s) and " \
        << IDN.tab_num << " tab(s), absolute = " \
        << IDN.absolute_depth << ", relative = " \
        << IDN.relative_depth \
        << Log::endl; \
} while(0)

#define LOG_TOKEN_INDENT() do { \
    Logger << Log::info << "line " << yylineno << ": indent" << Log::endl; \
} while(0)

#define LOG_TOKEN_DEDENT() do { \
    Logger << Log::info << "line " << yylineno << ": dedent" << Log::endl; \
} while(0)

#define LOG_TOKEN_ERROR(type_string) do { \
    Logger << Log::error \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": " << type_string << ": " << yytext << Log::endl; \
} while(0)

#define LOG_TOKEN_DENT_ERROR(type_string, space_num, tab_num) do { \
    Logger << Log::error \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": " << space_num << " space(s) and " << tab_num << " tab(s), " \
        << type_string << Log::endl; \
} while(0)



#define SAME_LINE_COLUMN_UPDATE \
    do { last_string = std::string(yytext); last_string_length = last_string.size(); yycolumnno += last_string.size(); } while(0)

#define NEW_LINE_COLUMN_UPDATE \
    do { last_string = std::string("\n"); last_string_length = 1; yycolumnno = 1; } while(0)

#define EOF_COLUMN_UPDATE \
    do { last_string = std::string(); last_string_length = 0; } while(0)



#define GENERAL_TOKEN_GEN(a, b) do { \
    yylval.token_ptr = make_token(); \
    yylval.token_ptr->type = a; \
    yylval.token_ptr->content.name = std::string(yytext); \
    SET_TOKEN_LINE_COLUMN; \
    LOG_TOKEN(b); \
    SAME_LINE_COLUMN_UPDATE; \
} while(0)

// this is because flex change the yylineno once I read \n, however I don't want it update this fast.
#define NEWLINE_TOKEN_GEN do { \
    yylval.token_ptr = make_token(); \
    yylval.token_ptr->type = token_type::newline; \
    SET_TOKEN_LINE_COLUMN; \
    yylval.token_ptr->lineno--; \
    LOG_TOKEN_NEWLINE(); \
    NEW_LINE_COLUMN_UPDATE; \
} while(0)

#define STRTEXT_TOKEN_GEN do { \
    yylval.token_ptr = make_token(); \
    yylval.token_ptr->type = token_type::strtext; \
    yylval.token_ptr->content.message = std::string(yytext); \
    SET_TOKEN_LINE_COLUMN; \
    LOG_TOKEN("strtext"); \
    SAME_LINE_COLUMN_UPDATE; \
} while(0)

#define DELIMITER_TOKEN_GEN \
    GENERAL_TOKEN_GEN(token_type::delimiter, "delimiter")

#define OPERATOR_TOKEN_GEN \
    GENERAL_TOKEN_GEN(token_type::operators, "operator")

#define BRACKET_TOKEN_GEN \
    GENERAL_TOKEN_GEN(token_type::bracket, "bracket")

#define KEYWORD_TOKEN_GEN \
    GENERAL_TOKEN_GEN(token_type::keyword, "keyword")

// indent, integer, floats, identifier, error _TOKEN_GEN are not here



// order:
// make_token -> assign -> SET_TOKEN_LINE_COLUMN -> LOG_... -> ..._COLUMN_UPDATE -> BEGIN(...) -> return t_...
// ..._GEN == ( make_token ~ ..._COLUMN_UPDATE )

%}

%option warn nodefault noyywrap yylineno case-sensitive pointer

%x LINE_COMMENT
%x NEW_LINE_COUNT
%x PRODUCE_INDENT
%x PRODUCE_DEDENT
%x SQUOTE_STR_TEXT
%x DQUOTE_STR_TEXT
%x SQUOTE_STR_TEXT_END
%x DQUOTE_STR_TEXT_END

space       [ ]
tab         \t
white       [ \t]
new_line    (\n|\r|\r\n|\n\r)
all_noline  (.)
all         (.|\n|\r)

digit       [0-9]
letter      [_a-zA-Z]
wrong_id    ([0-9]+[_a-zA-Z]+([_a-zA-Z]|[0-9])*)
dec_value   [0-9]+
pure_dec_value ([1-9][0-9]+|[0-9]|0+)
wrong_dec_value (0+[1-9]+[0-9]*)
hex_value   0x[0-9a-fA-F]+
oct_value   0o[0-7]+
bin_value   0b[01]+
float_value ([0-9]*\.[0-9]+|[0-9]+\.)

%%

{white}+    { SAME_LINE_COLUMN_UPDATE; }

{new_line}  {
                totally_new_line = true;
                NEWLINE_TOKEN_GEN;
                BEGIN(NEW_LINE_COUNT);
                return t_newline;
            }

"#"         {  // only use in "# <comment>" after a solid sentense (not just tabs or spaces)
                LOG_TOKEN("comment start sharp");
                SAME_LINE_COLUMN_UPDATE;
                BEGIN(LINE_COMMENT);
            }

<LINE_COMMENT>{new_line} {
                totally_new_line = true;
                NEWLINE_TOKEN_GEN;
                BEGIN(NEW_LINE_COUNT);
                return t_newline;
            }

<LINE_COMMENT><<EOF>> {
                EOF_COLUMN_UPDATE;
                BEGIN(INITIAL);
            }

<LINE_COMMENT>{all_noline}* {
                LOG_TOKEN("comment");
                SAME_LINE_COLUMN_UPDATE;
            }

<NEW_LINE_COUNT>({space}|{tab})+{new_line} {
                yyless(yyleng - 1);  // strip the spaces and tabs before {new_line}
                totally_new_line = false;
                SAME_LINE_COLUMN_UPDATE;
            }

<NEW_LINE_COUNT>{new_line} {
                totally_new_line = true;
                NEWLINE_TOKEN_GEN;
                return t_newline;
            }

<NEW_LINE_COUNT>({space}|{tab})+[#] {  // only use in "# <comment>" after tabs or spaces
                yyless(yyleng - 1);  // strip the spaces and tabs before "#"
                totally_new_line = false;
                SAME_LINE_COLUMN_UPDATE;
            }

<NEW_LINE_COUNT>[#] {
                totally_new_line = false;
                LOG_TOKEN("comment start sharp");
                SAME_LINE_COLUMN_UPDATE;
                BEGIN(LINE_COMMENT);
            }

<NEW_LINE_COUNT>({space}|{tab})+ {
                totally_new_line = false;
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::indent;
                std::string temp(yytext);
                IDN.space_num = std::count(temp.begin(), temp.end(), ' ');
                IDN.tab_num = std::count(temp.begin(), temp.end(), '\t');

                if (!block_depth_init) {
                    block_depth_init = true;
                    if (IDN.space_num != 0 && IDN.tab_num != 0) {
                        LOG_TOKEN_DENT_ERROR("mix space and tab together", IDN.space_num, IDN.tab_num);
                        block_depth_init = false;  // reinit next time
                        IDN.absolute_depth = last_block_depth;
                    }
                    else if (IDN.space_num != 0 && IDN.tab_num == 0) {
                        block_depth_cell.to_space();
                        block_depth_cell.add(IDN.space_num);
                        IDN.absolute_depth = block_depth_cell.total_depth;
                    }
                    else if (IDN.space_num == 0 && IDN.tab_num != 0) {
                        block_depth_cell.to_tab();
                        block_depth_cell.add(IDN.tab_num);
                        IDN.absolute_depth = block_depth_cell.total_depth;
                    }
                    else {
                        assert(false && "[0] you cannot get here, unless your lex for t_indent is wrong!!!");
                    }
                } else {
                    if (IDN.space_num != 0 && IDN.tab_num != 0) {
                        LOG_TOKEN_DENT_ERROR("mix space and tab together", IDN.space_num, IDN.tab_num);
                        IDN.absolute_depth = block_depth_cell.total_depth;
                    }
                    else if (
                        (!block_depth_cell.use_tab && IDN.space_num != 0 && IDN.tab_num == 0) ||
                        (block_depth_cell.use_tab && IDN.space_num == 0 && IDN.tab_num != 0)
                    ) {
                        int num = block_depth_cell.use_tab ? IDN.tab_num : IDN.space_num;
                        if (num == block_depth_cell.total_num) {
                            IDN.absolute_depth = block_depth_cell.total_depth;
                        } else if (num > block_depth_cell.total_num) {
                            block_depth_cell.add(num - block_depth_cell.total_num);
                            IDN.absolute_depth = block_depth_cell.total_depth;
                        } else {
                            int res = block_depth_cell.get_absolute_depth(num);
                            if (res == -1) {
                                LOG_TOKEN_DENT_ERROR("unindent does not match any outer indentation level", IDN.space_num, IDN.tab_num);
                                IDN.absolute_depth = block_depth_cell.total_depth;
                            } else {
                                bool success = block_depth_cell.del(block_depth_cell.total_depth - res);
                                IDN.absolute_depth = block_depth_cell.total_depth;
                                if (!success) {
                                    assert(false && "[1] you cannot get here, unless your flex is wrong!!!");
                                }
                            }
                        }
                    }
                    else if (IDN.space_num == 0 && IDN.tab_num == 0) {
                        assert(false && "[2] you cannot get here, unless your flex is wrong!!!");
                    }
                    else {
                        // use_tab but space, or not use_tab but tab
                        LOG_TOKEN_DENT_ERROR("unindent does not match any outer indentation level", IDN.space_num, IDN.tab_num);
                        IDN.absolute_depth = block_depth_cell.total_depth;
                    }
                }

                IDN.relative_depth = tmp_dent = IDN.absolute_depth - last_block_depth;
                last_block_depth = IDN.absolute_depth;
                last_ptr = yylval.token_ptr;

                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN_DENT();
                SAME_LINE_COLUMN_UPDATE;

                if (tmp_dent == 0)
                    BEGIN(INITIAL);
                else if (tmp_dent > 0) {
                    BEGIN(PRODUCE_INDENT);
                } else {
                    tmp_dent = -tmp_dent;
                    BEGIN(PRODUCE_DEDENT);
                }
            }

<NEW_LINE_COUNT><<EOF>> {
                    EOF_COLUMN_UPDATE;
                    BEGIN(INITIAL);
                }

<NEW_LINE_COUNT>{all_noline} {
                yyless(0);

                if (totally_new_line) {
                    totally_new_line = false;
                    yylval.token_ptr = make_token();
                    yylval.token_ptr->type = token_type::indent;
                    IDN.space_num = 0;
                    IDN.tab_num = 0;
                    IDN.absolute_depth = 0;
                    IDN.relative_depth = tmp_dent = -last_block_depth;
                    last_block_depth = 0;
                    last_ptr = yylval.token_ptr;
                    block_depth_cell.clear();

                    SET_TOKEN_LINE_COLUMN;
                    LOG_TOKEN_DENT();
                    SAME_LINE_COLUMN_UPDATE;

                    if (tmp_dent == 0)
                        BEGIN(INITIAL);
                    else if (tmp_dent > 0) {
                        BEGIN(PRODUCE_INDENT);
                    } else {
                        tmp_dent = -tmp_dent;
                        BEGIN(PRODUCE_DEDENT);
                    }
                } else {
                    BEGIN(INITIAL);
                }
            }

<PRODUCE_INDENT><<EOF>> {
                yylval.token_ptr = last_ptr;
                LOG_TOKEN_INDENT();
                EOF_COLUMN_UPDATE;
                tmp_dent--;
                if (tmp_dent <= 0)
                    BEGIN(INITIAL);
                return t_indent;
            }

<PRODUCE_INDENT>{all} {
                yyless(0);
                
                yylval.token_ptr = last_ptr;
                LOG_TOKEN_INDENT();
                tmp_dent--;
                if (tmp_dent <= 0)
                    BEGIN(INITIAL);
                return t_indent;
            }

<PRODUCE_DEDENT><<EOF>> {
                yylval.token_ptr = last_ptr;
                LOG_TOKEN_DEDENT();
                EOF_COLUMN_UPDATE;
                tmp_dent--;
                if (tmp_dent <= 0)
                    BEGIN(INITIAL);
                return t_dedent;
            }

<PRODUCE_DEDENT>{all} {
                yyless(0);

                yylval.token_ptr = last_ptr;
                LOG_TOKEN_DEDENT();
                tmp_dent--;
                if (tmp_dent <= 0)
                    BEGIN(INITIAL);
                return t_dedent;
            }

<INITIAL><<EOF>> {
                if (no_eof_yet) {
                    no_eof_yet = false;
                    yylval.token_ptr = make_token();
                    yylval.token_ptr->type = token_type::indent;
                    IDN.space_num = 0;
                    IDN.tab_num = 0;
                    IDN.absolute_depth = 0;
                    IDN.relative_depth = tmp_dent = -last_block_depth;
                    last_block_depth = 0;
                    last_ptr = yylval.token_ptr;
                    block_depth_cell.clear();

                    SET_TOKEN_LINE_COLUMN;
                    LOG_TOKEN_DENT();
                    EOF_COLUMN_UPDATE;

                    if (tmp_dent == 0)
                        BEGIN(INITIAL);
                    else if (tmp_dent > 0) {
                        BEGIN(PRODUCE_INDENT);
                    } else {
                        tmp_dent = -tmp_dent;
                        BEGIN(PRODUCE_DEDENT);
                    }
                } else {
                    EOF_COLUMN_UPDATE;
                    return 0;
                }    
            }

{pure_dec_value}|{hex_value}|{oct_value}|{bin_value} {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::integer;
                yylval.token_ptr->content.data.int_num = translate_python_int(std::string(yytext));
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN_WITH_VALUE(
                    "integer (string)", yylval.token_ptr->content.data.int_num
                );
                SAME_LINE_COLUMN_UPDATE;
                return t_number;  // integer
            }

({float_value}|{dec_value})e(\+|-)?[0-9]+ {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::floats;
                yylval.token_ptr->content.data.double_num = std::stod(std::string(yytext));
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN_WITH_VALUE(
                    "float (string)", yylval.token_ptr->content.data.double_num
                );
                SAME_LINE_COLUMN_UPDATE;
                return t_number;  // floats
            }

{float_value} {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::floats;
                yylval.token_ptr->content.data.double_num = std::stod(std::string(yytext));
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN_WITH_VALUE(
                    "float (string)", yylval.token_ptr->content.data.double_num
                );
                SAME_LINE_COLUMN_UPDATE;
                return t_number;
            }

<SQUOTE_STR_TEXT>\\\' { yymore(); }
<SQUOTE_STR_TEXT>[^'\n\r]+ { yymore(); }

<SQUOTE_STR_TEXT_END>\' {
                BRACKET_TOKEN_GEN;
                BEGIN(INITIAL);
                return t_bracket_squotes;
            }

<SQUOTE_STR_TEXT_END><<EOF>> { assert(false && "[3] you cannot get here, unless your flex is wrong!!!"); }
<SQUOTE_STR_TEXT_END>{all} { assert(false && "[4] you cannot get here, unless your flex is wrong!!!"); }

<SQUOTE_STR_TEXT>\' {
                yyless(yyleng - 1);
                STRTEXT_TOKEN_GEN;
                BEGIN(SQUOTE_STR_TEXT_END);
                return t_strtext;
            }

<SQUOTE_STR_TEXT>{new_line} {
                yyless(yyleng - 1);
                LOG_TOKEN_ERROR("single quote does not close");
                BEGIN(INITIAL);
            }

<SQUOTE_STR_TEXT><<EOF>> {
                LOG_TOKEN_ERROR("single quote does not close");
                EOF_COLUMN_UPDATE;
                BEGIN(INITIAL);
            }

<DQUOTE_STR_TEXT>\\\" { yymore(); }
<DQUOTE_STR_TEXT>[^"\n\r]+ { yymore(); }

<DQUOTE_STR_TEXT_END>\" {
                BRACKET_TOKEN_GEN;
                BEGIN(INITIAL);
                return t_bracket_squotes;
            }

<DQUOTE_STR_TEXT_END><<EOF>> { assert(false && "[5] you cannot get here, unless your flex is wrong!!!"); }
<DQUOTE_STR_TEXT_END>{all} { assert(false && "[6] you cannot get here, unless your flex is wrong!!!"); }

<DQUOTE_STR_TEXT>\" {
                yyless(yyleng - 1);
                STRTEXT_TOKEN_GEN;
                BEGIN(DQUOTE_STR_TEXT_END);
                return t_strtext;
            }

<DQUOTE_STR_TEXT>{new_line} {
                yyless(yyleng - 1);
                LOG_TOKEN_ERROR("double quote does not close");
                BEGIN(INITIAL);
            }

<DQUOTE_STR_TEXT><<EOF>> {
                LOG_TOKEN_ERROR("double quote does not close");
                EOF_COLUMN_UPDATE;
                BEGIN(INITIAL);
            }

,           { DELIMITER_TOKEN_GEN; return t_delimiter_comma; }
:           { DELIMITER_TOKEN_GEN; return t_delimiter_colon; }
->          { DELIMITER_TOKEN_GEN; return t_delimiter_arrow; }
\;          { DELIMITER_TOKEN_GEN; return t_delimiter_semicolon; }
\.          { DELIMITER_TOKEN_GEN; return t_delimiter_dot; }
\.\.\.      { DELIMITER_TOKEN_GEN; return t_delimiter_3dot; }

\'          { BRACKET_TOKEN_GEN; BEGIN(SQUOTE_STR_TEXT); return t_bracket_squotes; }
\"          { BRACKET_TOKEN_GEN; BEGIN(DQUOTE_STR_TEXT); return t_bracket_dquotes; }
\(          { BRACKET_TOKEN_GEN; return t_bracket_parentheses_l; }
\)          { BRACKET_TOKEN_GEN; return t_bracket_parentheses_r; }
\[          { BRACKET_TOKEN_GEN; return t_bracket_square_l; }
\]          { BRACKET_TOKEN_GEN; return t_bracket_square_r; }
\{          { BRACKET_TOKEN_GEN; return t_bracket_curly_l; }
\}          { BRACKET_TOKEN_GEN; return t_bracket_curly_r; }

\+          { OPERATOR_TOKEN_GEN; return t_operators_add; }
-           { OPERATOR_TOKEN_GEN; return t_operators_sub; }
\*          { OPERATOR_TOKEN_GEN; return t_operators_mul; }
\/          { OPERATOR_TOKEN_GEN; return t_operators_div; }
\/\/        { OPERATOR_TOKEN_GEN; return t_operators_ediv; }
%           { OPERATOR_TOKEN_GEN; return t_operators_mod; }
\*\*        { OPERATOR_TOKEN_GEN; return t_operators_pow; }
@           { OPERATOR_TOKEN_GEN; return t_operators_at; }
&           { OPERATOR_TOKEN_GEN; return t_operators_and; }
\|          { OPERATOR_TOKEN_GEN; return t_operators_or; }
\^          { OPERATOR_TOKEN_GEN; return t_operators_xor; }
~           { OPERATOR_TOKEN_GEN; return t_operators_not; }
[<][<]      { OPERATOR_TOKEN_GEN; return t_operators_sleft; }
>>          { OPERATOR_TOKEN_GEN; return t_operators_sright; }
==          { OPERATOR_TOKEN_GEN; return t_operators_eq; }
!=          { OPERATOR_TOKEN_GEN; return t_operators_neq; }
[<]=        { OPERATOR_TOKEN_GEN; return t_operators_leq; }
>=          { OPERATOR_TOKEN_GEN; return t_operators_geq; }
[<]         { OPERATOR_TOKEN_GEN; return t_operators_lt; }
>           { OPERATOR_TOKEN_GEN; return t_operators_gt; }

=           { OPERATOR_TOKEN_GEN; return t_operators_assign; }
\+=         { OPERATOR_TOKEN_GEN; return t_operators_add_assign; }
-=          { OPERATOR_TOKEN_GEN; return t_operators_sub_assign; }
\*=         { OPERATOR_TOKEN_GEN; return t_operators_mul_assign; }
\/=         { OPERATOR_TOKEN_GEN; return t_operators_div_assign; }
\/\/=       { OPERATOR_TOKEN_GEN; return t_operators_ediv_assign; }
%=          { OPERATOR_TOKEN_GEN; return t_operators_mod_assign; }
\*\*=       { OPERATOR_TOKEN_GEN; return t_operators_pow_assign; }
@=          { OPERATOR_TOKEN_GEN; return t_operators_at_assign; }
&=          { OPERATOR_TOKEN_GEN; return t_operators_and_assign; }
\|=         { OPERATOR_TOKEN_GEN; return t_operators_or_assign; }
\^=         { OPERATOR_TOKEN_GEN; return t_operators_xor_assign; }
~=          { OPERATOR_TOKEN_GEN; return t_operators_not_assign; }
[<][<]=     { OPERATOR_TOKEN_GEN; return t_operators_sleft_assign; }
>>=         { OPERATOR_TOKEN_GEN; return t_operators_sright_assign; }

_           { KEYWORD_TOKEN_GEN; return t_keyword_underline; }
None        { KEYWORD_TOKEN_GEN; return t_keyword_None; }
True        { KEYWORD_TOKEN_GEN; return t_keyword_True; }
False       { KEYWORD_TOKEN_GEN; return t_keyword_False; }

and         { KEYWORD_TOKEN_GEN; return t_keyword_and; }
or          { KEYWORD_TOKEN_GEN; return t_keyword_or; }
not         { KEYWORD_TOKEN_GEN; return t_keyword_not; }
is          { KEYWORD_TOKEN_GEN; return t_keyword_is; }
in          { KEYWORD_TOKEN_GEN; return t_keyword_in; }

pass        { KEYWORD_TOKEN_GEN; return t_keyword_pass; }

def         { KEYWORD_TOKEN_GEN; return t_keyword_def; }
return      { KEYWORD_TOKEN_GEN; return t_keyword_return; }
yield       { KEYWORD_TOKEN_GEN; return t_keyword_yield; }
class       { KEYWORD_TOKEN_GEN; return t_keyword_class; }
lambda      { KEYWORD_TOKEN_GEN; return t_keyword_lambda; }
await       { KEYWORD_TOKEN_GEN; return t_keyword_await; }

if          { KEYWORD_TOKEN_GEN; return t_keyword_if; }
else        { KEYWORD_TOKEN_GEN; return t_keyword_else; }
elif        { KEYWORD_TOKEN_GEN; return t_keyword_elif; }
for         { KEYWORD_TOKEN_GEN; return t_keyword_for; }
break       { KEYWORD_TOKEN_GEN; return t_keyword_break; }
continue    { KEYWORD_TOKEN_GEN; return t_keyword_continue; }
match       { KEYWORD_TOKEN_GEN; return t_keyword_match; }
case        { KEYWORD_TOKEN_GEN; return t_keyword_case; }

global      { KEYWORD_TOKEN_GEN; return t_keyword_global; }
nonlocal    { KEYWORD_TOKEN_GEN; return t_keyword_nonlocal; }
del         { KEYWORD_TOKEN_GEN; return t_keyword_del; }

import      { KEYWORD_TOKEN_GEN; return t_keyword_import; }
from        { KEYWORD_TOKEN_GEN; return t_keyword_from; }
as          { KEYWORD_TOKEN_GEN; return t_keyword_as; }

raise       { KEYWORD_TOKEN_GEN; return t_keyword_raise; }
try         { KEYWORD_TOKEN_GEN; return t_keyword_try; }
except      { KEYWORD_TOKEN_GEN; return t_keyword_except; }
finally     { KEYWORD_TOKEN_GEN; return t_keyword_finally; }

assert      { KEYWORD_TOKEN_GEN; return t_keyword_assert; }

tastror_out { KEYWORD_TOKEN_GEN; return t_keyword_tastror_out; }

{letter}+({digit}|{letter})* {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::identifier;
                yylval.token_ptr->content.name = std::string(yytext);
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN("identifier");
                SAME_LINE_COLUMN_UPDATE;
                return t_identifier;
            }

{all_noline}|{wrong_dec_value}|{wrong_id} {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::error;
                yylval.token_ptr->content.message = "invalid string '" + std::string(yytext) + "'";
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN_ERROR("invalid string");
                SAME_LINE_COLUMN_UPDATE;
                return t_error;
            }

%%
