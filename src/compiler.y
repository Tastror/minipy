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

struct s_t {
    std::shared_ptr<Token> token_ptr;
    std::shared_ptr<AstNode> astnode_ptr;
    s_t() {
        token_ptr = nullptr;
        astnode_ptr = nullptr;
    };
    ~s_t() {};
    s_t& operator=(const s_t& other) {
        this->token_ptr = other.token_ptr;
        this->astnode_ptr = other.astnode_ptr;
        return *this;
    }
};

typedef s_t YYSTYPE;

#define yyoverflow

}

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
%token <token_ptr> t_delimiter
%token <token_ptr> t_keyword
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
        | t_operators_sub
            {
                Logger << Log::info << "t_operators_minus" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_mul
            {
                Logger << Log::info << "t_operators_multiply" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_div
            {
                Logger << Log::info << "t_operators_divide" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_mod
            {
                Logger << Log::info << "t_operators_mod" << Log::endl;
                $$ = make_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_assign
            {
                Logger << Log::info << "t_operators_assign" << Log::endl;
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