%{
#include <string>
#include <memory>

#include "compiler_flex.h"
#include "../src/common.h"
#include "../src/log.h"
#include "../src/lexer.h"
#include "../src/parser.h"

void yyerror(AstNode*& ast_head, char* msg);

bool block_depth_init = false;
bool use_tab = false;
int block_depth_cell = 0;
int now_block_depth = 0;

%}

%code requires {
#include <memory>
#include "../src/log.h"
#include "../src/common.h"
#include "../src/lexer.h"
#include "../src/parser.h"

union s_t {
    Token* token_ptr;
    AstNode* astnode_ptr;
};

typedef s_t YYSTYPE;

#define yyoverflow

#define LOG_ASTNODE(type_string) \
    do { Logger << Log::info << "astnode: " << type_string << Log::endl; } while(0)

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
                LOG_ASTNODE("t_error");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_identifier
            {
                LOG_ASTNODE("t_identifier");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_integer
            {
                LOG_ASTNODE("t_integer");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_floats
            {
                LOG_ASTNODE("t_floats");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_add
            {
                LOG_ASTNODE("t_operators_add");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_sub
            {
                LOG_ASTNODE("t_operators_minus");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_mul
            {
                LOG_ASTNODE("t_operators_multiply");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_div
            {
                LOG_ASTNODE("t_operators_divide");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_mod
            {
                LOG_ASTNODE("t_operators_mod");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_operators_assign
            {
                LOG_ASTNODE("t_operators_assign");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_keyword_def
            {
                LOG_ASTNODE("t_keyword_def");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_delimiter
            {
                LOG_ASTNODE("t_delimiter");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_indent
            {
                LOG_ASTNODE("t_indent");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;

                if (!block_depth_init) {
                    block_depth_init = true;
                    if (
                        $$->token_leaf.content.indent_num.space_num != 0 &&
                        $$->token_leaf.content.indent_num.tab_num != 0
                    ) {
                        yyerror(ast_head, "mix space and tab together");
                        use_tab = false;
                        block_depth_cell = 4;
                    } else if (
                        $$->token_leaf.content.indent_num.space_num != 0 &&
                        $$->token_leaf.content.indent_num.tab_num == 0
                    ) {
                        use_tab = false;
                        block_depth_cell = $$->token_leaf.content.indent_num.space_num;
                    } else if (
                        $$->token_leaf.content.indent_num.space_num == 0 &&
                        $$->token_leaf.content.indent_num.tab_num != 0
                    ) {
                        use_tab = true;
                        block_depth_cell = $$->token_leaf.content.indent_num.tab_num;
                    }
                } else {
                    if (
                        $$->token_leaf.content.indent_num.space_num != 0 &&
                        $$->token_leaf.content.indent_num.tab_num != 0
                    ) {
                        yyerror(ast_head, "mix space and tab together");
                    } else if (
                        !use_tab &&
                        $$->token_leaf.content.indent_num.space_num != 0 &&
                        $$->token_leaf.content.indent_num.tab_num == 0 &&
                        $$->token_leaf.content.indent_num.space_num % block_depth_cell == 0
                    ) {
                        now_block_depth =
                            $$->token_leaf.content.indent_num.space_num /
                            block_depth_cell;
                    } else if (
                        use_tab &&
                        $$->token_leaf.content.indent_num.space_num == 0 &&
                        $$->token_leaf.content.indent_num.tab_num != 0 &&
                        $$->token_leaf.content.indent_num.tab_num % block_depth_cell == 0
                    ) {
                        now_block_depth =
                            $$->token_leaf.content.indent_num.tab_num /
                            block_depth_cell;
                    } else {
                        yyerror(ast_head, "unindent does not match any outer indentation level");
                    }
                }
            }
        | t_newline
            {
                LOG_ASTNODE("t_newline");
                now_block_depth = 0;
            }

%%

void yyerror(AstNode*& ast_head, char* msg)
{
    Logger << Log::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << Log::endl;
}