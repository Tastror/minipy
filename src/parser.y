%{
#include <string>
#include <memory>

#include "compiler_flex.h"
#include "../src/timing.h"
#include "../src/log.h"
#include "../src/lexer.h"
#include "../src/parser.h"

void yyerror(AstNode*& ast_head, char* msg);
%}

%code requires {

#include <memory>
#include "../src/log.h"
#include "../src/timing.h"
#include "../src/lexer.h"
#include "../src/parser.h"

#define LOG_ASTNODE(log_info_string) \
    do { stdlog::log << stdlog::info << "astnode: " << log_info_string << stdlog::endl; } while (0)

// below only for ast_error
#define GEN_ERROR_NODE(log_info_string, new_astnode_ptr, token_ptr) do { \
    LOG_ASTNODE(log_info_string); \
    new_astnode_ptr = make_astnode_from_token(token_ptr); \
} while (0)
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



// [1] file, statements

%start file
%type <astnode_ptr> statements


// [2] simple statements

%type <astnode_ptr> simple_stmts
%type <astnode_ptr> _no_newline_simple_stmt
%type <astnode_ptr> simple_stmt

%type <astnode_ptr> assignment
%type <astnode_ptr> _no_type_assign
%type <astnode_ptr> augassign
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


// [3] compound (block) statements

%type <astnode_ptr> compound_stmt

%type <astnode_ptr> class_def
%type <astnode_ptr> class_def_raw

%type <astnode_ptr> function_def
%type <astnode_ptr> function_def_raw

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

%type <astnode_ptr> block
%type <astnode_ptr> decorators


// [4] (not implement yet) match pattern

// %type <astnode_ptr> match_stmt
// %type <astnode_ptr> subject_expr
// %type <astnode_ptr> case_block
// %type <astnode_ptr> guard
// %type <astnode_ptr> patterns
// %type <astnode_ptr> pattern
// %type <astnode_ptr> as_pattern
// %type <astnode_ptr> or_pattern
// %type <astnode_ptr> closed_pattern
// %type <astnode_ptr> literal_pattern
// %type <astnode_ptr> literal_expr
// %type <astnode_ptr> complex_number
// %type <astnode_ptr> signed_number
// %type <astnode_ptr> signed_real_number
// %type <astnode_ptr> real_number
// %type <astnode_ptr> imaginary_number
// %type <astnode_ptr> capture_pattern
// %type <astnode_ptr> pattern_capture_target
// %type <astnode_ptr> wildcard_pattern
// %type <astnode_ptr> value_pattern
// %type <astnode_ptr> attr
// %type <astnode_ptr> name_or_attr
// %type <astnode_ptr> group_pattern
// %type <astnode_ptr> sequence_pattern
// %type <astnode_ptr> open_sequence_pattern
// %type <astnode_ptr> maybe_sequence_pattern
// %type <astnode_ptr> maybe_star_pattern
// %type <astnode_ptr> star_pattern
// %type <astnode_ptr> mapping_pattern
// %type <astnode_ptr> items_pattern
// %type <astnode_ptr> key_value_pattern
// %type <astnode_ptr> double_star_pattern
// %type <astnode_ptr> class_pattern
// %type <astnode_ptr> positional_patterns
// %type <astnode_ptr> keyword_patterns
// %type <astnode_ptr> keyword_pattern


// [5] expressions

%type <astnode_ptr> expressions_type
%type <astnode_ptr> expressions_lhs
%type <astnode_ptr> expressions_rhs

%type <astnode_ptr> yield_expr
%type <astnode_ptr> _normal_multiple_or_single_expr
%type <astnode_ptr> _tuple_like_multiple_or_single_expr
%type <astnode_ptr> _no_endcomma_multiple_expressions
%type <astnode_ptr> _normal_single_expression
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


// [6] basic defines

%type <astnode_ptr> list
%type <astnode_ptr> tuple
%type <astnode_ptr> set
%type <astnode_ptr> dict

%type <astnode_ptr> for_if_clauses
%type <astnode_ptr> for_if_clause
%type <astnode_ptr> listcomp
%type <astnode_ptr> setcomp
%type <astnode_ptr> genexp
%type <astnode_ptr> dictcomp

%type <astnode_ptr> double_starred_kvpairs
%type <astnode_ptr> double_starred_kvpair
%type <astnode_ptr> kvpair
%type <astnode_ptr> slice
%type <astnode_ptr> strings
%type <astnode_ptr> string_text
%type <astnode_ptr> arguments_or_parameters
%type <astnode_ptr> argparas
%type <astnode_ptr> argpara


// [7] errors

%type <astnode_ptr> ast_error

%%


// [1] file, statements

file: statements
            {
                ast_head = $1;
            }

statements:
          simple_stmts
            {
                $$ = make_astnode(astnode_type::statements);
                $$->eat_sons($1);
                delete_astnode($1);
            }
        | compound_stmt
            {
                $$ = make_astnode(astnode_type::statements);
                $$->eat($1);
            }
        | statements simple_stmts
            {
                $$ = $1->eat_sons($2);
                delete_astnode($2);
            }
        | statements compound_stmt
            {
                $$ = $1->eat($2);
            }



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
        | t_newline
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
        | t_keyword_pass
            {
                LOG_ASTNODE("t_keyword_pass (for simple_stmt)");
                $$ = make_astnode(astnode_type::zero_op_pass);
            }
        | t_keyword_break
            {
                LOG_ASTNODE("t_keyword_break (for simple_stmt)");
                $$ = make_astnode(astnode_type::zero_op_break);
            }
        | t_keyword_continue
            {
                LOG_ASTNODE("t_keyword_continue (for simple_stmt)");
                $$ = make_astnode(astnode_type::zero_op_continue);
            }
        | assignment
        | _normal_multiple_or_single_expr
        | yield_expr
        | t_keyword_return
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                $$ = make_astnode(astnode_type::sin_op_return);
                $$->eat(make_empty_astnode());
            }
        | t_keyword_return _normal_multiple_or_single_expr
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                $$ = make_astnode(astnode_type::sin_op_return);
                $$->eat($2);
            }
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
                $$ = make_astnode(astnode_type::tri_op_assign);
                $$->eat($3);
                $$->eat($1);
                $$->eat(make_empty_astnode());
            }
        | primary t_delimiter_colon expressions_type t_operators_assign expressions_rhs
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                LOG_ASTNODE("t_operators_assign (for assignment)");
                $$ = make_astnode(astnode_type::tri_op_assign);
                $$->eat($3);
                $$->eat($1);
                $$->eat($5);
            }
        | primary augassign expressions_rhs
            {
                $$ = make_astnode(astnode_type::tri_op_augassign);
                $$->eat($2);
                $$->eat($1);
                $$->eat($3);
            }

// only notype assign can use expressions_lhs and "a = b = c = ..."
_no_type_assign:
          expressions_lhs t_operators_assign expressions_rhs
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                $$ = make_astnode(astnode_type::tri_op_assign);
                $$->eat(make_empty_astnode());
                $$->eat($1);
                $$->eat($3);
            }
        | expressions_lhs t_operators_assign _no_type_assign
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                $$ = make_astnode(astnode_type::tri_op_assign);
                $$->eat(make_empty_astnode());
                $$->eat($1);
                $$->eat($3);
            }

augassign:
          t_operators_add_assign    { LOG_ASTNODE("t_operators_add_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_sub_assign    { LOG_ASTNODE("t_operators_sub_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_mul_assign    { LOG_ASTNODE("t_operators_mul_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_div_assign    { LOG_ASTNODE("t_operators_div_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_ediv_assign   { LOG_ASTNODE("t_operators_ediv_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_mod_assign    { LOG_ASTNODE("t_operators_mod_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_pow_assign    { LOG_ASTNODE("t_operators_pow_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_at_assign     { LOG_ASTNODE("t_operators_at_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_and_assign    { LOG_ASTNODE("t_operators_and_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_or_assign     { LOG_ASTNODE("t_operators_or_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_xor_assign    { LOG_ASTNODE("t_operators_xor_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_not_assign    { LOG_ASTNODE("t_operators_not_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_sleft_assign  { LOG_ASTNODE("t_operators_sleft_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }
        | t_operators_sright_assign { LOG_ASTNODE("t_operators_sright_assign (for augassign)"); $$ = make_astnode_from_token($1, astnode_type::atom); }



// [3] compound (block) statements

compound_stmt:
          function_def
        | class_def
        | if_stmt

function_def:
          function_def_raw
            {
                $$ = $1->eat(make_empty_astnode());
            }
        // | decorators function_def_raw

function_def_raw:
          t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                $$ = make_astnode(astnode_type::pen_op_function_block);
                $$->eat(make_astnode_from_token($2, astnode_type::atom));
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
                $$->eat($6);
            }
        | t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                $$ = make_astnode(astnode_type::pen_op_function_block);
                $$->eat(make_astnode_from_token($2, astnode_type::atom));
                $$->eat($4);
                $$->eat(make_empty_astnode());
                $$->eat($7);
            }
        | t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_arrow _normal_multiple_or_single_expr t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_arrow (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                $$ = make_astnode(astnode_type::pen_op_function_block);
                $$->eat(make_astnode_from_token($2, astnode_type::atom));
                $$->eat(make_empty_astnode());
                $$->eat($6);
                $$->eat($8);
            }
        | t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_arrow _normal_multiple_or_single_expr t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_arrow (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                $$ = make_astnode(astnode_type::pen_op_function_block);
                $$->eat(make_astnode_from_token($2, astnode_type::atom));
                $$->eat($4);
                $$->eat($7);
                $$->eat($9);
            }

class_def:
          class_def_raw
            {
                $$ = $1->eat(make_empty_astnode());
            }
        // | decorators class_def_raw

class_def_raw:
          t_keyword_class t_identifier t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                $$ = make_astnode(astnode_type::qua_op_class_block);
                $$->eat(make_astnode_from_token($2, astnode_type::atom));
                $$->eat(make_empty_astnode());
                $$->eat($4);
            }
        | t_keyword_class t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                $$ = make_astnode(astnode_type::qua_op_class_block);
                $$->eat(make_astnode_from_token($2, astnode_type::atom));
                $$->eat(make_empty_astnode());
                $$->eat($6);
            }
        | t_keyword_class t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                $$ = make_astnode(astnode_type::qua_op_class_block);
                $$->eat(make_astnode_from_token($2, astnode_type::atom));
                $$->eat($4);
                $$->eat($7);
            }

if_stmt:
          t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block elif_stmt
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                $$ = make_astnode(astnode_type::tri_op_if_else_block);
                $$->eat($2);
                $$->eat($4);
                $$->eat($5);
            }
        | t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                $$ = make_astnode(astnode_type::tri_op_if_else_block);
                $$->eat($2);
                $$->eat($4);
                $$->eat(make_empty_astnode());
            }
        | t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block else_block
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                $$ = make_astnode(astnode_type::tri_op_if_else_block);
                $$->eat($2);
                $$->eat($4);
                $$->eat($5);
            }

elif_stmt:
          t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block elif_stmt
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                $$ = make_astnode(astnode_type::tri_op_if_else_block);
                $$->eat($2);
                $$->eat($4);
                $$->eat($5);
            }
        | t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                $$ = make_astnode(astnode_type::tri_op_if_else_block);
                $$->eat($2);
                $$->eat($4);
                $$->eat(make_empty_astnode());
            }
        | t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block else_block
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                $$ = make_astnode(astnode_type::tri_op_if_else_block);
                $$->eat($2);
                $$->eat($4);
                $$->eat($5);
            }

else_block:
          t_keyword_else t_delimiter_colon block
            {
                LOG_ASTNODE("t_keyword_else (for else_block)");
                LOG_ASTNODE("t_delimiter_colon (for else_block)");
                $$ = $3;
            }

block:
          t_newline t_indent statements t_dedent
            {
                LOG_ASTNODE("t_newline (for block)");
                LOG_ASTNODE("t_indent (for block)");
                LOG_ASTNODE("t_dedent (for block)");
                $$ = $3;
            }
        | simple_stmts


// [5] expressions

// expression order
// (no genexp yet)
// i means identifier, p means primary, g means arguments, s means slice, a means atom

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

expressions_type:
          primary

expressions_lhs:
          _normal_multiple_or_single_expr

expressions_rhs:
          _normal_multiple_or_single_expr
        | yield_expr

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
                $$ = make_astnode(astnode_type::sin_op_yield);
                $$->eat(make_empty_astnode());
            }
        | t_keyword_yield _normal_multiple_or_single_expr
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                $$ = make_astnode(astnode_type::sin_op_yield);
                $$->eat($2);
            }
        | t_keyword_yield t_keyword_from _normal_multiple_or_single_expr
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                LOG_ASTNODE("t_keyword_from (for yield_expr)");
                $$ = make_astnode(astnode_type::sin_op_yield_from);
                $$->eat($3);
            }

_normal_multiple_or_single_expr:
          _tuple_like_multiple_or_single_expr
        | _normal_single_expression

_tuple_like_multiple_or_single_expr:
          _no_endcomma_multiple_expressions
        | _no_endcomma_multiple_expressions t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for _tuple_like_multiple_or_single_expr)");
                $$ = $1;
            }
        | _normal_single_expression t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for _tuple_like_multiple_or_single_expr)");
                $$ = make_astnode(astnode_type::expressions);  // to normal expressions
                $$->eat($1);
            }

_no_endcomma_multiple_expressions:
          _normal_single_expression t_delimiter_comma _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_multiple_expressions)");
                $$ = make_astnode(astnode_type::expressions);  // to normal expressions
                $$->eat($1);
                $$->eat($3);
            }
        | _no_endcomma_multiple_expressions t_delimiter_comma _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_multiple_expressions)");
                $$ = $1->eat($3);
            }

_normal_single_expression:
          star_expression

star_expression:
          _expression_if_else
        | t_operators_mul _expression_if_else
            {
                LOG_ASTNODE("t_operators_mul (for star_expression)");
                $$ = make_astnode(astnode_type::sin_op_star);
                $$->eat($2);
            }

_expression_if_else:
          _disjunction_or_just_conjunction
        | _disjunction_or_just_conjunction t_keyword_if _disjunction_or_just_conjunction t_keyword_else _expression_if_else
            {
                $$ = make_astnode(astnode_type::tri_op_if_else_expr);
                $$->eat($3);
                $$->eat($1);
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
                $$ = make_astnode(astnode_type::list_op_or);
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
                $$ = make_astnode(astnode_type::list_op_and);
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
                $$ = make_astnode(astnode_type::sin_op_not);
                $$->eat($2);
            }

_comparison_or_just_bitwise_or:
          bitwise_or
        | comparison

comparison:
          bitwise_or compare_op_bitwise_or_pair
            {
                $$ = make_astnode(astnode_type::list_op_comparison);
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
                $$ = make_astnode(astnode_type::comp_op_eq);
                $$->eat($2);
            }
        | t_operators_neq bitwise_or
            {
                LOG_ASTNODE("t_operators_neq (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_neq);
                $$->eat($2);
            }
        | t_operators_leq bitwise_or
            {
                LOG_ASTNODE("t_operators_leq (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_leq);
                $$->eat($2);
            }
        | t_operators_lt bitwise_or
            {
                LOG_ASTNODE("t_operators_lt (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_lt);
                $$->eat($2);
            }
        | t_operators_geq bitwise_or
            {
                LOG_ASTNODE("t_operators_geq (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_geq);
                $$->eat($2);
            }
        | t_operators_gt bitwise_or
            {
                LOG_ASTNODE("t_operators_gt (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_gt);
                $$->eat($2);
            }
        | t_keyword_not t_keyword_in bitwise_or
            {
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_notin);
                $$->eat($3);
            }
        | t_keyword_in bitwise_or
            {
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_in);
                $$->eat($2);
            }
        | t_keyword_is t_keyword_not bitwise_or
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_isnot);
                $$->eat($3);
            }
        | t_keyword_is bitwise_or
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                $$ = make_astnode(astnode_type::comp_op_is);
                $$->eat($2);
            }

bitwise_or:
          bitwise_xor
        | bitwise_or t_operators_or bitwise_xor
            {
                LOG_ASTNODE("t_operators_or (for bitwise_or)");
                $$ = make_astnode(astnode_type::bin_op_or);
                $$->eat($1);
                $$->eat($3);
            }

bitwise_xor:
          bitwise_and
        | bitwise_xor t_operators_xor bitwise_and
            {
                LOG_ASTNODE("t_operators_xor (for bitwise_xor)");
                $$ = make_astnode(astnode_type::bin_op_xor);
                $$->eat($1);
                $$->eat($3);
            }

bitwise_and:
          shift_expr
        | bitwise_and t_operators_and shift_expr
            {
                LOG_ASTNODE("t_operators_and (for bitwise_and)");
                $$ = make_astnode(astnode_type::bin_op_and);
                $$->eat($1);
                $$->eat($3);
            }

shift_expr:
          sum
        | shift_expr t_operators_sleft sum
            {
                LOG_ASTNODE("t_operators_sleft (for shift_expr)");
                $$ = make_astnode(astnode_type::bin_op_sleft);
                $$->eat($1);
                $$->eat($3);
            }
        | shift_expr t_operators_sright sum
            {
                LOG_ASTNODE("t_operators_sright (for shift_expr)");
                $$ = make_astnode(astnode_type::bin_op_sright);
                $$->eat($1);
                $$->eat($3);
            }

sum:
          term
        | sum t_operators_add term
            {
                LOG_ASTNODE("t_operators_add (for sum)");
                $$ = make_astnode(astnode_type::bin_op_add);
                $$->eat($1);
                $$->eat($3);
            }
        | sum t_operators_sub term
            {
                LOG_ASTNODE("t_operators_sub (for sum)");
                $$ = make_astnode(astnode_type::bin_op_sub);
                $$->eat($1);
                $$->eat($3);
            }

term:
          factor
        | term t_operators_mul factor
            {
                LOG_ASTNODE("t_operators_mul (for term)");
                $$ = make_astnode(astnode_type::bin_op_mul);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_div factor
            {
                LOG_ASTNODE("t_operators_div (for term)");
                $$ = make_astnode(astnode_type::bin_op_div);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_ediv factor
            {
                LOG_ASTNODE("t_operators_ediv (for term)");
                $$ = make_astnode(astnode_type::bin_op_ediv);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_mod factor
            {
                LOG_ASTNODE("t_operators_mod (for term)");
                $$ = make_astnode(astnode_type::bin_op_mod);
                $$->eat($1);
                $$->eat($3);
            }
        | term t_operators_at factor
            {
                LOG_ASTNODE("t_operators_at (for term)");
                $$ = make_astnode(astnode_type::bin_op_at);
                $$->eat($1);
                $$->eat($3);
            }

factor:
          power
        | t_operators_add factor
            {
                LOG_ASTNODE("t_operators_add (for factor)");
                $$ = make_astnode(astnode_type::sin_op_positive);
                $$->eat($2);
            }
        | t_operators_sub factor
            {
                LOG_ASTNODE("t_operators_sub (for factor)");
                $$ = make_astnode(astnode_type::sin_op_negative);
                $$->eat($2);
            }
        | t_operators_not factor
            {
                LOG_ASTNODE("t_operators_not (for factor)");
                $$ = make_astnode(astnode_type::sin_op_wavenot);
                $$->eat($2);
            }

power:
          await_primary
        | await_primary t_operators_pow factor
            {
                LOG_ASTNODE("t_operators_pow (for power)");
                $$ = make_astnode(astnode_type::bin_op_power);
                $$->eat($1);
                $$->eat($3);
            }

await_primary:
          primary
        | t_keyword_await primary
            {
                LOG_ASTNODE("t_keyword_await (for await_primary)");
                $$ = make_astnode(astnode_type::sin_op_await);
                $$->eat($2);
            }

primary:
          atom
        | primary t_delimiter_dot t_identifier
            {
                LOG_ASTNODE("t_delimiter_dot (for primary)");
                LOG_ASTNODE("t_identifier (for primary)");
                $$ = make_astnode(astnode_type::bin_op_dot);
                $$->eat($1);
                $$->eat(make_astnode_from_token($3, astnode_type::atom));
            }
        | primary t_bracket_parentheses_l t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                $$ = make_astnode(astnode_type::bin_op_fcall);
                $$->eat($1);
                $$->eat(make_empty_astnode());
            }
        | primary t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                $$ = make_astnode(astnode_type::bin_op_fcall);
                $$->eat($1);
                $$->eat($3);
            }
        | primary t_bracket_square_l slice t_bracket_square_r
            {
                LOG_ASTNODE("t_bracket_square_l (for primary)");
                LOG_ASTNODE("t_bracket_square_r (for primary)");
                $$ = make_astnode(astnode_type::bin_op_index);
                $$->eat($1);
                $$->eat($3);
            }
        | primary t_bracket_square_l _normal_multiple_or_single_expr t_bracket_square_r
            {
                LOG_ASTNODE("t_bracket_square_l (for primary)");
                LOG_ASTNODE("t_bracket_square_r (for primary)");
                $$ = make_astnode(astnode_type::bin_op_index);
                $$->eat($1);
                $$->eat($3);
            }

atom:
         t_identifier
            {
                LOG_ASTNODE("t_identifier (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_keyword_True
            {
                LOG_ASTNODE("t_keyword_True (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_keyword_False
            {
                LOG_ASTNODE("t_keyword_False (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_keyword_None
            {
                LOG_ASTNODE("t_keyword_None (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_keyword_underline
            {
                LOG_ASTNODE("t_keyword_underline (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_number
            {
                LOG_ASTNODE("t_number (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | t_delimiter_3dot
            {
                LOG_ASTNODE("t_delimiter_3dot (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | list
        | tuple
        | set
        | strings
        | t_bracket_parentheses_l yield_expr t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                $$ = $2;
            }
        | t_bracket_parentheses_l _normal_multiple_or_single_expr t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                $$ = $2;
            }



// [6] basic defines

list:
          t_bracket_square_l t_bracket_square_r
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                $$ = make_astnode(astnode_type::list_mayempty_op_list);
            }
        | t_bracket_square_l _tuple_like_multiple_or_single_expr t_bracket_square_r
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                $$ = make_astnode(astnode_type::list_mayempty_op_list);
                $$->eat_sons($2);
                delete_astnode($2);
            }
        | t_bracket_square_l _normal_single_expression t_bracket_square_r
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                $$ = make_astnode(astnode_type::list_mayempty_op_list);
                $$->eat($2);
            }

tuple:
          t_bracket_parentheses_l t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for tuple)");
                LOG_ASTNODE("t_bracket_parentheses_r (for tuple)");
                $$ = make_astnode(astnode_type::list_mayempty_op_tuple);
            }
        | t_bracket_parentheses_l _tuple_like_multiple_or_single_expr t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for tuple)");
                LOG_ASTNODE("t_delimiter_comma (for tuple)");
                LOG_ASTNODE("t_bracket_parentheses_r (for tuple)");
                $$ = make_astnode(astnode_type::list_mayempty_op_tuple);
                $$->eat_sons($2);
                delete_astnode($2);
            }

set:
          t_bracket_curly_l t_bracket_curly_r
            {
                LOG_ASTNODE("t_bracket_curly_l (for set)");
                LOG_ASTNODE("t_bracket_curly_r (for set)");
                $$ = make_astnode(astnode_type::list_mayempty_op_set);
            }
        | t_bracket_curly_l _tuple_like_multiple_or_single_expr t_bracket_curly_r
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                $$ = make_astnode(astnode_type::list_mayempty_op_set);
                $$->eat_sons($2);
                delete_astnode($2);
            }
        | t_bracket_curly_l _normal_single_expression t_bracket_curly_r
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                $$ = make_astnode(astnode_type::list_mayempty_op_set);
                $$->eat($2);
            }

slice:
                                    t_delimiter_colon
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
            }
        |                           t_delimiter_colon _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat(make_empty_astnode());
                $$->eat($2);
                $$->eat(make_empty_astnode());
            }
        | _normal_single_expression t_delimiter_colon
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat($1);
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
            }
        | _normal_single_expression t_delimiter_colon _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat($1);
                $$->eat($3);
                $$->eat(make_empty_astnode());
            }
        |                           t_delimiter_colon                           t_delimiter_colon
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
            }
        |                           t_delimiter_colon                           t_delimiter_colon _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
                $$->eat($3);
            }
        |                           t_delimiter_colon _normal_single_expression t_delimiter_colon
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat(make_empty_astnode());
                $$->eat($2);
                $$->eat(make_empty_astnode());
            }
        |                           t_delimiter_colon _normal_single_expression t_delimiter_colon _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat(make_empty_astnode());
                $$->eat($2);
                $$->eat($4);
            }
        | _normal_single_expression t_delimiter_colon                           t_delimiter_colon
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat($1);
                $$->eat(make_empty_astnode());
                $$->eat(make_empty_astnode());
            }
        | _normal_single_expression t_delimiter_colon                           t_delimiter_colon _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat($1);
                $$->eat(make_empty_astnode());
                $$->eat($4);
            }
        | _normal_single_expression t_delimiter_colon _normal_single_expression t_delimiter_colon
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat($1);
                $$->eat($3);
                $$->eat(make_empty_astnode());
            }
        | _normal_single_expression t_delimiter_colon _normal_single_expression t_delimiter_colon _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                $$ = make_astnode(astnode_type::tri_op_slice);
                $$->eat($1);
                $$->eat($3);
                $$->eat($5);
            }

strings:
          string_text
            {
                $$ = make_astnode(astnode_type::list_op_strings);
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
                $$ = make_astnode_from_token($2, astnode_type::atom);
            }
        | t_bracket_squotes t_strtext t_bracket_squotes
            {
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                $$ = make_astnode_from_token($2, astnode_type::atom);
            }

arguments_or_parameters:
          argparas
        | argparas t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for arguments_or_parameters)");
                $$ = $1;
            }

argparas:
          argpara
            {
                $$ = make_astnode(astnode_type::list_op_args_or_prams);
                $$->eat($1);
            }
        | argparas t_delimiter_comma argpara
            {
                LOG_ASTNODE("t_delimiter_comma (for argparas)");
                $$ = $1->eat($3);
            }

argpara:
          _normal_single_expression
        | primary t_delimiter_colon primary
            {
                LOG_ASTNODE("t_delimiter_colon (for argpara)");
                $$ = make_astnode(astnode_type::bin_op_aptype);
                $$->eat($1);
                $$->eat($3);
            }
        | t_operators_mul _normal_single_expression
            {
                LOG_ASTNODE("t_operators_mul (for argpara)");
                $$ = make_astnode(astnode_type::sin_op_apstar);
                $$->eat($2);
            }
        | t_operators_pow _normal_single_expression
            {
                LOG_ASTNODE("t_operators_pow (for argpara)");
                $$ = make_astnode(astnode_type::sin_op_apdstar);
                $$->eat($2);
            }
        | primary t_operators_assign _normal_single_expression
            {
                LOG_ASTNODE("t_operators_assign (for argpara)");
                $$ = make_astnode(astnode_type::bin_op_apequ);
                $$->eat($1);
                $$->eat($3);
            }
        | primary t_delimiter_colon primary t_operators_assign _normal_single_expression
            {
                LOG_ASTNODE("t_delimiter_colon (for argpara)");
                LOG_ASTNODE("t_operators_assign (for argpara)");
                auto r = make_astnode(astnode_type::bin_op_aptype);
                r->eat($1);
                r->eat($3);
                $$ = make_astnode(astnode_type::bin_op_apequ);
                $$->eat(r);
                $$->eat($5);
            }



// [7] errors

ast_error :
          t_error { GEN_ERROR_NODE("t_error (for ast_error)", $$, $1); }
        // | t_newline { GEN_ERROR_NODE("t_newline (for ast_error)", $$, $1); }
        // | t_indent { GEN_ERROR_NODE("t_indent (for ast_error)", $$, $1); }
        // | t_dedent { GEN_ERROR_NODE("t_dedent (for ast_error)", $$, $1); }
        // | t_identifier { GEN_ERROR_NODE("t_identifier (for ast_error)", $$, $1); }
        // | t_number { GEN_ERROR_NODE("t_number (for ast_error)", $$, $1); }
        // | t_strtext { GEN_ERROR_NODE("t_strtext (for ast_error)", $$, $1); }
        // | t_delimiter_comma { DELIMITER($$, $1); }
        // | t_delimiter_colon { DELIMITER($$, $1); }
        // | t_delimiter_arrow { DELIMITER($$, $1); }
        // | t_delimiter_semicolon { DELIMITER($$, $1); }
        // | t_delimiter_dot { DELIMITER($$, $1); }
        // | t_delimiter_3dot { DELIMITER($$, $1); }
        // | t_bracket_squotes { BRACKET($$, $1); }
        // | t_bracket_dquotes { BRACKET($$, $1); }
        // | t_bracket_parentheses_l { BRACKET($$, $1); }
        // | t_bracket_parentheses_r { BRACKET($$, $1); }
        // | t_bracket_square_l { BRACKET($$, $1); }
        // | t_bracket_square_r { BRACKET($$, $1); }
        // | t_bracket_curly_l { BRACKET($$, $1); }
        // | t_bracket_curly_r { BRACKET($$, $1); }
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
        // | t_operators_add_assign { OPERATORS($$, $1); }
        // | t_operators_sub_assign { OPERATORS($$, $1); }
        // | t_operators_mul_assign { OPERATORS($$, $1); }
        // | t_operators_div_assign { OPERATORS($$, $1); }
        // | t_operators_ediv_assign { OPERATORS($$, $1); }
        // | t_operators_mod_assign { OPERATORS($$, $1); }
        // | t_operators_pow_assign { OPERATORS($$, $1); }
        // | t_operators_at_assign { OPERATORS($$, $1); }
        // | t_operators_and_assign { OPERATORS($$, $1); }
        // | t_operators_or_assign { OPERATORS($$, $1); }
        // | t_operators_xor_assign { OPERATORS($$, $1); }
        // | t_operators_not_assign { OPERATORS($$, $1); }
        // | t_operators_sleft_assign { OPERATORS($$, $1); }
        // | t_operators_sright_assign { OPERATORS($$, $1); }
        // | t_keyword_underline { KEYWORD($$, $1); }
        // | t_keyword_None { KEYWORD($$, $1); }
        // | t_keyword_True { KEYWORD($$, $1); }
        // | t_keyword_False { KEYWORD($$, $1); }
        // | t_keyword_and { KEYWORD($$, $1); }
        // | t_keyword_or { KEYWORD($$, $1); }
        // | t_keyword_not { KEYWORD($$, $1); }
        // | t_keyword_is { KEYWORD($$, $1); }
        // | t_keyword_in { KEYWORD($$, $1); }
        // | t_keyword_pass { KEYWORD($$, $1); }
        // | t_keyword_def { KEYWORD($$, $1); }
        // | t_keyword_return { KEYWORD($$, $1); }
        // | t_keyword_yield { KEYWORD($$, $1); }
        // | t_keyword_class { KEYWORD($$, $1); }
        | t_keyword_lambda { KEYWORD($$, $1); }
        // | t_keyword_await { KEYWORD($$, $1); }
        // | t_keyword_if { KEYWORD($$, $1); }
        // | t_keyword_else { KEYWORD($$, $1); }
        // | t_keyword_elif { KEYWORD($$, $1); }
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
    stdlog::log << stdlog::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << stdlog::endl;
}
