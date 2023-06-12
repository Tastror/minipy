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

// #define yyoverflow

#define LOG_ASTNODE(type_string) \
    do { Logger << Log::info << "astnode: " << type_string << Log::endl; } while(0)
}

%union {
    Token* token_ptr;
    AstNode* astnode_ptr;
};

%parse-param {AstNode*& ast_head}



%token <token_ptr> t_error

%token <token_ptr> t_indent
%token <token_ptr> t_newline

%token <token_ptr> t_identifier
%token <token_ptr> t_integer
%token <token_ptr> t_floats
%token <token_ptr> t_raw_text  // just for str

%token <token_ptr> t_underline  // _

%token <token_ptr> t_delimiter_comma        // ,
%token <token_ptr> t_delimiter_colon        // :
%token <token_ptr> t_delimiter_arrow        // ->
%token <token_ptr> t_delimiter_semicolon    // ;
%token <token_ptr> t_delimiter_dot          // .

%token <token_ptr> t_operators_add      // +
%token <token_ptr> t_operators_sub      // -
%token <token_ptr> t_operators_mul      // *
%token <token_ptr> t_operators_div      // /
%token <token_ptr> t_operators_ediv     // //
%token <token_ptr> t_operators_mod      // %
%token <token_ptr> t_operators_pow      // **
%token <token_ptr> t_operators_at       // @
%token <token_ptr> t_operators_and      // &
%token <token_ptr> t_operators_or       // |
%token <token_ptr> t_operators_xor      // ^
%token <token_ptr> t_operators_not      // ~
%token <token_ptr> t_operators_sleft    // <<
%token <token_ptr> t_operators_sright   // >>
%token <token_ptr> t_operators_eq       // ==
%token <token_ptr> t_operators_neq      // !=
%token <token_ptr> t_operators_leq      // <=
%token <token_ptr> t_operators_geq      // >=
%token <token_ptr> t_operators_lt       // <
%token <token_ptr> t_operators_gt       // >

%token <token_ptr> t_operators_assign       // =
%token <token_ptr> t_operators_add_assign   // +=
%token <token_ptr> t_operators_sub_assign   // -=
%token <token_ptr> t_operators_mul_assign   // *=
%token <token_ptr> t_operators_div_assign   // /=
%token <token_ptr> t_operators_ediv_assign  // //=
%token <token_ptr> t_operators_mod_assign   // %=
%token <token_ptr> t_operators_pow_assign   // **=
%token <token_ptr> t_operators_at_assign    // @=
%token <token_ptr> t_operators_and_assign   // &=
%token <token_ptr> t_operators_or_assign    // |=
%token <token_ptr> t_operators_xor_assign   // ^=
%token <token_ptr> t_operators_not_assign   // ~=
%token <token_ptr> t_operators_sleft_assign     // <<=
%token <token_ptr> t_operators_sright_assign    // >>=

%token <token_ptr> t_bracket_squotes
%token <token_ptr> t_bracket_dquotes
%token <token_ptr> t_bracket_parentheses_l
%token <token_ptr> t_bracket_parentheses_r
%token <token_ptr> t_bracket_square_l
%token <token_ptr> t_bracket_square_r
%token <token_ptr> t_bracket_curly_l
%token <token_ptr> t_bracket_curly_r

%token <token_ptr> t_keyword_None
%token <token_ptr> t_keyword_True
%token <token_ptr> t_keyword_False

%token <token_ptr> t_keyword_and
%token <token_ptr> t_keyword_or
%token <token_ptr> t_keyword_not
%token <token_ptr> t_keyword_is
%token <token_ptr> t_keyword_in

%token <token_ptr> t_keyword_pass

%token <token_ptr> t_keyword_def
%token <token_ptr> t_keyword_return
%token <token_ptr> t_keyword_yield
%token <token_ptr> t_keyword_class
%token <token_ptr> t_keyword_lambda

%token <token_ptr> t_keyword_if
%token <token_ptr> t_keyword_else
%token <token_ptr> t_keyword_elif
%token <token_ptr> t_keyword_for
%token <token_ptr> t_keyword_break
%token <token_ptr> t_keyword_continue
%token <token_ptr> t_keyword_match
%token <token_ptr> t_keyword_case

%token <token_ptr> t_keyword_global
%token <token_ptr> t_keyword_nonlocal
%token <token_ptr> t_keyword_del

%token <token_ptr> t_keyword_import
%token <token_ptr> t_keyword_from
%token <token_ptr> t_keyword_as

%token <token_ptr> t_keyword_raise
%token <token_ptr> t_keyword_try
%token <token_ptr> t_keyword_except
%token <token_ptr> t_keyword_finally

%token <token_ptr> t_keyword_assert

%token <token_ptr> t_keyword_tastror_out



%start file

%type <astnode_ptr> ast_error

%type <astnode_ptr> statement
// %type <astnode_ptr> simple_stmt
// %type <astnode_ptr> compound_stmt
// %type <astnode_ptr> assignment
// %type <astnode_ptr> block

%%

file : statement
            {
                ast_head = make_astnode();
                ast_head->eat($1);
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
        | t_newline
            {
                LOG_ASTNODE("t_newline");
                $$ = make_astnode();
                $$->type = astnode_type::error;
                now_block_depth = 0;
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
                    } else if (
                        $$->token_leaf.content.indent_num.space_num == 0 &&
                        $$->token_leaf.content.indent_num.tab_num == 0
                    ) {
                        yyerror(ast_head, "WTF to get here");
                        use_tab = false;
                        block_depth_cell = 4;
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
        | t_bracket_parentheses_l
            {
                LOG_ASTNODE("t");
                $$ = make_astnode();
                $$->type = astnode_type::error;
            }
        | t_bracket_parentheses_r
            {
                LOG_ASTNODE("t");
                $$ = make_astnode();
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