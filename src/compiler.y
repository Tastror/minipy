%{
#include <string>
#include <memory>

#include "compiler_flex.h"
#include "../src/common.h"
#include "../src/log.h"
#include "../src/lexer.h"
#include "../src/parser.h"

void yyerror(AstNode*& ast_head, char* msg);
%}

%code requires {
#include <memory>
#include "../src/common.h"
#include "../src/lexer.h"
#include "../src/parser.h"

union s_t {
    Token* token_ptr;
    AstNode* astnode_ptr;
};

typedef s_t YYSTYPE;

#define yyoverflow

}

%parse-param {AstNode*& ast_head}

%start file

%token <token_ptr> t_error

%token <token_ptr> t_identifier

%token <token_ptr> t_integer
%token <token_ptr> t_floats

%token <token_ptr> t_operators_add
%token <token_ptr> t_operators_sub
%token <token_ptr> t_operators_mul
%token <token_ptr> t_operators_div
%token <token_ptr> t_operators_mod
%token <token_ptr> t_operators_assign

%token <token_ptr> t_keyword_def

%token <token_ptr> t_delimiter
%token <token_ptr> t_indent
%token <token_ptr> t_newline

%type <astnode_ptr> ast_error
%type <astnode_ptr> statement
// %type <astnode_ptr> simple_stmt
// %type <astnode_ptr> compound_stmt
// %type <astnode_ptr> assignment
// %type <astnode_ptr> block

%%

file : statement
            {
                ast_head = $1;
                ast_head->type = astnode_type::file;
            }

statement : statement ast_error
            {
                $$ = $1->eat($2);
                $$->type = astnode_type::statement;
            }
        | ast_error
            {
                $$ = $1;
                $$->type = astnode_type::statement;
            }


ast_error : t_error
            {
                Logger << Log::info << "t_error" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_identifier
            {
                Logger << Log::info << "t_identifier" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_integer
            {
                Logger << Log::info << "t_integer" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_floats
            {
                Logger << Log::info << "t_floats" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_add
            {
                Logger << Log::info << "t_operators_add" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_sub
            {
                Logger << Log::info << "t_operators_minus" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_mul
            {
                Logger << Log::info << "t_operators_multiply" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_div
            {
                Logger << Log::info << "t_operators_divide" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_mod
            {
                Logger << Log::info << "t_operators_mod" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_assign
            {
                Logger << Log::info << "t_operators_assign" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_keyword_def
            {
                Logger << Log::info << "t_keyword_def" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_delimiter
            {
                Logger << Log::info << "t_delimiter" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_indent
            {
                Logger << Log::info << "t_indent" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_newline
            {
                Logger << Log::info << "t_newline" << Log::endl;
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }

%%

void yyerror(AstNode*& ast_head, char* msg)
{
    Logger << Log::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << Log::endl;
}