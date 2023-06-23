#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <vector>

#include "timing.h"
#include "log.h"
#include "lexer.h"

extern FILE* yyin;



// --- 2 ---
// type to_string

// Types can only be:
//   [1] operator types:
//     zero_op_...
//     sin_op_... (including: comp_op_...)
//     bin_op_...
//     tri_op_..., qua_op_..., ...
//     list_op_... (including: statements, expressions)
//  [2] substance types:
//     error (with token leaf)
//     atom (with token leaf)
//     placeholder (no token leaf)
enum class astnode_type {

// substance types

    error,  // with token_leaf
    atom,  // with token_leaf
    placeholder,  // empty

// temp

    temp,  // may use in the generation of ast, but must be changed or deleted at last

// operator types

    statements,  // list_op_statements

    tri_op_assign,  // type, lhs, rhs
    tri_op_augassign,  // operator, lhs, rhs

    zero_op_pass,
    zero_op_break,
    zero_op_continue,
    sin_op_return,

    qua_op_class_block,  // name, base classes, block, decorators
    pen_op_function_block,  // name, params, return type, block, decorators
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
    comp_op_eq, comp_op_neq, comp_op_leq, comp_op_lt, comp_op_geq,
    comp_op_gt, comp_op_notin, comp_op_in, comp_op_isnot, comp_op_is,

    bin_op_or, bin_op_xor, bin_op_and, bin_op_sleft, bin_op_sright,
    bin_op_add, bin_op_sub,
    bin_op_mul, bin_op_div, bin_op_ediv, bin_op_mod, bin_op_at,
    sin_op_positive, sin_op_negative, sin_op_wavenot,
    bin_op_power,

    sin_op_await,
    bin_op_dot,
    bin_op_fcall,

    list_op_slices,
    list_op_strings,
    list_op_args_or_prams,

    bin_op_aptype,
    sin_op_apstar,
    sin_op_apdstar, 
    bin_op_apequ, 
};

std::string to_string(astnode_type a);



// --- 3 ---
// class (include class to_string)

struct Attribute {
    bool is_await = false;

    Attribute();
    ~Attribute();
};

struct AstNode {
    astnode_type type;
    AstNode* parent;
    std::vector<AstNode*> sons;

    bool is_empty;

    // made from token, expression (single)
    bool is_token_leaf;
    Token token_leaf;

    Attribute attribute;

    AstNode();
    ~AstNode();

    AstNode* eat(AstNode* son);
    AstNode* eat_sons(AstNode* old_mother);

    std::string to_string();
};

int yyparse(AstNode*& ast_head);


// --- 1 ---
// buff and make

// 所有权 (unique_ptr) 在这个 vector 里，其他函数只能获得 AstNode*，即 AstNode 的读写权限，并非所有权。
extern std::vector<std::unique_ptr<AstNode>> astnode_buff;
AstNode* make_astnode(astnode_type type = astnode_type::error);
AstNode* make_empty_astnode();
AstNode* make_astnode_from_token(const Token& token, astnode_type type = astnode_type::error);
AstNode* make_astnode_from_token(Token* token, astnode_type type = astnode_type::error);
void remove_from_astnode_buff(AstNode*& del);



// --- 4 ---
// head log show

void log_ast(AstNode* head);
