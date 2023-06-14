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
    error, placeholder, file,

    statements, statement,

    simple_stmts, simple_stmt,

    slice, atom, group,
};

namespace std {
    std::string to_string(astnode_type tt);
}



// --- 3 ---
// class (include class to_string)

struct AstNode {
    astnode_type type;
    AstNode* parent;
    std::vector<AstNode*> sons;

    // made from token, expression (single)
    bool is_token_leaf;
    Token token_leaf;

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
AstNode* make_astnode_from_token(Token token, astnode_type type = astnode_type::error);
AstNode* make_astnode_from_token(Token* token, astnode_type type = astnode_type::error);
void remove_from_astnode_buff(AstNode*& del);



// --- 4 ---
// head log show

void log_ast(AstNode* head);
