%{
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <algorithm>

#include "compiler_bison.h"
#include "../src/log.h"
#include "../src/lexer.h"

int yycolumnno = 1;
size_t last_string_length;
std::string last_string;

std::stringstream debug_ss;



#define YY_USER_INIT { BEGIN(NEW_LINE_COUNT); }



#define SAME_LINE_COLUMN_UPDATE \
    do { last_string = std::string(yytext); last_string_length = last_string.size(); yycolumnno += last_string.size(); } while(0)

#define NEW_LINE_COLUMN_UPDATE \
    do { last_string = std::string("\n"); last_string_length = 1; yycolumnno = 1; } while(0)

#define EOF_COLUMN_UPDATE \
    do { last_string = std::string(); last_string_length = 0; } while(0)

#define SET_TOKEN_LINE_COLUMN do { \
    yylval.token_ptr->lineno = yylineno; \
    yylval.token_ptr->columnno = yycolumnno; \
} while(0)



#define LOG_TOKEN_ERROR(type_string) do { \
    Logger << Log::error \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": " << type_string << ": " << yytext << Log::endl; \
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

#define LOG_TOKEN_SPACE() do { \
    Logger << Log::info \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": tab/space after a new line: " \
        << yylval.token_ptr->content.indent_num.space_num << " space(s) and " \
        << yylval.token_ptr->content.indent_num.tab_num << " tab(s)" << Log::endl; \
} while(0)



#define GENERAL_TOKEN_GEN(a, b) do { \
    yylval.token_ptr = make_token(); \
    yylval.token_ptr->type = a; \
    yylval.token_ptr->content.name = std::string(yytext); \
    SET_TOKEN_LINE_COLUMN; \
    LOG_TOKEN(b); \
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
%}

%option warn nodefault noyywrap yylineno case-sensitive pointer

%x LINE_COMMENT
%x NEW_LINE_COUNT

digit       [0-9]
letter      [_a-zA-Z]
white       [ \t]
space       [ ]
tab         \t
new_line    (\r\n|\n)

dec_value   [0-9]+
pure_dec_value ([1-9][0-9]+|[0-9]|0+)
wrong_dec_value (0+[1-9]+[0-9]*)
wrong_id    ([0-9]+[_a-zA-Z]+([_a-zA-Z]|[0-9])*)
hex_value   0x[0-9a-fA-F]+
oct_value   0o[0-7]+
bin_value   0b[01]+
float_value ([0-9]*\.[0-9]+|[0-9]+\.)

%%

"#"         {
                LOG_TOKEN("comment start sharp");
                SAME_LINE_COLUMN_UPDATE;
                BEGIN(LINE_COMMENT);
            }

<LINE_COMMENT>{new_line} {
                NEW_LINE_COLUMN_UPDATE;
                BEGIN(NEW_LINE_COUNT);
                return t_newline;
            }

<LINE_COMMENT>.* {
                LOG_TOKEN("comment");
                SAME_LINE_COLUMN_UPDATE;
            }

{white}+    { SAME_LINE_COLUMN_UPDATE; }

{new_line}  {
                NEW_LINE_COLUMN_UPDATE;
                BEGIN(NEW_LINE_COUNT);
                return t_newline;
            }

<NEW_LINE_COUNT>({space}|{tab})+ {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::indent;
                std::string temp(yytext);
                yylval.token_ptr->content.indent_num.space_num = std::count(temp.begin(), temp.end(), ' ');
                yylval.token_ptr->content.indent_num.tab_num = std::count(temp.begin(), temp.end(), '\t');
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN_SPACE();
                SAME_LINE_COLUMN_UPDATE;
                BEGIN(INITIAL);
                return t_indent;
            }

<NEW_LINE_COUNT>{new_line} {
                NEW_LINE_COLUMN_UPDATE;
                return t_newline;
            }

<NEW_LINE_COUNT>. {
                BEGIN(INITIAL);
                yyless(0);
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
                return t_integer;
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
                return t_floats;
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
                return t_floats;
            }

_           { DELIMITER_TOKEN_GEN; return t_underline; }

,           { DELIMITER_TOKEN_GEN; return t_delimiter_comma; }
:           { DELIMITER_TOKEN_GEN; return t_delimiter_colon; }
->          { DELIMITER_TOKEN_GEN; return t_delimiter_arrow; }
\;          { DELIMITER_TOKEN_GEN; return t_delimiter_comma; }
\.          { DELIMITER_TOKEN_GEN; return t_delimiter_dot; }

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

\"          { BRACKET_TOKEN_GEN; return t_bracket_squotes; }
\'          { BRACKET_TOKEN_GEN; return t_bracket_dquotes; }
\(          { BRACKET_TOKEN_GEN; return t_bracket_parentheses_l; }
\)          { BRACKET_TOKEN_GEN; return t_bracket_parentheses_r; }
\[          { BRACKET_TOKEN_GEN; return t_bracket_square_l; }
\]          { BRACKET_TOKEN_GEN; return t_bracket_square_r; }
\{          { BRACKET_TOKEN_GEN; return t_bracket_curly_l; }
\}          { BRACKET_TOKEN_GEN; return t_bracket_curly_r; }

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

.|{wrong_dec_value}|{wrong_id} {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::error;
                yylval.token_ptr->content.message = "invalid string '" + std::string(yytext) + "'";
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN_ERROR("invalid string");
                SAME_LINE_COLUMN_UPDATE;
                return t_error;
            }

%%
