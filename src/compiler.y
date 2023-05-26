%{
#include <string>
#include <memory>

#include "compiler_flex.h"
#include "../src/common.h"
#include "../src/log.h"
#include "../src/lexer.h"
#include "../src/parser.h"

void yyerror(char * msg);

std::shared_ptr<AstNode> astnode_root;

%}

%code requires {
#include <memory>
#include "../src/common.h"
#include "../src/lexer.h"
#include "../src/parser.h"
}

%union u_t {
    struct s_t {
        std::shared_ptr<Token> token_ptr;
        std::shared_ptr<AstNode> astnode_ptr;
        s_t() {};
        ~s_t() {};
        s_t& operator=(const s_t& other) {
            this->token_ptr = other.token_ptr;
            this->astnode_ptr = other.astnode_ptr;
            return *this;
        }
    } data;
    u_t() {};
    ~u_t() {};
    u_t& operator=(const u_t& other) {
        this->data.token_ptr = other.data.token_ptr;
        this->data.astnode_ptr = other.data.astnode_ptr;
        return *this;
    }
};

%start file

%token <data.token_ptr> t_error
%token <data.token_ptr> t_identifier
%token <data.token_ptr> t_integer
%token <data.token_ptr> t_floats
%token <data.token_ptr> t_operators_add
%token <data.token_ptr> t_operators_minus
%token <data.token_ptr> t_delimiter
%token <data.token_ptr> t_keyword
%token <data.token_ptr> t_indent
%token <data.token_ptr> t_newline

%type <data.astnode_ptr> ast_error
%type <data.astnode_ptr> statement
// %type <data.astnode_ptr> simple_stmt
// %type <data.astnode_ptr> compound_stmt
// %type <data.astnode_ptr> assignment
// %type <data.astnode_ptr> block

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
                Logger << Log::info << "t_error" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_identifier
            {
                Logger << Log::info << "t_identifier" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_integer
            {
                Logger << Log::info << "t_integer" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_floats
            {
                Logger << Log::info << "t_floats" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_add
            {
                Logger << Log::info << "t_operators_add" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_minus
            {
                Logger << Log::info << "t_operators_minus" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_delimiter
            {
                Logger << Log::info << "t_delimiter" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_keyword
            {
                Logger << Log::info << "t_keyword" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_indent
            {
                Logger << Log::info << "t_indent" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_newline
            {
                Logger << Log::info << "t_newline" << Log::endl;
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