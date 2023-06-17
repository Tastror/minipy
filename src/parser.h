#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <vector>

#include "common.h"
#include "lexer.h"

extern FILE* yyin;



// --- 2 ---
// type to_string

enum class astnode_type {
    error,          // error, no son (token_leaf)
    temp,           // may use in the generation of ast, but will change or delete at last
    placeholder,    // empty, no son (if had, must be error)
    
    statements,     // sons: (ast_error | assignment | xxx_stmt | ...) * n

    assignment,     // sons: lhs, type, rhs
    pass_stmt,      // no son (token_leaf)
    break_stmt,     // no son (token_leaf)
    continue_stmt,  // no son (token_leaf)

    expressions_type,   // same as primary_lhs
    expressions_lhs,    // sons: (expression_lhs) * n
    stars_lhs,
    star_lhs,
    primary_lhs,        // sons: (1) atom, (2) atom sign_annotate ...
    expressions_rhs,

    expressions,    // sons: (expression) * n
    expression_if_else,

    yield_expr,         // 1 son
    yield_from_expr,    // 1 son
    star_expressions,   // >= 1 son
    star_expression,    // 1 son
    // star_named_expressions,
    // star_named_expression,
    // assignment_expression,
    // named_expression,
    disjunction,    // >= 2 sons
    conjunction,    // >= 2 sons
    inversion,      // 1 son
    comparison,     // sons: bitwise_or, (compare_op_bitwise_or_pair) * n
    eq_bitwise_or, neq_bitwise_or, leq_bitwise_or, lt_bitwise_or, geq_bitwise_or,       // 1 son
    gt_bitwise_or, notin_bitwise_or, in_bitwise_or, isnot_bitwise_or, is_bitwise_or,    // 1 son
    bitwise_or,     // 2 sons
    bitwise_xor,    // 2 sons
    bitwise_and,    // 2 sons
    shift_left, shift_right,    // 2 sons
    sum_add, sum_sub,           // 2 sons
    term_mul, term_div, term_ediv, term_mod, term_at,   // 2 sons
    factor_positive, factor_negative, factor_not,       // 1 son
    power,          // 2 sons
    await_primary,  // 1 son
    primary,        // sons: (1) atom, (2) atom sign_annotate ...
    atom,           // no son (token_leaf)

    slices,
    slice,
    strings,    // sons: (string_text) * n
    string_text,    // no son (token_leaf)

    sign_annotate,  // no son (token_leaf), use in primary, todo: change to primary_dot, primary_xxx, ...
};

namespace std {
    std::string to_string(astnode_type tt);
}



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
AstNode* make_astnode_from_token(Token token, astnode_type type = astnode_type::error);
AstNode* make_astnode_from_token(Token* token, astnode_type type = astnode_type::error);
void remove_from_astnode_buff(AstNode*& del);



// --- 4 ---
// head log show

void log_ast(AstNode* head);
