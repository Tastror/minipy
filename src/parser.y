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
#include "../src/log.h"
#include "../src/common.h"
#include "../src/lexer.h"
#include "../src/parser.h"

// #define yyoverflow

#define LOG_ASTNODE(type_string) \
    do { Logger << Log::info << "astnode: " << type_string << Log::endl; } while(0)

#define GEN_NODE(string, node, leaf, Ttype) do { \
    LOG_ASTNODE(string); \
    node = make_astnode_from_token(leaf); \
    node->type = Ttype; \
} while(0)

#define EMPTY(node, leaf) GEN_NODE("empty", node, leaf, astnode_type::error)
#define DELIMITER(node, leaf) GEN_NODE("t_delimiter", node, leaf, astnode_type::error)
#define BRACKET(node, leaf) GEN_NODE("t_bracket", node, leaf, astnode_type::error)
#define OPERATORS(node, leaf) GEN_NODE("t_operators", node, leaf, astnode_type::error)
#define KEYWORD(node, leaf) GEN_NODE("t_keyword", node, leaf, astnode_type::error)

}

%union {
    Token* token_ptr;
    AstNode* astnode_ptr;
};

%parse-param {AstNode*& ast_head}



%token <token_ptr> t_error

%token <token_ptr> t_newline
%token <token_ptr> t_indent
%token <token_ptr> t_dedent

%token <token_ptr> t_identifier
%token <token_ptr> t_integer
%token <token_ptr> t_floats
%token <token_ptr> t_strtext  // just for str

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

%type <astnode_ptr> statements
%type <astnode_ptr> statement
%type <astnode_ptr> simple_stmts
%type <astnode_ptr> simple_stmt
%type <astnode_ptr> _no_newline_simple_stmt
// %type <astnode_ptr> compound_stmt

// %type <astnode_ptr> assignment
// %type <astnode_ptr> block

%%

file : statements
            {
                ast_head = make_astnode();
                ast_head->eat($1);
                ast_head->type = astnode_type::file;
            }

statements : statement
            {
                $$ = make_astnode();
                $$->eat($1);
                $$->type = astnode_type::statements;
            }
        | statements statement
            {
                $$ = $1->eat($2);
            }

statement : simple_stmts
            {
                $$ = $1;
                $$->type = astnode_type::statement;
            }
        | ast_error
            {
                $$ = $1;
                $$->type = astnode_type::statement;
            }

simple_stmts : _no_newline_simple_stmt t_newline
            {
                $$ = $1;
                $$->type = astnode_type::simple_stmts;
            }
        | _no_newline_simple_stmt t_delimiter_semicolon t_newline
            {
                $$ = $1;
                $$->type = astnode_type::simple_stmts;
            }

_no_newline_simple_stmt : simple_stmt
            {
                $$ = make_astnode();
                $$->eat($1);
            }
        | _no_newline_simple_stmt t_delimiter_semicolon simple_stmt
            {
                $$ = $1;
                $$->eat($3);
            }

simple_stmt : t_keyword_pass
            {
                GEN_NODE("t_keyword", $$, $1, astnode_type::simple_stmt);
            }
        | t_keyword_break
            {
                GEN_NODE("t_keyword", $$, $1, astnode_type::simple_stmt);
            }
        | t_keyword_continue
            {
                GEN_NODE("t_keyword", $$, $1, astnode_type::simple_stmt);
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
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_indent
            {
                LOG_ASTNODE("t_indent");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_dedent
            {
                LOG_ASTNODE("t_dedent");
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
        | t_strtext
            {
                LOG_ASTNODE("t_strtext");
                $$ = make_astnode_from_token($1);
                $$->type = astnode_type::error;
            }
        | t_delimiter_comma { DELIMITER($$, $1); }
        | t_delimiter_colon { DELIMITER($$, $1); }
        | t_delimiter_arrow { DELIMITER($$, $1); }
        // | t_delimiter_semicolon { DELIMITER($$, $1); }
        | t_delimiter_dot { DELIMITER($$, $1); }
        | t_bracket_squotes { BRACKET($$, $1); }
        | t_bracket_dquotes { BRACKET($$, $1); }
        | t_bracket_parentheses_l { BRACKET($$, $1); }
        | t_bracket_parentheses_r { BRACKET($$, $1); }
        | t_bracket_square_l { BRACKET($$, $1); }
        | t_bracket_square_r { BRACKET($$, $1); }
        | t_bracket_curly_l { BRACKET($$, $1); }
        | t_bracket_curly_r { BRACKET($$, $1); }
        | t_operators_add { OPERATORS($$, $1); }
        | t_operators_sub { OPERATORS($$, $1); }
        | t_operators_mul { OPERATORS($$, $1); }
        | t_operators_div { OPERATORS($$, $1); }
        | t_operators_ediv { OPERATORS($$, $1); }
        | t_operators_mod { OPERATORS($$, $1); }
        | t_operators_pow { OPERATORS($$, $1); }
        | t_operators_at { OPERATORS($$, $1); }
        | t_operators_and { OPERATORS($$, $1); }
        | t_operators_or { OPERATORS($$, $1); }
        | t_operators_xor { OPERATORS($$, $1); }
        | t_operators_not { OPERATORS($$, $1); }
        | t_operators_sleft { OPERATORS($$, $1); }
        | t_operators_sright { OPERATORS($$, $1); }
        | t_operators_eq { OPERATORS($$, $1); }
        | t_operators_neq { OPERATORS($$, $1); }
        | t_operators_leq { OPERATORS($$, $1); }
        | t_operators_geq { OPERATORS($$, $1); }
        | t_operators_lt { OPERATORS($$, $1); }
        | t_operators_gt { OPERATORS($$, $1); }
        | t_operators_assign { OPERATORS($$, $1); }
        | t_operators_add_assign { OPERATORS($$, $1); }
        | t_operators_sub_assign { OPERATORS($$, $1); }
        | t_operators_mul_assign { OPERATORS($$, $1); }
        | t_operators_div_assign { OPERATORS($$, $1); }
        | t_operators_ediv_assign { OPERATORS($$, $1); }
        | t_operators_mod_assign { OPERATORS($$, $1); }
        | t_operators_pow_assign { OPERATORS($$, $1); }
        | t_operators_at_assign { OPERATORS($$, $1); }
        | t_operators_and_assign { OPERATORS($$, $1); }
        | t_operators_or_assign { OPERATORS($$, $1); }
        | t_operators_xor_assign { OPERATORS($$, $1); }
        | t_operators_not_assign { OPERATORS($$, $1); }
        | t_operators_sleft_assign { OPERATORS($$, $1); }
        | t_operators_sright_assign { OPERATORS($$, $1); }
        | t_keyword_underline { KEYWORD($$, $1); }
        | t_keyword_None { KEYWORD($$, $1); }
        | t_keyword_True { KEYWORD($$, $1); }
        | t_keyword_False { KEYWORD($$, $1); }
        | t_keyword_and { KEYWORD($$, $1); }
        | t_keyword_or { KEYWORD($$, $1); }
        | t_keyword_not { KEYWORD($$, $1); }
        | t_keyword_is { KEYWORD($$, $1); }
        | t_keyword_in { KEYWORD($$, $1); }
        // | t_keyword_pass { KEYWORD($$, $1); }
        | t_keyword_def { KEYWORD($$, $1); }
        | t_keyword_return { KEYWORD($$, $1); }
        | t_keyword_yield { KEYWORD($$, $1); }
        | t_keyword_class { KEYWORD($$, $1); }
        | t_keyword_lambda { KEYWORD($$, $1); }
        | t_keyword_if { KEYWORD($$, $1); }
        | t_keyword_else { KEYWORD($$, $1); }
        | t_keyword_elif { KEYWORD($$, $1); }
        | t_keyword_for { KEYWORD($$, $1); }
        // | t_keyword_break { KEYWORD($$, $1); }
        // | t_keyword_continue { KEYWORD($$, $1); }
        | t_keyword_match { KEYWORD($$, $1); }
        | t_keyword_case { KEYWORD($$, $1); }
        | t_keyword_global { KEYWORD($$, $1); }
        | t_keyword_nonlocal { KEYWORD($$, $1); }
        | t_keyword_del { KEYWORD($$, $1); }
        | t_keyword_import { KEYWORD($$, $1); }
        | t_keyword_from { KEYWORD($$, $1); }
        | t_keyword_as { KEYWORD($$, $1); }
        | t_keyword_raise { KEYWORD($$, $1); }
        | t_keyword_try { KEYWORD($$, $1); }
        | t_keyword_except { KEYWORD($$, $1); }
        | t_keyword_finally { KEYWORD($$, $1); }
        | t_keyword_assert { KEYWORD($$, $1); }
        | t_keyword_tastror_out { KEYWORD($$, $1); }

%%

void yyerror(AstNode*& ast_head, char* msg)
{
    Logger << Log::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << Log::endl;
}
