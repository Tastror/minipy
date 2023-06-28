#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <cassert>

#include "timing.h"
#include "log.h"
#include "lexer.h"

extern FILE* yyin;



// --- 2 ---
// type to_string

// Types can only be:
//   [1] operator types:
//     0: zero_op_... {empty}
//     1: sin_op_..., comp_op_...
//     2: bin_op_...
//     3,4,...: tri_op_..., qua_op_..., ...
//     >=1: list_op_... (including: statements, expressions, ...)
//     >=0: list_mayempty_op_... (including: list, tuple, ...) {may-empty}
//  [2] substance types:
//     error (with token leaf)
//     atom (with token leaf)
//     placeholder (no token leaf) {empty}
//  [3] warning: {empty} and {may-empty} have (may have) no token at the end! so be careful!
enum class astnode_type {

// substance types

    error,  // with token_leaf
    atom,  // with token_leaf
    placeholder,  // {empty}

// temp

    temp,  // may use in the generation of ast, but must be changed or deleted at last

// operator types

    statements,  // list_op_statements

    tri_op_assign,  // type_comment (fake type) (may be placeholder), lhs, rhs
    tri_op_augassign,  // operator, lhs, rhs

    zero_op_pass, // {empty}
    zero_op_break, // {empty}
    zero_op_continue,  // {empty}
    sin_op_return,  // expr (may be placeholder)

    qua_op_class_block,  // name, base classes (may be placeholder), block, decorators
    pen_op_function_block,  // name, params (may be placeholder), return type_comment (fake type) (may be placeholder), block, decorators (may be placeholder)
    tri_op_if_else_block,  // condition, if, else (else can also be if_else_block, which means elif)

    sin_op_yield,
    sin_op_yield_from,

    expressions,  // list_op_expressions

    sin_op_star,
    tri_op_if_else_expr,  // if, data1, data2

    list_op_or,
    list_op_and,
    sin_op_not,

    list_op_comparison,  // normal, comp_op_... * n
    // just name. such as [a < b] equals to [a, comp_op_lt(b)]
    comp_op_eq, comp_op_neq, comp_op_leq, comp_op_lt, comp_op_geq, comp_op_gt,
    // just name. such as [a is not b] equals to [a, comp_op_isnot(b)]
    comp_op_notin, comp_op_in, comp_op_isnot, comp_op_is,

    // expr, expr
    bin_op_or, bin_op_xor, bin_op_and, bin_op_sleft, bin_op_sright,
    // expr, expr
    bin_op_add, bin_op_sub, bin_op_mul, bin_op_div, bin_op_ediv, bin_op_mod, bin_op_at,
    sin_op_positive, sin_op_negative, sin_op_wavenot,
    // expr, expr
    bin_op_power,

    sin_op_await,
    bin_op_dot,  // name, dot_expr (may be recursive)
    bin_op_fcall,  // name, args_list (may be placeholder)
    bin_op_index,  // name, tri_op_slice or index

    list_mayempty_op_list,  // {may-empty}
    list_mayempty_op_tuple,  // {may-empty}
    list_mayempty_op_set,  // {may-empty}
    list_mayempty_op_dict,  // {may-empty}

    tri_op_slice,  // start (maybe placeholder), end (maybe placeholder), step (maybe placeholder)
    list_op_strings,
    list_op_args_or_prams,

    bin_op_aptype,  // name, type
    sin_op_apstar,  // name
    sin_op_apdstar,  // name
    bin_op_apequ,  // name, value
};

std::string to_string(astnode_type a);



// --- 3 ---
// class (include class to_string)

class AstNode {
public:
    astnode_type type;
    AstNode* parent;
    std::vector<AstNode*> sons;

    // made from token, expression (single)
    bool is_token_leaf;
    Token* token_leaf;

    // if the expression value of this node is calculated, become `true`
    // such as:
    // a = 1, the expression value of `a` is `%123` (%123 = 1);
    // c = b = a, the expression value of `b = a` is `%123` (a = %123 stores 1, b = %123 stores 1);
    // d = a + 2, the expression value of `a + 2` is `%456` (%456 stores %123 + 2, a = %123 stores 1)
    // "%123" "%456" is saved in <bound_value_name>
    // however, if the expression is not used (such as a nude `a + 2`),
    // we will not calculate the value of `a + 2`, and this will still be `false`.
    // another thing is that if you want to find the type and value of "%123" "%456"
    // please search it in `SymbolTable` and get its `SymbolType`
    // such as:
    // %123 -> int valued 1
    // %456 -> int (not valued)
    // also the `a`, `b`, `c` itself will update in SymbolTable too,
    // but will only assigned as
    // %a -> alias to %123, %d -> alias to %456
    // an execption of this is function parameters, it will be as
    // %param -> any (not an alias to anything)
    bool is_expression_built;
    // see <is_expression_built>
    std::string bound_value_name;

    AstNode();
    AstNode(astnode_type type);
    AstNode(Token* token, astnode_type type);

    AstNode* eat(AstNode* son);
    AstNode* eat_sons(AstNode* old_mother);

    Token* first_token();

    std::string to_string() const;
};

int yyparse(AstNode*& ast_head);


// --- 1 ---
// buff and make

AstNode* make_empty_astnode();
AstNode* make_astnode(astnode_type type = astnode_type::error);
AstNode* make_astnode_from_token(Token* token, astnode_type type = astnode_type::error);
void delete_astnode(AstNode*& del);



// --- 4 ---
// head log show

void log_ast(AstNode* head);
