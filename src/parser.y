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
%type <astnode_ptr> compound_stmt

%type <astnode_ptr> assignment
%type <astnode_ptr> annotated_rhs
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

%type <astnode_ptr> expressions
%type <astnode_ptr> expression
%type <astnode_ptr> yield_expr
%type <astnode_ptr> star_expressions
%type <astnode_ptr> star_expression
%type <astnode_ptr> star_named_expressions
%type <astnode_ptr> star_named_expression
%type <astnode_ptr> assignment_expression
%type <astnode_ptr> named_expression
%type <astnode_ptr> disjunction
%type <astnode_ptr> conjunction
%type <astnode_ptr> inversion
%type <astnode_ptr> comparison
%type <astnode_ptr> compare_op_bitwise_or_pair
%type <astnode_ptr> eq_bitwise_or
%type <astnode_ptr> noteq_bitwise_or
%type <astnode_ptr> lte_bitwise_or
%type <astnode_ptr> lt_bitwise_or
%type <astnode_ptr> gte_bitwise_or
%type <astnode_ptr> gt_bitwise_or
%type <astnode_ptr> notin_bitwise_or
%type <astnode_ptr> in_bitwise_or
%type <astnode_ptr> isnot_bitwise_or
%type <astnode_ptr> is_bitwise_or
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
%type <astnode_ptr> slices
%type <astnode_ptr> slice
%type <astnode_ptr> _part_fo_slice
%type <astnode_ptr> atom
%type <astnode_ptr> group

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

%type <astnode_ptr> strings
%type <astnode_ptr> list
%type <astnode_ptr> tuple
%type <astnode_ptr> set
%type <astnode_ptr> dict
%type <astnode_ptr> double_starred_kvpairs
%type <astnode_ptr> double_starred_kvpair
%type <astnode_ptr> kvpair

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

%type <astnode_ptr> star_targets
%type <astnode_ptr> star_targets_list_seq
%type <astnode_ptr> star_targets_tuple_seq
%type <astnode_ptr> star_target
%type <astnode_ptr> target_with_star_atom
%type <astnode_ptr> star_atom
%type <astnode_ptr> single_target
%type <astnode_ptr> single_subscript_attribute_target
%type <astnode_ptr> ast_primary
%type <astnode_ptr> ast_lookahead

%type <astnode_ptr> del_targets
%type <astnode_ptr> del_target
%type <astnode_ptr> del_t_atom
%type <astnode_ptr> type_expressions
%type <astnode_ptr> func_type_comment

%%

file : statements
            {
                ast_head = make_astnode(astnode_type::file);
                ast_head->eat($1);
            }

statements : statement
            {
                $$ = make_astnode(astnode_type::statements);
                $$->eat($1);
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
                $$ = make_astnode(astnode_type::placeholder);
                $$->eat($1);
            }
        | _no_newline_simple_stmt t_delimiter_semicolon simple_stmt
            {
                $$ = $1;
                $$->eat($3);
            }

simple_stmt : t_keyword_pass
            {
                LOG_ASTNODE("t_keyword_pass (for simple_stmt)");
                $$ = make_astnode_from_token($1, astnode_type::simple_stmt);
            }
        | t_keyword_break
            {
                LOG_ASTNODE("t_keyword_break (for simple_stmt)");
                $$ = make_astnode_from_token($1, astnode_type::simple_stmt);
            }
        | t_keyword_continue
            {
                LOG_ASTNODE("t_keyword_continue (for simple_stmt)");
                $$ = make_astnode_from_token($1, astnode_type::simple_stmt);
            }

// # NOTE: assignment MUST precede expression, else parsing a simple assignment
// # will throw a SyntaxError.
// simple_stmt:
//     | assignment
//     | star_expressions 
//     | return_stmt
//     | import_stmt
//     | raise_stmt
//     | 'pass' 
//     | del_stmt
//     | yield_stmt
//     | assert_stmt
//     | 'break' 
//     | 'continue' 
//     | global_stmt
//     | nonlocal_stmt

// compound_stmt:
//     | function_def
//     | if_stmt
//     | class_def
//     | with_stmt
//     | for_stmt
//     | try_stmt
//     | while_stmt
//     | match_stmt

// # SIMPLE STATEMENTS
// # =================

// # NOTE: annotated_rhs may start with 'yield'; yield_expr must start with 'yield'
// assignment:
//     | NAME ':' expression ['=' annotated_rhs ] 
//     | ('(' single_target ')' 
//         | single_subscript_attribute_target) ':' expression ['=' annotated_rhs ] 
//     | (star_targets '=' )+ (yield_expr | star_expressions) !'=' [TYPE_COMMENT] 
//     | single_target augassign ~ (yield_expr | star_expressions) 

// annotated_rhs: yield_expr | star_expressions

// augassign:
//     | '+=' 
//     | '-=' 
//     | '*=' 
//     | '@=' 
//     | '/=' 
//     | '%=' 
//     | '&=' 
//     | '|=' 
//     | '^=' 
//     | '<<=' 
//     | '>>=' 
//     | '**=' 
//     | '//=' 

// return_stmt:
//     | 'return' [star_expressions] 

// raise_stmt:
//     | 'raise' expression ['from' expression ] 
//     | 'raise' 

// global_stmt: 'global' ','.NAME+ 

// nonlocal_stmt: 'nonlocal' ','.NAME+ 

// del_stmt:
//     | 'del' del_targets &(';' | NEWLINE) 

// yield_stmt: yield_expr 

// assert_stmt: 'assert' expression [',' expression ] 

// import_stmt: import_name | import_from

// # Import statements
// # -----------------

// import_name: 'import' dotted_as_names 
// # note below: the ('.' | '...') is necessary because '...' is tokenized as ELLIPSIS
// import_from:
//     | 'from' ('.' | '...')* dotted_name 'import' import_from_targets 
//     | 'from' ('.' | '...')+ 'import' import_from_targets 
// import_from_targets:
//     | '(' import_from_as_names [','] ')' 
//     | import_from_as_names !','
//     | '*' 
// import_from_as_names:
//     | ','.import_from_as_name+ 
// import_from_as_name:
//     | NAME ['as' NAME ] 
// dotted_as_names:
//     | ','.dotted_as_name+ 
// dotted_as_name:
//     | dotted_name ['as' NAME ] 
// dotted_name:
//     | dotted_name '.' NAME 
//     | NAME

// # COMPOUND STATEMENTS
// # ===================

// # Common elements
// # ---------------

// block:
//     | NEWLINE INDENT statements DEDENT 
//     | simple_stmts

// decorators: ('@' named_expression NEWLINE )+ 

// # Class definitions
// # -----------------

// class_def:
//     | decorators class_def_raw 
//     | class_def_raw

// class_def_raw:
//     | 'class' NAME ['(' [arguments] ')' ] ':' block 

// # Function definitions
// # --------------------

// function_def:
//     | decorators function_def_raw 
//     | function_def_raw

// function_def_raw:
//     | 'def' NAME '(' [params] ')' ['->' expression ] ':' [func_type_comment] block 
//     | ASYNC 'def' NAME '(' [params] ')' ['->' expression ] ':' [func_type_comment] block 

// # Function parameters
// # -------------------

// params:
//     | parameters

// parameters:
//     | slash_no_default param_no_default* param_with_default* [star_etc] 
//     | slash_with_default param_with_default* [star_etc] 
//     | param_no_default+ param_with_default* [star_etc] 
//     | param_with_default+ [star_etc] 
//     | star_etc 

// # Some duplication here because we can't write (',' | &')'),
// # which is because we don't support empty alternatives (yet).

// slash_no_default:
//     | param_no_default+ '/' ',' 
//     | param_no_default+ '/' &')' 
// slash_with_default:
//     | param_no_default* param_with_default+ '/' ',' 
//     | param_no_default* param_with_default+ '/' &')' 

// star_etc:
//     | '*' param_no_default param_maybe_default* [kwds] 
//     | '*' param_no_default_star_annotation param_maybe_default* [kwds] 
//     | '*' ',' param_maybe_default+ [kwds] 
//     | kwds 

// kwds:
//     | '**' param_no_default 

// # One parameter.  This *includes* a following comma and type comment.
// #
// # There are three styles:
// # - No default
// # - With default
// # - Maybe with default
// #
// # There are two alternative forms of each, to deal with type comments:
// # - Ends in a comma followed by an optional type comment
// # - No comma, optional type comment, must be followed by close paren
// # The latter form is for a final parameter without trailing comma.
// #

// param_no_default:
//     | param ',' TYPE_COMMENT? 
//     | param TYPE_COMMENT? &')' 
// param_no_default_star_annotation:
//     | param_star_annotation ',' TYPE_COMMENT? 
//     | param_star_annotation TYPE_COMMENT? &')' 
// param_with_default:
//     | param default ',' TYPE_COMMENT? 
//     | param default TYPE_COMMENT? &')' 
// param_maybe_default:
//     | param default? ',' TYPE_COMMENT? 
//     | param default? TYPE_COMMENT? &')' 
// param: NAME annotation? 
// param_star_annotation: NAME star_annotation 
// annotation: ':' expression 
// star_annotation: ':' star_expression 
// default: '=' expression  | invalid_default

// # If statement
// # ------------

// if_stmt:
//     | 'if' named_expression ':' block elif_stmt 
//     | 'if' named_expression ':' block [else_block] 
// elif_stmt:
//     | 'elif' named_expression ':' block elif_stmt 
//     | 'elif' named_expression ':' block [else_block] 
// else_block:
//     | 'else' ':' block 

// # While statement
// # ---------------

// while_stmt:
//     | 'while' named_expression ':' block [else_block] 

// # For statement
// # -------------

// for_stmt:
//     | 'for' star_targets 'in' ~ star_expressions ':' [TYPE_COMMENT] block [else_block] 
//     | ASYNC 'for' star_targets 'in' ~ star_expressions ':' [TYPE_COMMENT] block [else_block] 

// # With statement
// # --------------

// with_stmt:
//     | 'with' '(' ','.with_item+ ','? ')' ':' block 
//     | 'with' ','.with_item+ ':' [TYPE_COMMENT] block 
//     | ASYNC 'with' '(' ','.with_item+ ','? ')' ':' block 
//     | ASYNC 'with' ','.with_item+ ':' [TYPE_COMMENT] block 

// with_item:
//     | expression 'as' star_target &(',' | ')' | ':') 
//     | expression 

// # Try statement
// # -------------

// try_stmt:
//     | 'try' ':' block finally_block 
//     | 'try' ':' block except_block+ [else_block] [finally_block] 
//     | 'try' ':' block except_star_block+ [else_block] [finally_block] 


// # Except statement
// # ----------------

// except_block:
//     | 'except' expression ['as' NAME ] ':' block 
//     | 'except' ':' block 
// except_star_block:
//     | 'except' '*' expression ['as' NAME ] ':' block 
// finally_block:
//     | 'finally' ':' block 

// # Match statement
// # ---------------

// match_stmt:
//     | "match" subject_expr ':' NEWLINE INDENT case_block+ DEDENT 

// subject_expr:
//     | star_named_expression ',' star_named_expressions? 
//     | named_expression

// case_block:
//     | "case" patterns guard? ':' block 

// guard: 'if' named_expression 

// patterns:
//     | open_sequence_pattern 
//     | pattern

// pattern:
//     | as_pattern
//     | or_pattern

// as_pattern:
//     | or_pattern 'as' pattern_capture_target 

// or_pattern:
//     | '|'.closed_pattern+ 

// closed_pattern:
//     | literal_pattern
//     | capture_pattern
//     | wildcard_pattern
//     | value_pattern
//     | group_pattern
//     | sequence_pattern
//     | mapping_pattern
//     | class_pattern

// # Literal patterns are used for equality and identity constraints
// literal_pattern:
//     | signed_number !('+' | '-') 
//     | complex_number 
//     | strings 
//     | 'None' 
//     | 'True' 
//     | 'False' 

// # Literal expressions are used to restrict permitted mapping pattern keys
// literal_expr:
//     | signed_number !('+' | '-')
//     | complex_number
//     | strings
//     | 'None' 
//     | 'True' 
//     | 'False' 

// complex_number:
//     | signed_real_number '+' imaginary_number 
//     | signed_real_number '-' imaginary_number  

// signed_number:
//     | NUMBER
//     | '-' NUMBER 

// signed_real_number:
//     | real_number
//     | '-' real_number 

// real_number:
//     | NUMBER 

// imaginary_number:
//     | NUMBER 

// capture_pattern:
//     | pattern_capture_target 

// pattern_capture_target:
//     | !"_" NAME !('.' | '(' | '=') 

// wildcard_pattern:
//     | "_" 

// value_pattern:
//     | attr !('.' | '(' | '=') 

// attr:
//     | name_or_attr '.' NAME 

// name_or_attr:
//     | attr
//     | NAME

// group_pattern:
//     | '(' pattern ')' 

// sequence_pattern:
//     | '[' maybe_sequence_pattern? ']' 
//     | '(' open_sequence_pattern? ')' 

// open_sequence_pattern:
//     | maybe_star_pattern ',' maybe_sequence_pattern? 

// maybe_sequence_pattern:
//     | ','.maybe_star_pattern+ ','? 

// maybe_star_pattern:
//     | star_pattern
//     | pattern

// star_pattern:
//     | '*' pattern_capture_target 
//     | '*' wildcard_pattern 

// mapping_pattern:
//     | '{' '}' 
//     | '{' double_star_pattern ','? '}' 
//     | '{' items_pattern ',' double_star_pattern ','? '}' 
//     | '{' items_pattern ','? '}' 

// items_pattern:
//     | ','.key_value_pattern+

// key_value_pattern:
//     | (literal_expr | attr) ':' pattern 

// double_star_pattern:
//     | '**' pattern_capture_target 

// class_pattern:
//     | name_or_attr '(' ')' 
//     | name_or_attr '(' positional_patterns ','? ')' 
//     | name_or_attr '(' keyword_patterns ','? ')' 
//     | name_or_attr '(' positional_patterns ',' keyword_patterns ','? ')' 

// positional_patterns:
//     | ','.pattern+ 

// keyword_patterns:
//     | ','.keyword_pattern+

// keyword_pattern:
//     | NAME '=' pattern 

// expressions:
//     | expression (',' expression )+ [','] 
//     | expression ',' 
//     | expression

// expression:
//     | disjunction 'if' disjunction 'else' expression 
//     | disjunction
//     | lambdef

// yield_expr:
//     | 'yield' 'from' expression 
//     | 'yield' [star_expressions] 

// star_expressions:
//     | star_expression (',' star_expression )+ [','] 
//     | star_expression ',' 
//     | star_expression

// star_expression:
//     | '*' bitwise_or 
//     | expression

// star_named_expressions: ','.star_named_expression+ [','] 

// star_named_expression:
//     | '*' bitwise_or 
//     | named_expression

// assignment_expression:
//     | NAME '=' expression 

// named_expression:
//     | assignment_expression
//     | expression !'='

// disjunction:
//     | conjunction ('or' conjunction )+ 
//     | conjunction

// conjunction:
//     | inversion ('and' inversion )+ 
//     | inversion

// inversion:
//     | 'not' inversion 
//     | comparison

// comparison:
//     | bitwise_or compare_op_bitwise_or_pair+ 
//     | bitwise_or

// compare_op_bitwise_or_pair:
//     | eq_bitwise_or
//     | noteq_bitwise_or
//     | lte_bitwise_or
//     | lt_bitwise_or
//     | gte_bitwise_or
//     | gt_bitwise_or
//     | notin_bitwise_or
//     | in_bitwise_or
//     | isnot_bitwise_or
//     | is_bitwise_or

// eq_bitwise_or: '==' bitwise_or 
// noteq_bitwise_or:
//     | ('!=' ) bitwise_or 
// lte_bitwise_or: '<=' bitwise_or 
// lt_bitwise_or: '<' bitwise_or 
// gte_bitwise_or: '>=' bitwise_or 
// gt_bitwise_or: '>' bitwise_or 
// notin_bitwise_or: 'not' 'in' bitwise_or 
// in_bitwise_or: 'in' bitwise_or 
// isnot_bitwise_or: 'is' 'not' bitwise_or 
// is_bitwise_or: 'is' bitwise_or 

// bitwise_or: | bitwise_or '|' bitwise_xor
//             {

//             }
//         | bitwise_xor
//             {
                
//             }

// bitwise_xor:
//     | bitwise_xor '^' bitwise_and 
//     | bitwise_and

// bitwise_and:
//     | bitwise_and '&' shift_expr 
//     | shift_expr

// shift_expr:
//     | shift_expr '<<' sum 
//     | shift_expr '>>' sum 
//     | sum

// sum:
//     | sum '+' term 
//     | sum '-' term 
//     | term

// term:
//     | term '*' factor 
//     | term '/' factor 
//     | term '//' factor 
//     | term '%' factor 
//     | term '@' factor 
//     | factor

// factor:
//     | '+' factor 
//     | '-' factor 
//     | '~' factor 
//     | power

// power: | await_primary '|' factor
//             {

//             }
//         | await_primary
//             {
                
//             }

// await_primary:
//     | AWAIT primary 
//     | primary

// primary:
//     | primary '.' NAME 
//     | primary genexp 
//     | primary '(' [arguments] ')' 
//     | primary '[' slices ']' 
//     | atom

// slices:
//     | slice !',' 
//     | ','.(slice | starred_expression)+ [','] 

slice:   t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for slice)");
                auto tmp1 = make_astnode(astnode_type::placeholder);
                auto tmp2 = make_astnode(astnode_type::placeholder);
                $$ = make_astnode(astnode_type::slice);
                $$.eat(tmp1);
                $$.eat(tmp2);
            }
        | expression t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for slice)");
                auto tmp = make_astnode(astnode_type::placeholder);
                $$ = make_astnode(astnode_type::slice);
                $$.eat($1);
                $$.eat(tmp);
            }
        | t_delimiter_comma expression
            {
                LOG_ASTNODE("t_delimiter_comma (for slice)");
                auto tmp = make_astnode(astnode_type::placeholder);
                $$ = make_astnode(astnode_type::slice);
                $$.eat(tmp);
                $$.eat($2);
            }
        | expression t_delimiter_comma expression
            {
                LOG_ASTNODE("t_delimiter_comma (for slice)");
                $$ = make_astnode(astnode_type::slice);
                $$.eat($1);
                $$.eat($3);
            }
        | slice _part_fo_slice
            {
                $$ = $1;
                $$.eat_sons($2);
                remove_from_astnode_buff($2);
            }
        | named_expression
            {
                $$ = make_astnode(astnode_type::slice);
                $$.eat($1);
            }

_part_fo_slice: t_delimiter_comma expression
            {
                LOG_ASTNODE("t_delimiter_comma (for _part_fo_slice)");
                $$ = make_astnode(astnode_type::placeholder);
                $$.eat($2);
            }
        | t_delimiter_comma
            {
                LOG_ASTNODE("t_delimiter_comma (for _part_fo_slice)");
                auto tmp = make_astnode(astnode_type::placeholder);
                $$ = make_astnode(astnode_type::placeholder);
                $$.eat(tmp);
            }

atom:     t_identifier
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
        | t_number
            {
                LOG_ASTNODE("t_number (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }
        | strings
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | tuple
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | group
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | genexp
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | list
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | listcomp
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | dict
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | set
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | dictcomp
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | setcomp
            {
                $$ = make_astnode(astnode_type::atom);
                $$->eat($1);
            }
        | t_delimiter_3dot
            {
                LOG_ASTNODE("t_delimiter_3dot (for atom)");
                $$ = make_astnode_from_token($1, astnode_type::atom);
            }

group:    t_bracket_parentheses_l yield_expr t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for group)");
                LOG_ASTNODE("t_bracket_parentheses_r (for group)");
                $$ = make_astnode(astnode_type::group);
                $$->eat($2);
            }
        | t_bracket_parentheses_l named_expression t_bracket_parentheses_r
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for group)");
                LOG_ASTNODE("t_bracket_parentheses_r (for group)");
                $$ = make_astnode(astnode_type::group);
                $$->eat($2);
            }

// lambdef:
//     | 'lambda' [lambda_params] ':' expression 

// lambda_params:
//     | lambda_parameters

// lambda_parameters:
//     | lambda_slash_no_default lambda_param_no_default* lambda_param_with_default* [lambda_star_etc] 
//     | lambda_slash_with_default lambda_param_with_default* [lambda_star_etc] 
//     | lambda_param_no_default+ lambda_param_with_default* [lambda_star_etc] 
//     | lambda_param_with_default+ [lambda_star_etc] 
//     | lambda_star_etc 

// lambda_slash_no_default:
//     | lambda_param_no_default+ '/' ',' 
//     | lambda_param_no_default+ '/' &':' 

// lambda_slash_with_default:
//     | lambda_param_no_default* lambda_param_with_default+ '/' ',' 
//     | lambda_param_no_default* lambda_param_with_default+ '/' &':' 

// lambda_star_etc:
//     | '*' lambda_param_no_default lambda_param_maybe_default* [lambda_kwds] 
//     | '*' ',' lambda_param_maybe_default+ [lambda_kwds] 
//     | lambda_kwds 

// lambda_kwds:
//     | '**' lambda_param_no_default 

// lambda_param_no_default:
//     | lambda_param ',' 
//     | lambda_param &':' 
// lambda_param_with_default:
//     | lambda_param default ',' 
//     | lambda_param default &':' 
// lambda_param_maybe_default:
//     | lambda_param default? ',' 
//     | lambda_param default? &':' 
// lambda_param: NAME 

// strings: STRING+ 

// list:
//     | '[' [star_named_expressions] ']' 

// tuple:
//     | '(' [star_named_expression ',' [star_named_expressions]  ] ')' 

// set: '{' star_named_expressions '}' 

// dict:
//     | '{' [double_starred_kvpairs] '}' 

// double_starred_kvpairs: ','.double_starred_kvpair+ [','] 

// double_starred_kvpair:
//     | '**' bitwise_or 
//     | kvpair

// kvpair: expression ':' expression 

// for_if_clauses:
//     | for_if_clause+ 

// for_if_clause:
//     | ASYNC 'for' star_targets 'in' ~ disjunction ('if' disjunction )* 
//     | 'for' star_targets 'in' ~ disjunction ('if' disjunction )* 

// listcomp:
//     | '[' named_expression for_if_clauses ']' 

// setcomp:
//     | '{' named_expression for_if_clauses '}' 

// genexp:
//     | '(' ( assignment_expression | expression !':=') for_if_clauses ')' 

// dictcomp:
//     | '{' kvpair for_if_clauses '}' 

// # FUNCTION CALL ARGUMENTS
// # =======================

// arguments:
//     | args [','] &')' 

// args:
//     | ','.(starred_expression | ( assignment_expression | expression !':=') !'=')+ [',' kwargs ] 
//     | kwargs 

// kwargs:
//     | ','.kwarg_or_starred+ ',' ','.kwarg_or_double_starred+ 
//     | ','.kwarg_or_starred+
//     | ','.kwarg_or_double_starred+

// starred_expression:
//     | '*' expression 

// kwarg_or_starred:
//     | NAME '=' expression 
//     | starred_expression 

// kwarg_or_double_starred:
//     | NAME '=' expression 
//     | '**' expression 

// # ASSIGNMENT TARGETS
// # ==================

// # Generic targets
// # ---------------

// # NOTE: star_targets may contain *bitwise_or, targets may not.
// star_targets:
//     | star_target !',' 
//     | star_target (',' star_target )* [','] 

// star_targets_list_seq: ','.star_target+ [','] 

// star_targets_tuple_seq:
//     | star_target (',' star_target )+ [','] 
//     | star_target ',' 

// star_target:
//     | '*' (!'*' star_target) 
//     | target_with_star_atom

// target_with_star_atom:
//     | t_primary '.' NAME !t_lookahead 
//     | t_primary '[' slices ']' !t_lookahead 
//     | star_atom

// star_atom:
//     | NAME 
//     | '(' target_with_star_atom ')' 
//     | '(' [star_targets_tuple_seq] ')' 
//     | '[' [star_targets_list_seq] ']' 

// single_target:
//     | single_subscript_attribute_target
//     | NAME 
//     | '(' single_target ')' 

// single_subscript_attribute_target:
//     | t_primary '.' NAME !t_lookahead 
//     | t_primary '[' slices ']' !t_lookahead 

// t_primary:
//     | t_primary '.' NAME &t_lookahead 
//     | t_primary '[' slices ']' &t_lookahead 
//     | t_primary genexp &t_lookahead 
//     | t_primary '(' [arguments] ')' &t_lookahead 
//     | atom &t_lookahead 

// t_lookahead: '(' | '[' | '.'

// del_targets: ','.del_target+ [','] 

// del_target:
//     | t_primary '.' NAME !t_lookahead 
//     | t_primary '[' slices ']' !t_lookahead 
//     | del_t_atom

// del_t_atom:
//     | NAME 
//     | '(' del_target ')' 
//     | '(' [del_targets] ')' 
//     | '[' [del_targets] ']' 

// type_expressions:
//     | ','.expression+ ',' '*' expression ',' '**' expression 
//     | ','.expression+ ',' '*' expression 
//     | ','.expression+ ',' '**' expression 
//     | '*' expression ',' '**' expression 
//     | '*' expression 
//     | '**' expression 
//     | ','.expression+ 

// func_type_comment:
//     | NEWLINE TYPE_COMMENT &(NEWLINE INDENT)   # Must be followed by indented block
//     | TYPE_COMMENT

ast_error : t_error { GEN_ERROR_NODE("t_error (for ast_error)", $$, $1); }
        | t_newline { GEN_ERROR_NODE("t_newline (for ast_error)", $$, $1); }
        | t_indent { GEN_ERROR_NODE("t_indent (for ast_error)", $$, $1); }
        | t_dedent { GEN_ERROR_NODE("t_dedent (for ast_error)", $$, $1); }
        | t_identifier { GEN_ERROR_NODE("t_identifier (for ast_error)", $$, $1); }
        | t_number { GEN_ERROR_NODE("t_number (for ast_error)", $$, $1); }
        | t_strtext { GEN_ERROR_NODE("t_strtext (for ast_error)", $$, $1); }
        | t_delimiter_comma { DELIMITER($$, $1); }
        | t_delimiter_colon { DELIMITER($$, $1); }
        | t_delimiter_arrow { DELIMITER($$, $1); }
        | t_delimiter_semicolon { DELIMITER($$, $1); }
        | t_delimiter_dot { DELIMITER($$, $1); }
        | t_delimiter_3dot { DELIMITER($$, $1); }
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
        | t_keyword_pass { KEYWORD($$, $1); }
        | t_keyword_def { KEYWORD($$, $1); }
        | t_keyword_return { KEYWORD($$, $1); }
        | t_keyword_yield { KEYWORD($$, $1); }
        | t_keyword_class { KEYWORD($$, $1); }
        | t_keyword_lambda { KEYWORD($$, $1); }
        | t_keyword_if { KEYWORD($$, $1); }
        | t_keyword_else { KEYWORD($$, $1); }
        | t_keyword_elif { KEYWORD($$, $1); }
        | t_keyword_for { KEYWORD($$, $1); }
        | t_keyword_break { KEYWORD($$, $1); }
        | t_keyword_continue { KEYWORD($$, $1); }
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
