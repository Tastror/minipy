%{
#include <string>
#include <memory>
#include <cassert>

#include "compiler_flex.h"
#include "../src/common.h"
#include "../src/log.h"
#include "../src/lexer.h"
#include "../src/parser.h"

void yyerror(AstNode*& ast_head, char* msg);
void yyerror(AstNode*& ast_head, char* msg, int space_num, int tab_num);

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

#define EMPTY(node) do { \
    LOG_ASTNODE("empty"); \
    node = make_astnode(); \
    node->type = astnode_type::error; \
} while(0)

#define IDN(node) node->token_leaf.content.indent_num
}

%union {
    Token* token_ptr;
    AstNode* astnode_ptr;
};

%parse-param {AstNode*& ast_head}



%token <token_ptr> t_error

%token <token_ptr> t_newline
%token <token_ptr> t_indent

%token <token_ptr> t_identifier
%token <token_ptr> t_integer
%token <token_ptr> t_floats
%token <token_ptr> t_rawtext  // just for str

%token <token_ptr> t_delimiter_comma        // ,
%token <token_ptr> t_delimiter_colon        // :
%token <token_ptr> t_delimiter_arrow        // ->
%token <token_ptr> t_delimiter_semicolon    // ;
%token <token_ptr> t_delimiter_dot          // .

%token <token_ptr> t_bracket_squotes
%token <token_ptr> t_bracket_dquotes
%token <token_ptr> t_bracket_parentheses_l
%token <token_ptr> t_bracket_parentheses_r
%token <token_ptr> t_bracket_square_l
%token <token_ptr> t_bracket_square_r
%token <token_ptr> t_bracket_curly_l
%token <token_ptr> t_bracket_curly_r

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

%token <token_ptr> t_keyword_underline  // _
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
                    if (IDN($$).space_num != 0 && IDN($$).tab_num != 0) {
                        yyerror(ast_head, "mix space and tab together", IDN($$).space_num, IDN($$).tab_num);
                        block_depth_init = false;  // reinit next time
                    }
                    else if (IDN($$).space_num != 0 &&IDN($$).tab_num == 0) {
                        use_tab = false;
                        block_depth_cell = IDN($$).space_num;
                        IDN($$).valid_depth = now_block_depth = 1;
                    }
                    else if (IDN($$).space_num == 0 && IDN($$).tab_num != 0) {
                        use_tab = true;
                        block_depth_cell = IDN($$).tab_num;
                        IDN($$).valid_depth = now_block_depth = 1;
                    }
                    else {
                        assert(false && "you cannot get here, unless your lex for t_indent is wrong!!!");
                    }
                } else {
                    if (IDN($$).space_num != 0 && IDN($$).tab_num != 0) {
                        yyerror(ast_head, "mix space and tab together", IDN($$).space_num, IDN($$).tab_num);
                    }
                    else if (
                        !use_tab &&
                        IDN($$).space_num != 0 && IDN($$).tab_num == 0 &&
                        IDN($$).space_num % block_depth_cell == 0
                    ) {
                        IDN($$).valid_depth = now_block_depth = IDN($$).space_num / block_depth_cell;
                    }
                    else if (
                        use_tab &&
                        IDN($$).space_num == 0 && IDN($$).tab_num != 0 &&
                        IDN($$).tab_num % block_depth_cell == 0
                    ) {
                        IDN($$).valid_depth = now_block_depth = IDN($$).tab_num / block_depth_cell;
                    }
                    else if (IDN($$).space_num == 0 && IDN($$).tab_num == 0) {
                        assert(false && "you cannot get here, unless your lex for t_indent is wrong!!!");
                    }
                    else {
                        yyerror(ast_head, "unindent does not match any outer indentation level", IDN($$).space_num, IDN($$).tab_num);
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
        | t_rawtext
            {
                LOG_ASTNODE("t_rawtext");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_delimiter_comma { EMPTY($$); }
        | t_delimiter_colon { EMPTY($$); }
        | t_delimiter_arrow { EMPTY($$); }
        | t_delimiter_semicolon { EMPTY($$); }
        | t_delimiter_dot { EMPTY($$); }
        | t_bracket_squotes { EMPTY($$); }
        | t_bracket_dquotes { EMPTY($$); }
        | t_bracket_parentheses_l { EMPTY($$); }
        | t_bracket_parentheses_r { EMPTY($$); }
        | t_bracket_square_l { EMPTY($$); }
        | t_bracket_square_r { EMPTY($$); }
        | t_bracket_curly_l { EMPTY($$); }
        | t_bracket_curly_r { EMPTY($$); }
        | t_operators_add { EMPTY($$); }
        | t_operators_sub { EMPTY($$); }
        | t_operators_mul { EMPTY($$); }
        | t_operators_div { EMPTY($$); }
        | t_operators_ediv { EMPTY($$); }
        | t_operators_mod { EMPTY($$); }
        | t_operators_pow { EMPTY($$); }
        | t_operators_at { EMPTY($$); }
        | t_operators_and { EMPTY($$); }
        | t_operators_or { EMPTY($$); }
        | t_operators_xor { EMPTY($$); }
        | t_operators_not { EMPTY($$); }
        | t_operators_sleft { EMPTY($$); }
        | t_operators_sright { EMPTY($$); }
        | t_operators_eq { EMPTY($$); }
        | t_operators_neq { EMPTY($$); }
        | t_operators_leq { EMPTY($$); }
        | t_operators_geq { EMPTY($$); }
        | t_operators_lt { EMPTY($$); }
        | t_operators_gt { EMPTY($$); }
        | t_operators_assign { EMPTY($$); }
        | t_operators_add_assign { EMPTY($$); }
        | t_operators_sub_assign { EMPTY($$); }
        | t_operators_mul_assign { EMPTY($$); }
        | t_operators_div_assign { EMPTY($$); }
        | t_operators_ediv_assign { EMPTY($$); }
        | t_operators_mod_assign { EMPTY($$); }
        | t_operators_pow_assign { EMPTY($$); }
        | t_operators_at_assign { EMPTY($$); }
        | t_operators_and_assign { EMPTY($$); }
        | t_operators_or_assign { EMPTY($$); }
        | t_operators_xor_assign { EMPTY($$); }
        | t_operators_not_assign { EMPTY($$); }
        | t_operators_sleft_assign { EMPTY($$); }
        | t_operators_sright_assign { EMPTY($$); }
        | t_keyword_underline { EMPTY($$); }
        | t_keyword_None { EMPTY($$); }
        | t_keyword_True { EMPTY($$); }
        | t_keyword_False { EMPTY($$); }
        | t_keyword_and { EMPTY($$); }
        | t_keyword_or { EMPTY($$); }
        | t_keyword_not { EMPTY($$); }
        | t_keyword_is { EMPTY($$); }
        | t_keyword_in { EMPTY($$); }
        | t_keyword_pass { EMPTY($$); }
        | t_keyword_def { EMPTY($$); }
        | t_keyword_return { EMPTY($$); }
        | t_keyword_yield { EMPTY($$); }
        | t_keyword_class { EMPTY($$); }
        | t_keyword_lambda { EMPTY($$); }
        | t_keyword_if { EMPTY($$); }
        | t_keyword_else { EMPTY($$); }
        | t_keyword_elif { EMPTY($$); }
        | t_keyword_for { EMPTY($$); }
        | t_keyword_break { EMPTY($$); }
        | t_keyword_continue { EMPTY($$); }
        | t_keyword_match { EMPTY($$); }
        | t_keyword_case { EMPTY($$); }
        | t_keyword_global { EMPTY($$); }
        | t_keyword_nonlocal { EMPTY($$); }
        | t_keyword_del { EMPTY($$); }
        | t_keyword_import { EMPTY($$); }
        | t_keyword_from { EMPTY($$); }
        | t_keyword_as { EMPTY($$); }
        | t_keyword_raise { EMPTY($$); }
        | t_keyword_try { EMPTY($$); }
        | t_keyword_except { EMPTY($$); }
        | t_keyword_finally { EMPTY($$); }
        | t_keyword_assert { EMPTY($$); }
        | t_keyword_tastror_out { EMPTY($$); }

%%

void yyerror(AstNode*& ast_head, char* msg)
{
    Logger << Log::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << Log::endl;
}

void yyerror(AstNode*& ast_head, char* msg, int space_num, int tab_num)
{
    Logger << Log::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": " << space_num << " space(s) and " << tab_num << " tab(s), "
        << msg << Log::endl;
}