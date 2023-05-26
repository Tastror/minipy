%{
#include <string>
#include <memory>

#include "compiler_flex.h"
#include "../src/Log.h"
#include "../src/lexer.h"
#include "../src/parser.h"

void yyerror(char * msg);

std::shared_ptr<AstNode> astnode_root;

%}

%code requires {
#include <memory>
#include "../src/lexer.h"
#include "../src/parser.h"
}

%union u_t {
    Token token;
    std::shared_ptr<AstNode> astnode;
    u_t() {};
    ~u_t() {};
    u_t& operator=(const u_t& other) { this->astnode = other.astnode; return *this; }
};

%start file

%token <token> t_error
%token <token> t_identifier
%token <token> t_integer
%token <token> t_floats
%token <token> t_operators_add
%token <token> t_operators_minus
%token <token> t_delimiter
%token <token> t_keyword
%token <token> t_indent
%token <token> t_newline

%type <astnode> ast_error
%type <astnode> statement
// %type <astnode> simple_stmt
// %type <astnode> compound_stmt
// %type <astnode> assignment
// %type <astnode> block

%%

file : statement
            {
                astnode_root = $1;
            }

statement : statement ast_error
            {
                $2->parent = $1;
                $1->sons.push_back($2);
                $$ = $1;
            }
        | ast_error


ast_error : t_error
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_identifier
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_integer
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_floats
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_add
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_minus
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_delimiter
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_keyword
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_indent
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_newline
            {
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }

%%

void yyerror(char * msg)
{
    Logger << Log::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << Log::endl;
}