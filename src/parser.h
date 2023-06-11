#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <vector>

#include "common.h"
#include "lexer.h"

extern FILE* yyin;

enum class astnode_type {
    error, statement, simple_stmt, compound_stmt, assignment, block, expression
};

struct AstNode {
    astnode_type type;
    AstNode* parent;
    std::vector<AstNode*> sons;

    // made from token, expression (single)
    bool is_token_leaf;
    Token token_leaf;

    AstNode();
    ~AstNode();
};

// 所有权 (unique_ptr) 在这个 vector 里，其他函数只能获得 AstNode*，即 AstNode 的读写权限，并非所有权。
extern std::vector<std::unique_ptr<AstNode>> astnode_buff;
AstNode* make_astnode();
AstNode* make_astnode_from_token(Token token);
AstNode* make_astnode_from_token(Token* token);

int yyparse(AstNode* ast_head);
