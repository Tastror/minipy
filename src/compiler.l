%{
#include <string>
#include <algorithm>

#include "compiler_bison.h"
#include "../src/Log.h"
#include "../src/lexer.h"

#define YY_USER_INIT BEGIN(NEW_LINE_COUNT);

int yycolumnno;
size_t last_string_length;
std::string last_string;

#define SAME_LINE_COLUMN_UPDATE \
    { last_string = std::string(yytext); last_string_length = last_string.size(); yycolumnno += last_string.size(); }
#define NEW_LINE_COLUMN_UPDATE \
    { last_string = std::string("\n"); last_string_length = 1; yycolumnno = 1; }
#define EOF_COLUMN_UPDATE \
    { last_string = std::string(); last_string_length = 0; }

%}

%option warn noyywrap yylineno case-sensitive pointer

%x LINE_COMMENT
%x NEW_LINE_COUNT

digit       [0-9]
letter      [_a-zA-Z]
white       [ \t]
space       [ ]
tab         \t
new_line    (\r\n|\n)

dec_value   [0-9]+
pure_dec_value ([1-9][0-9]+|0)
hex_value   0x[0-9a-fA-F]+
oct_value   0o[0-7]+
bin_value   0b[01]+
float_value ([0-9]*\.[0-9]+|[0-9]+\.)

%%

"#"         {
                SAME_LINE_COLUMN_UPDATE;
                BEGIN(LINE_COMMENT);
            }

<LINE_COMMENT>{new_line} {
                NEW_LINE_COLUMN_UPDATE;
                BEGIN(INITIAL);
                return t_newline;
            }

<LINE_COMMENT>.* {
                SAME_LINE_COLUMN_UPDATE;
            }

{pure_dec_value}|{hex_value}|{oct_value}|{bin_value} {
                yylval.token.type = token_type::integer;
                yylval.token.content.data.int_num = translate_python_int(std::string(yytext));
                yylval.token.lineno = yylineno;
                yylval.token.columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_integer;
            }

({float_value}|{dec_value})e(\+|-)?[0-9]+ {
                yylval.token.type = token_type::floats;
                yylval.token.content.data.double_num = std::stod(std::string(yytext));
                yylval.token.lineno = yylineno;
                yylval.token.columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_floats;
            }

{float_value} {
                yylval.token.type = token_type::floats;
                yylval.token.content.data.double_num = std::stod(std::string(yytext));
                yylval.token.lineno = yylineno;
                yylval.token.columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_floats;
            }

{letter}+({digit}|{letter})* {
                yylval.token.type = token_type::identifier;
                yylval.token.content.name = std::string(yytext);
                yylval.token.lineno = yylineno;
                yylval.token.columnno = yycolumnno;
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
                yylval.token.type = token_type::indent;
                std::string temp(yytext);
                yylval.token.content.indent_num.space_num = std::count(temp.begin(), temp.end(), ' ');
                yylval.token.content.indent_num.tab_num = std::count(temp.begin(), temp.end(), '\t');
                yylval.token.lineno = yylineno;
                yylval.token.columnno = yycolumnno;
                NEW_LINE_COLUMN_UPDATE;
                BEGIN(INITIAL);
                return t_indent;
            }

[\S]*       {
                Logger << Log::error
                    << "line " << yylineno << ", column " << yycolumnno
                    << ": invalid string '" << yytext << "'"
                    << Log::endl;
                yylval.token.type = token_type::error;
                yylval.token.content.message = "invalid string '" + std::string(yytext) + "'";
                yylval.token.lineno = yylineno;
                yylval.token.columnno = yycolumnno;
                SAME_LINE_COLUMN_UPDATE;
                return t_error;
            }

%%
