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

#define LOG_ASTNODE(log_info_string) \
    do { Logger << Log::info << "astnode: " << log_info_string << Log::endl; } while(0)

// below only for ast_error
#define GEN_ERROR_NODE(log_info_string, new_astnode_ptr, token_ptr) do { \
    LOG_ASTNODE(log_info_string); \
    new_astnode_ptr = make_astnode_from_token(token_ptr); \
} while(0)
#define EMPTY(node, leaf) GEN_ERROR_NODE("... (for ast_error)", node, leaf)
#define DELIMITER(node, leaf) GEN_ERROR_NODE("t_delimiter_... (for ast_error)", node, leaf)
#define BRACKET(node, leaf) GEN_ERROR_NODE("t_bracket_... (for ast_error)", node, leaf)
#define OPERATORS(node, leaf) GEN_ERROR_NODE("t_operators_... (for ast_error)", node, leaf)
#define KEYWORD(node, leaf) GEN_ERROR_NODE("t_keyword_... (for ast_error)", node, leaf)

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
%token <token_ptr> t_number
%token <token_ptr> t_strtext  // just for str

%token <token_ptr> t_delimiter_comma        // ,
%token <token_ptr> t_delimiter_colon        // :
%token <token_ptr> t_delimiter_arrow        // ->
%token <token_ptr> t_delimiter_semicolon    // ;
%token <token_ptr> t_delimiter_dot          // .
%token <token_ptr> t_delimiter_3dot         // ...

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
%token <token_ptr> t_keyword_await

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
%type <astnode_ptr> _no_newline_simple_stmt
%type <astnode_ptr> simple_stmt
%type <astnode_ptr> compound_stmt

%type <astnode_ptr> assignment
%type <astnode_ptr> _no_type_assign
%type <astnode_ptr> augassign
%type <astnode_ptr> return_stmt
%type <astnode_ptr> raise_stmt
%type <astnode_ptr> global_stmt
%type <astnode_ptr> nonlocal_stmt
%type <astnode_ptr> del_stmt
%type <astnode_ptr> yield_stmt
%type <astnode_ptr> import_stmt

%type <astnode_ptr> import_from
%type <astnode_ptr> import_from_targets
%type <astnode_ptr> import_from_as_names
%type <astnode_ptr> import_from_as_name
%type <astnode_ptr> dotted_as_names
%type <astnode_ptr> dotted_as_name
%type <astnode_ptr> dotted_name

%type <astnode_ptr> block
%type <astnode_ptr> decorators

%type <astnode_ptr> class_def
%type <astnode_ptr> class_def_raw

%type <astnode_ptr> function_def
%type <astnode_ptr> function_def_raw

%type <astnode_ptr> params
%type <astnode_ptr> parameters
%type <astnode_ptr> slash_no_default
%type <astnode_ptr> slash_with_default
%type <astnode_ptr> star_etc
%type <astnode_ptr> kwds

%type <astnode_ptr> param_no_default
%type <astnode_ptr> param_no_default_star_annotation
%type <astnode_ptr> param_with_default
%type <astnode_ptr> param_maybe_default
%type <astnode_ptr> param
%type <astnode_ptr> param_star_annotation
%type <astnode_ptr> annotation
%type <astnode_ptr> star_annotation
%type <astnode_ptr> default

%type <astnode_ptr> if_stmt
%type <astnode_ptr> elif_stmt
%type <astnode_ptr> else_block
%type <astnode_ptr> while_stmt
%type <astnode_ptr> for_stmt
%type <astnode_ptr> with_stmt
%type <astnode_ptr> with_item

%type <astnode_ptr> try_stmt
%type <astnode_ptr> except_block
%type <astnode_ptr> except_star_block
%type <astnode_ptr> finally_block

%type <astnode_ptr> match_stmt
%type <astnode_ptr> subject_expr
%type <astnode_ptr> case_block
%type <astnode_ptr> guard
%type <astnode_ptr> patterns
%type <astnode_ptr> pattern
%type <astnode_ptr> as_pattern
%type <astnode_ptr> or_pattern
%type <astnode_ptr> closed_pattern
%type <astnode_ptr> literal_pattern
%type <astnode_ptr> literal_expr
%type <astnode_ptr> complex_number
%type <astnode_ptr> signed_number
%type <astnode_ptr> signed_real_number
%type <astnode_ptr> real_number
%type <astnode_ptr> imaginary_number
%type <astnode_ptr> capture_pattern
%type <astnode_ptr> pattern_capture_target
%type <astnode_ptr> wildcard_pattern
%type <astnode_ptr> value_pattern
%type <astnode_ptr> attr
%type <astnode_ptr> name_or_attr
%type <astnode_ptr> group_pattern
%type <astnode_ptr> sequence_pattern
%type <astnode_ptr> open_sequence_pattern
%type <astnode_ptr> maybe_sequence_pattern
%type <astnode_ptr> maybe_star_pattern
%type <astnode_ptr> star_pattern
%type <astnode_ptr> mapping_pattern
%type <astnode_ptr> items_pattern
%type <astnode_ptr> key_value_pattern
%type <astnode_ptr> double_star_pattern
%type <astnode_ptr> class_pattern
%type <astnode_ptr> positional_patterns
%type <astnode_ptr> keyword_patterns
%type <astnode_ptr> keyword_pattern

%type <astnode_ptr> expressions_type
%type <astnode_ptr> expressions_lhs
%type <astnode_ptr> expressions_rhs

// %type <astnode_ptr> _stars_lhs_or_single_lhs
// %type <astnode_ptr> stars_lhs
// %type <astnode_ptr> _no_endcomma_star_lhs
// %type <astnode_ptr> star_lhs
// %type <astnode_ptr> single_lhs
// %type <astnode_ptr> primary_lhs

// %type <astnode_ptr> star_named_expressions
// %type <astnode_ptr> star_named_expression
// %type <astnode_ptr> assignment_expression
// %type <astnode_ptr> named_expression

%type <astnode_ptr> yield_expr
%type <astnode_ptr> _normal_expression
%type <astnode_ptr> star_expressions
%type <astnode_ptr> _no_endcomma_star_expressions
%type <astnode_ptr> star_expression
%type <astnode_ptr> _expression_if_else
%type <astnode_ptr> _disjunction_or_just_conjunction
%type <astnode_ptr> disjunction
%type <astnode_ptr> _conjunction_or_just_inversion
%type <astnode_ptr> conjunction
%type <astnode_ptr> inversion
%type <astnode_ptr> _comparison_or_just_bitwise_or
%type <astnode_ptr> comparison
%type <astnode_ptr> compare_op_bitwise_or_pair
%type <astnode_ptr> bitwise_or
%type <astnode_ptr> bitwise_xor
%type <astnode_ptr> bitwise_and
%type <astnode_ptr> shift_expr
%type <astnode_ptr> sum
%type <astnode_ptr> term
%type <astnode_ptr> factor
%type <astnode_ptr> power
%type <astnode_ptr> await_primary
%type <astnode_ptr> primary
%type <astnode_ptr> atom

%type <astnode_ptr> lambdef
%type <astnode_ptr> lambda_params
%type <astnode_ptr> lambda_parameters
%type <astnode_ptr> lambda_slash_no_default
%type <astnode_ptr> lambda_slash_with_default
%type <astnode_ptr> lambda_star_etc
%type <astnode_ptr> lambda_kwds
%type <astnode_ptr> lambda_param_no_default
%type <astnode_ptr> lambda_param_with_default
%type <astnode_ptr> lambda_param_maybe_default
%type <astnode_ptr> lambda_param

%type <astnode_ptr> slices
%type <astnode_ptr> slice
%type <astnode_ptr> _part_fo_slice
%type <astnode_ptr> list
%type <astnode_ptr> tuple
%type <astnode_ptr> set
%type <astnode_ptr> dict
%type <astnode_ptr> double_starred_kvpairs
%type <astnode_ptr> double_starred_kvpair
%type <astnode_ptr> kvpair
%type <astnode_ptr> strings
%type <astnode_ptr> string_text

%type <astnode_ptr> for_if_clauses
%type <astnode_ptr> for_if_clause
%type <astnode_ptr> listcomp
%type <astnode_ptr> setcomp
%type <astnode_ptr> genexp
%type <astnode_ptr> dictcomp

%type <astnode_ptr> arguments
%type <astnode_ptr> args
%type <astnode_ptr> kwargs
%type <astnode_ptr> starred_expression
%type <astnode_ptr> kwarg_or_starred
%type <astnode_ptr> kwarg_or_double_starred

%type <astnode_ptr> del_targets
%type <astnode_ptr> del_target
%type <astnode_ptr> del_t_atom
%type <astnode_ptr> type_expressions
%type <astnode_ptr> func_type_comment

%%


// [1] file, statements

file: statements
            {
                ast_head = $1;
            }

statements:
          statement
            {
                $$ = make_astnode(astnode_type::statements);
                $$->eat_sons($1);
                remove_from_astnode_buff($1);
            }
        | statements statement
            {
                $$ = $1->eat_sons($2);
                remove_from_astnode_buff($2);
            }

statement:
          simple_stmts



// [2] simple statements

simple_stmts:
          _no_newline_simple_stmt t_newline
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                $$ = $1;
            }
        | _no_newline_simple_stmt t_delimiter_semicolon t_newline
            {
                LOG_ASTNODE("t_delimiter_semicolon (for simple_stmts)");
                LOG_ASTNODE("t_newline (for simple_stmts)");
                $$ = $1;
            }
        | t_newline /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                $$ = make_empty_astnode();  // will be eat_sons by statements, which is just empty~
            }

_no_newline_simple_stmt:
          simple_stmt
            {
                $$ = make_astnode(astnode_type::temp);
                $$->eat($1);
            }
        | _no_newline_simple_stmt t_delimiter_semicolon simple_stmt
            {
                LOG_ASTNODE("t_delimiter_semicolon (for _no_newline_simple_stmt)");
                $$ = $1;
                $$->eat($3);
            }

simple_stmt:
          ast_error
        | t_keyword_pass /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_keyword_pass (for simple_stmt)");
                $$ = make_astnode_from_token($1, astnode_type::pass_stmt);
            }
        | t_keyword_break /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_keyword_break (for simple_stmt)");
                $$ = make_astnode_from_token($1, astnode_type::break_stmt);
            }
        | t_keyword_continue /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_keyword_continue (for simple_stmt)");
                $$ = make_astnode_from_token($1, astnode_type::continue_stmt);
            }
        | assignment
        | _normal_expression
        | yield_expr
        // | return_stmt
        // | import_stmt
        // | raise_stmt
        // | global_stmt
        // | nonlocal_stmt
        // | del_stmt
        // | yield_stmt
        // | assert_stmt

assignment:
          _no_type_assign
        | primary t_delimiter_colon expressions_type
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                $$ = make_astnode(astnode_type::assignment);
                $$->eat($1);
                $$->eat($3);
                $$->eat(make_empty_astnode());
            }
        | primary t_delimiter_colon expressions_type t_operators_assign expressions_rhs
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                LOG_ASTNODE("t_operators_assign (for assignment)");
                $$ = make_astnode(astnode_type::assignment);
                $$->eat($1);
                $$->eat($3);
                $$->eat($5);
            }

// only notype assign can use expressions_lhs and "a = b = c = ..."
_no_type_assign:
          expressions_lhs t_operators_assign expressions_rhs
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                $$ = make_astnode(astnode_type::assignment);
                $$->eat($1);
                $$->eat(make_empty_astnode());
                $$->eat($3);
            }
        | expressions_lhs t_operators_assign _no_type_assign
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                $$ = make_astnode(astnode_type::assignment);
                $$->eat($1);
                $$->eat(make_empty_astnode());
                $$->eat($3);
            }



// [3] compound (block) statements

// TODO



// [4] expressions

// expression (type, lhs, rhs) order
// (no genexp yet)
// i means identifier, p means primary_lhs, g means arguments, s means slices, a means atom

// p.i p(g) p() p[s]
// p = a

expressions_type:
          _normal_expression
            {
                $$ = $1;
                $$->type = astnode_type::expressions_type;
            }

expressions_lhs:
          _normal_expression
            {
                $$ = make_astnode(astnode_type::expressions_lhs);
                $$->eat($1);
            }

expressions_rhs:
          _normal_expression
            {
                $$ = make_astnode(astnode_type::expressions_rhs);
                $$->eat($1);
            }
        | yield_expr
            {
                $$ = make_astnode(astnode_type::expressions_rhs);
                $$->eat($1);
            }

// It cannot define which is lhs or rhs (so will go error), so i use another lhs below.

// expressions_lhs:
//           _stars_lhs_or_single_lhs
//             {
//                 $$ = make_astnode(astnode_type::expressions_lhs);
//                 $$->eat($1);
//             }

// _stars_lhs_or_single_lhs:
//           stars_lhs
//         | star_lhs

// stars_lhs:
//           _no_endcomma_star_lhs
//         | _no_endcomma_star_lhs t_delimiter_comma
//             {
//                 LOG_ASTNODE("t_delimiter_comma (for stars_lhs)");
//                 $$ = $1;
//             }
//         | star_lhs t_delimiter_comma
//             {
//                 LOG_ASTNODE("t_delimiter_comma (for stars_lhs)");
//                 $$ = make_astnode(astnode_type::stars_lhs);
//                 $$->eat($1);
//             }

// _no_endcomma_star_lhs:
//           star_lhs t_delimiter_comma star_lhs
//             {
//                 LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_star_lhs)");
//                 $$ = make_astnode(astnode_type::stars_lhs);
//                 $$->eat($1);
//                 $$->eat($3);
//             }
//         | _no_endcomma_star_lhs t_delimiter_comma star_lhs
//             {
//                 LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_star_lhs)");
//                 $$ = $1->eat($3);
//             }

// star_lhs:
//           single_lhs
//         | t_operators_mul single_lhs
//             {
//                 $$ = make_astnode(astnode_type::star_lhs);
//                 $$->eat($2);
//             }

// single_lhs:
//           primary_lhs
//         | t_bracket_parentheses_l single_lhs t_bracket_parentheses_r
//             {
//                 LOG_ASTNODE("t_bracket_parentheses_l (for single_lhs)");
//                 LOG_ASTNODE("t_bracket_parentheses_r (for single_lhs)");
//                 $$ = $2;
//             }

// primary_lhs:
//           atom
//             {
//                 $$ = make_astnode(astnode_type::primary_lhs);
//                 $$->eat($1);
//             }
//         | primary_lhs t_delimiter_dot t_identifier
//             {
//                 LOG_ASTNODE("t_delimiter_dot (for primary_lhs)");
//                 LOG_ASTNODE("t_identifier (for primary_lhs)");
//                 $$->eat(make_astnode_from_token($2, astnode_type::sign_annotate));
//                 $$->eat(make_astnode_from_token($3, astnode_type::atom));
//             }
//         // | primary_lhs '[' slices ']'   // wait for slices

// expression order
// (no genexp yet)
// i means identifier, p means primary, g means arguments, s means slices, a means atom

// xx if xx else xx
// yield xx, yield from xx
// xx, xx, xx
// *xx
// xx or xx
// xx and xx
// not xx
// ==, !=, <, <=, >, >=, not in, in, is not, is
// |
// ^
// &
// <<
// >>
// +, -
// *, /, //, %, @
// +(single), -(single), ~
// **
// await xx
// p.i p(g) p() p[s]
// p = a

// below are not normal

// star_named_expressions:
// star_named_expression:
// named_expression:
//           assignment_expression
//         | expressions
// assignment_expression:
//           t_identifier ':=' expression

// above are not normal

yield_expr:
          t_keyword_yield
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                $$ = make_astnode(astnode_type::yield_expr);
                $$->eat(make_empty_astnode());
            }
        | t_keyword_yield _normal_expression
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                $$ = make_astnode(astnode_type::yield_expr);
                $$->eat($2);
            }
        | t_keyword_yield t_keyword_from _normal_expression
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                LOG_ASTNODE("t_keyword_from (for yield_expr)");
                $$ = make_astnode(astnode_type::yield_from_expr);
                $$->eat($3);
            }

_normal_expression:
          star_expressions
        | star_expression

star_expressions:
          _no_endcomma_star_expressions
        | _no_endcomma_star_expressions t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for star_expressions)");
                $$ = $1;
            }
        | star_expression t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for star_expressions)");
                $$ = make_astnode(astnode_type::expressions);  // to normal expressions
                $$->eat($1);
            }

_no_endcomma_star_expressions:
          star_expression t_delimiter_comma star_expression
            {
                LOG_ASTNODE("t_delimiter_comma (for star_expressions)");
                $$ = make_astnode(astnode_type::expressions);  // to normal expressions
                $$->eat($1);
                $$->eat($3);
            }
        | _no_endcomma_star_expressions t_delimiter_comma star_expression
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_star_expressions)");
                $$ = $1->eat($3);
            }

star_expression:
          _expression_if_else
        | t_operators_mul _expression_if_else
            {
                LOG_ASTNODE("t_operators_mul (for star_expression)");
                $$ = make_astnode(astnode_type::star_expression);
                $$->eat($2);
            }

_expression_if_else:
          _disjunction_or_just_conjunction
        | _disjunction_or_just_conjunction t_keyword_if _disjunction_or_just_conjunction t_keyword_else _expression_if_else
            {
                $$ = make_astnode(astnode_type::expression_if_else);
                $$->eat($1);
                $$->eat($3);
                $$->eat($5);
            } 
        // | lambdef

_disjunction_or_just_conjunction:
          _conjunction_or_just_inversion
        | disjunction

disjunction:
          _conjunction_or_just_inversion t_keyword_or _conjunction_or_just_inversion
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                $$ = make_astnode(astnode_type::disjunction);
                $$->eat($1);
                $$->eat($3);
            }
        | disjunction t_keyword_or _conjunction_or_just_inversion
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                $$ = $1->eat($3);
            }

_conjunction_or_just_inversion:
          inversion
        | conjunction

conjunction:
          inversion t_keyword_and inversion
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                $$ = make_astnode(astnode_type::conjunction);
                $$->eat($1);
                $$->eat($3);
            }
        | conjunction t_keyword_and inversion
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                $$ = $1->eat($3);
            }

inversion:
          _comparison_or_just_bitwise_or
        | t_keyword_not inversion
            {
                LOG_ASTNODE("t_keyword_not (for inversion)");
                $$ = make_astnode(astnode_type::inversion);
                $$->eat($2);
            }

_comparison_or_just_bitwise_or:
          bitwise_or
        | comparison

comparison:
          bitwise_or compare_op_bitwise_or_pair
            {
                $$ = make_astnode(astnode_type::comparison);
                $$->eat($1);
                $$->eat($2);
            }
        | comparison compare_op_bitwise_or_pair
            {
                $$ = $1->eat($2);
            }

compare_op_bitwise_or_pair:
          t_operators_eq bitwise_or
            {
                LOG_ASTNODE("t_operators_eq (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::eq_bitwise_or);
                $$->eat($2);
            }
        | t_operators_neq bitwise_or
            {
                LOG_ASTNODE("t_operators_neq (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::neq_bitwise_or);
                $$->eat($2);
            }
        | t_operators_leq bitwise_or
            {
                LOG_ASTNODE("t_operators_leq (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::leq_bitwise_or);
                $$->eat($2);
            }
        | t_operators_lt bitwise_or
            {
                LOG_ASTNODE("t_operators_lt (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::lt_bitwise_or);
                $$->eat($2);
            }
        | t_operators_geq bitwise_or
            {
                LOG_ASTNODE("t_operators_geq (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::geq_bitwise_or);
                $$->eat($2);
            }
        | t_operators_gt bitwise_or
            {
                LOG_ASTNODE("t_operators_gt (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::gt_bitwise_or);
                $$->eat($2);
            }
        | t_keyword_not t_keyword_in bitwise_or
            {
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::notin_bitwise_or);
                $$->eat($3);
            }
        | t_keyword_in bitwise_or
            {
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::in_bitwise_or);
                $$->eat($2);
            }
        | t_keyword_is t_keyword_not bitwise_or
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::isnot_bitwise_or);
                $$->eat($3);
            }
        | t_keyword_is bitwise_or
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::is_bitwise_or);
                $$->eat($2);
            }

bitwise_or:
          bitwise_xor
        | bitwise_or t_operators_or bitwise_xor
            {
                LOG_ASTNODE("t_operators_or (for bitwise_or)");
                $$ = make_astnode(astnode_type::bitwise_or);
                $$->eat($1);
                $$->eat($3);
            }

bitwise_xor:
          bitwise_and
        | bitwise_xor t_operators_xor bitwise_and
            {
                LOG_ASTNODE("t_operators_xor (for bitwise_xor)");
                $$ = make_astnode(astnode_type::bitwise_xor);
                $$->eat($1);
                $$->eat($3);
            }

bitwise_and:
          shift_expr
        | bitwise_and t_operators_and shift_expr
            {
                LOG_ASTNODE("t_operators_and (for bitwise_and)");
                $$ = make_astnode(astnode_type::bitwise_and);
                $$->eat($1);
                $$->eat($3);
            }

shift_expr:
          sum
        | shift_expr t_operators_sleft sum
            {
                LOG_ASTNODE("t_operators_sleft (for shift_expr)");
                $$ = make_astnode(astnode_type::shift_left);
                $$->eat($1);
                $$->eat($3);
            }
        | shift_expr t_operators_sright sum
            {
                LOG_ASTNODE("t_operators_sright (for shift_expr)");
                $$ = make_astnode(astnode_type::shift_right);
                $$->eat($1);
                $$->eat($3);
            }

sum:
          term
        | sum t_operators_add term
            {
                LOG_ASTNODE("t_operators_add (for sum)");
                $$ = make_astnode(astnode_type::sum_add);
                $$->eat($1);
                $$->eat($3);
            }
        | sum t_operators_sub term
            {
                LOG_ASTNODE("t_operators_sub (for sum)");
                $$ = make_astnode(astnode_type::sum_sub);
                $$->eat($1);
                $$->eat($3);
            }

term:
          factor
        | term t_operators_mul factor
            {
                LOG_ASTNODE("t_operators_mul (for term)");
                $$ = make_astnode(astnode_type::term_mul);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_div factor
            {
                LOG_ASTNODE("t_operators_div (for term)");
                $$ = make_astnode(astnode_type::term_div);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_ediv factor
            {
                LOG_ASTNODE("t_operators_ediv (for term)");
                $$ = make_astnode(astnode_type::term_ediv);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_mod factor
            {
                LOG_ASTNODE("t_operators_mod (for term)");
                $$ = make_astnode(astnode_type::term_mod);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_at factor
            {
                LOG_ASTNODE("t_operators_at (for term)");
                $$ = make_astnode(astnode_type::term_at);
                $$->eat($1);
                $$->eat($3);
            }

factor:
          power
        | t_operators_add factor
            {
                LOG_ASTNODE("t_operators_add (for factor)");
                $$ = make_astnode(astnode_type::factor_positive);
                $$->eat($2);
            }
        | t_operators_sub factor
            {
                LOG_ASTNODE("t_operators_sub (for factor)");
                $$ = make_astnode(astnode_type::factor_negative);
                $$->eat($2);
            }
        | t_operators_not factor
            {
                LOG_ASTNODE("t_operators_not (for factor)");
                $$ = make_astnode(astnode_type::factor_not);
                $$->eat($2);
            }

power:
          await_primary
        | await_primary t_operators_pow factor
            {
                LOG_ASTNODE("t_operators_pow (for power)");
                $$ = make_astnode(astnode_type::power);
                $$->eat($1);
                $$->eat($3);
            }

await_primary:
          primary
        | t_keyword_await primary
            {
                LOG_ASTNODE("t_keyword_await (for await_primary)");
                $$ = make_astnode(astnode_type::await_primary);
                $$->eat($2);
            }

primary:
          atom
        | primary t_delimiter_dot t_identifier
            {
                LOG_ASTNODE("t_delimiter_dot (for primary)");
                LOG_ASTNODE("t_identifier (for primary)");
                $$->eat(make_astnode_from_token($2, astnode_type::sign_annotate));
                $$->eat(make_astnode_from_token($3, astnode_type::atom));
            }
        // | primary_lhs t_bracket_square_l   // wait for slices

atom:
         t_identifier /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_identifier (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_keyword_True /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_keyword_True (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_keyword_False /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_keyword_False (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_keyword_None /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_keyword_None (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_number /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_number (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_delimiter_3dot /* --- LEAF ONLY --- */
            {
                LOG_ASTNODE("t_delimiter_3dot (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | strings



// [5] basic defines

strings:
          string_text
            {
                $$ = make_astnode(astnode_type::strings);
                $$->eat($1);
            }
        | strings string_text
            {
                $$ = $1->eat($2);
            }

string_text:
          t_bracket_dquotes t_strtext t_bracket_dquotes
            {
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                $$ = make_astnode_from_token($2, astnode_type::string_text);
            }
        | t_bracket_squotes t_strtext t_bracket_squotes
            {
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                $$ = make_astnode_from_token($2, astnode_type::string_text);
            }



// [6] errors

/* --- LEAF ONLY --- */
ast_error :
          t_error { GEN_ERROR_NODE("t_error (for ast_error)", $$, $1); }
        // | t_newline { GEN_ERROR_NODE("t_newline (for ast_error)", $$, $1); }
        | t_indent { GEN_ERROR_NODE("t_indent (for ast_error)", $$, $1); }
        | t_dedent { GEN_ERROR_NODE("t_dedent (for ast_error)", $$, $1); }
        // | t_identifier { GEN_ERROR_NODE("t_identifier (for ast_error)", $$, $1); }
        // | t_number { GEN_ERROR_NODE("t_number (for ast_error)", $$, $1); }
        // | t_strtext { GEN_ERROR_NODE("t_strtext (for ast_error)", $$, $1); }
        // | t_delimiter_comma { DELIMITER($$, $1); }
        // | t_delimiter_colon { DELIMITER($$, $1); }
        | t_delimiter_arrow { DELIMITER($$, $1); }
        // | t_delimiter_semicolon { DELIMITER($$, $1); }
        // | t_delimiter_dot { DELIMITER($$, $1); }
        // | t_delimiter_3dot { DELIMITER($$, $1); }
        // | t_bracket_squotes { BRACKET($$, $1); }
        // | t_bracket_dquotes { BRACKET($$, $1); }
        | t_bracket_parentheses_l { BRACKET($$, $1); }
        | t_bracket_parentheses_r { BRACKET($$, $1); }
        | t_bracket_square_l { BRACKET($$, $1); }
        | t_bracket_square_r { BRACKET($$, $1); }
        | t_bracket_curly_l { BRACKET($$, $1); }
        | t_bracket_curly_r { BRACKET($$, $1); }
        // | t_operators_add { OPERATORS($$, $1); }
        // | t_operators_sub { OPERATORS($$, $1); }
        // | t_operators_mul { OPERATORS($$, $1); }
        // | t_operators_div { OPERATORS($$, $1); }
        // | t_operators_ediv { OPERATORS($$, $1); }
        // | t_operators_mod { OPERATORS($$, $1); }
        // | t_operators_pow { OPERATORS($$, $1); }
        // | t_operators_at { OPERATORS($$, $1); }
        // | t_operators_and { OPERATORS($$, $1); }
        // | t_operators_or { OPERATORS($$, $1); }
        // | t_operators_xor { OPERATORS($$, $1); }
        // | t_operators_not { OPERATORS($$, $1); }
        // | t_operators_sleft { OPERATORS($$, $1); }
        // | t_operators_sright { OPERATORS($$, $1); }
        // | t_operators_eq { OPERATORS($$, $1); }
        // | t_operators_neq { OPERATORS($$, $1); }
        // | t_operators_leq { OPERATORS($$, $1); }
        // | t_operators_geq { OPERATORS($$, $1); }
        // | t_operators_lt { OPERATORS($$, $1); }
        // | t_operators_gt { OPERATORS($$, $1); }
        // | t_operators_assign { OPERATORS($$, $1); }
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
        // | t_keyword_None { KEYWORD($$, $1); }
        // | t_keyword_True { KEYWORD($$, $1); }
        // | t_keyword_False { KEYWORD($$, $1); }
        // | t_keyword_and { KEYWORD($$, $1); }
        // | t_keyword_or { KEYWORD($$, $1); }
        // | t_keyword_not { KEYWORD($$, $1); }
        // | t_keyword_is { KEYWORD($$, $1); }
        // | t_keyword_in { KEYWORD($$, $1); }
        // | t_keyword_pass { KEYWORD($$, $1); }
        | t_keyword_def { KEYWORD($$, $1); }
        | t_keyword_return { KEYWORD($$, $1); }
        // | t_keyword_yield { KEYWORD($$, $1); }
        | t_keyword_class { KEYWORD($$, $1); }
        | t_keyword_lambda { KEYWORD($$, $1); }
        // | t_keyword_await { KEYWORD($$, $1); }
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
