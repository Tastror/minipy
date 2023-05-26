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
    { last_string = std::string(yytext); last_string_length = last_string.size(); yycolumnno += last_string.size(); }
#define NEW_LINE_COLUMN_UPDATE \
    { last_string = std::string("\n"); last_string_length = 1; yycolumnno = 1; }
#define EOF_COLUMN_UPDATE \
    { last_string = std::string(); last_string_length = 0; }

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
pure_dec_value ([1-9][0-9]+|[0-9])
hex_value   0x[0-9a-fA-F]+
oct_value   0o[0-7]+
bin_value   0b[01]+
float_value ([0-9]*\.[0-9]+|[0-9]+\.)

%%

"#"         {
                Logger << Log::info << yylineno << ", " << yycolumnno << ": now commet: " << yytext << Log::endl;
                SAME_LINE_COLUMN_UPDATE;
                BEGIN(LINE_COMMENT);
            }

<LINE_COMMENT>{new_line} {
                NEW_LINE_COLUMN_UPDATE;
                BEGIN(INITIAL);
                return t_newline;
            }

<LINE_COMMENT>.* {
                Logger << Log::info << yylineno << ", " << yycolumnno << ": now comment: " << yytext << Log::endl;
                SAME_LINE_COLUMN_UPDATE;
                Logger << yylval.token_ptr << Log::endl;
            }

\+          {
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::operators;
                yylval.token_ptr->content.name = std::string(yytext);
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_operators_add;
            }

-           {
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::operators;
                yylval.token_ptr->content.name = std::string(yytext);
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_operators_sub;
            }

{pure_dec_value}|{hex_value}|{oct_value}|{bin_value} {
                Logger << Log::info << yylineno << ", " << yycolumnno << ": now integer: " << translate_python_int(std::string(yytext)) << Log::endl;
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::integer;
                yylval.token_ptr->content.data.int_num = translate_python_int(std::string(yytext));
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_integer;
            }

({float_value}|{dec_value})e(\+|-)?[0-9]+ {
                Logger << Log::info << yylineno << ", " << yycolumnno << ": now float: " << std::stod(std::string(yytext)) << Log::endl;
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::floats;
                yylval.token_ptr->content.data.double_num = std::stod(std::string(yytext));
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_floats;
            }

{float_value} {
                Logger << Log::info << yylineno << ", " << yycolumnno << ": now float: " << std::stod(std::string(yytext)) << Log::endl;
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::floats;
                yylval.token_ptr->content.data.double_num = std::stod(std::string(yytext));
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_floats;
            }

{letter}+({digit}|{letter})* {
                Logger << Log::info << yylineno << ", " << yycolumnno << ": now identifier: " << yytext << Log::endl;
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::identifier;
                yylval.token_ptr->content.name = std::string(yytext);
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
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
                Logger << Log::info << yylineno << ", " << yycolumnno << ": now tab/space after a new line" << Log::endl;
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::indent;
                std::string temp(yytext);
                yylval.token_ptr->content.indent_num.space_num = std::count(temp.begin(), temp.end(), ' ');
                yylval.token_ptr->content.indent_num.tab_num = std::count(temp.begin(), temp.end(), '\t');
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
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

.               {
                Logger << Log::error
                    << "line " << yylineno << ", column " << yycolumnno
                    << ": invalid string '" << yytext << "'"
                    << Log::endl;
                yylval.token_ptr = std::make_unique<Token>();
                yylval.token_ptr->type = token_type::error;
                yylval.token_ptr->content.message = "invalid string '" + std::string(yytext) + "'";
                yylval.token_ptr->lineno = yylineno;
                yylval.token_ptr->columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_error;
            }

%%
