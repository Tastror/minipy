%{
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <algorithm>

#include "compiler_bison.h"
#include "../src/log.h"
#include "../src/lexer.h"

#define YY_USER_INIT { BEGIN(NEW_LINE_COUNT); }

int yycolumnno = 1;
size_t last_string_length;
std::string last_string;

std::stringstream debug_ss;

#define SAME_LINE_COLUMN_UPDATE \
    do { last_string = std::string(yytext); last_string_length = last_string.size(); yycolumnno += last_string.size(); } while(0)
#define NEW_LINE_COLUMN_UPDATE \
    do { last_string = std::string("\n"); last_string_length = 1; yycolumnno = 1; } while(0)
#define EOF_COLUMN_UPDATE \
    do { last_string = std::string(); last_string_length = 0; } while(0)

#define LOG_TOKEN(type_string) do { \
    Logger << Log::info \
        << "line " << yylineno << ", column " << yycolumnno \
        << ": " << type_string << ": " << yytext << Log::endl; \
} while(0)

#define SET_TOKEN_LINE_COLUMN do { \
    yylval.token_ptr->lineno = yylineno; \
    yylval.token_ptr->columnno = yycolumnno; \
} while(0)

#define OPERATOR_TOKEN_GEN do { \
    yylval.token_ptr = make_token(); \
    yylval.token_ptr->type = token_type::operators; \
    yylval.token_ptr->content.name = std::string(yytext); \
    SET_TOKEN_LINE_COLUMN; \
    LOG_TOKEN("operator"); \
    SAME_LINE_COLUMN_UPDATE; \
} while(0)

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

\+          { OPERATOR_TOKEN_GEN; return t_operators_add; }
-           { OPERATOR_TOKEN_GEN; return t_operators_sub; }
\*          { OPERATOR_TOKEN_GEN; return t_operators_mul; }
\/          { OPERATOR_TOKEN_GEN; return t_operators_div; }
%           { OPERATOR_TOKEN_GEN; return t_operators_mod; }
=           { OPERATOR_TOKEN_GEN; return t_operators_assign; }

def         {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::keyword;
                yylval.token_ptr->content.name = std::string(yytext);
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN("identifier");
                SAME_LINE_COLUMN_UPDATE;
                return t_keyword_def;
            }

{pure_dec_value}|{hex_value}|{oct_value}|{bin_value} {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::integer;
                yylval.token_ptr->content.data.int_num = translate_python_int(std::string(yytext));
                SET_TOKEN_LINE_COLUMN;
                Logger << Log::info
                    << "line " << yylineno << ", column " << yycolumnno
                    << ": integer (string): " << yytext
                    << ", value = " << yylval.token_ptr->content.data.int_num << Log::endl;
                SAME_LINE_COLUMN_UPDATE;
                return t_integer;
            }

({float_value}|{dec_value})e(\+|-)?[0-9]+ {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::floats;
                yylval.token_ptr->content.data.double_num = std::stod(std::string(yytext));
                SET_TOKEN_LINE_COLUMN;
                Logger << Log::info
                    << "line " << yylineno << ", column " << yycolumnno
                    << ": float (string): " << yytext
                    << ", value = " << yylval.token_ptr->content.data.double_num << Log::endl;
                SAME_LINE_COLUMN_UPDATE;
                return t_floats;
            }

{float_value} {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::floats;
                yylval.token_ptr->content.data.double_num = std::stod(std::string(yytext));
                SET_TOKEN_LINE_COLUMN;
                Logger << Log::info
                    << "line " << yylineno << ", column " << yycolumnno
                    << ": float (string): " << yytext
                    << ", value = " << yylval.token_ptr->content.data.double_num << Log::endl;
                SAME_LINE_COLUMN_UPDATE;
                return t_floats;
            }

{letter}+({digit}|{letter})* {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::identifier;
                yylval.token_ptr->content.name = std::string(yytext);
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN("identifier");
                SAME_LINE_COLUMN_UPDATE;
                return t_identifier;
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
                Logger << Log::warning
                    << "line " << yylineno << ", column " << yycolumnno
                    << ": tab/space after a new line: "
                    << yylval.token_ptr->content.indent_num.space_num << " space(s) and "
                    << yylval.token_ptr->content.indent_num.tab_num << " tab(s)" << Log::endl;
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

.|{wrong_dec_value}|{wrong_id} {
                yylval.token_ptr = make_token();
                yylval.token_ptr->type = token_type::error;
                yylval.token_ptr->content.message = "invalid string '" + std::string(yytext) + "'";
                SET_TOKEN_LINE_COLUMN;
                LOG_TOKEN("invalid string");
                SAME_LINE_COLUMN_UPDATE;
                return t_error;
            }

%%
