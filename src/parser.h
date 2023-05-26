#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <vector>

#include "common.h"
#include "lexer.h"

int yyparse();

enum class astnode_type {
    error, statement, simple_stmt, compound_stmt, assignment, block, expression
};

struct AstNode {
    astnode_type type;
    std::shared_ptr<AstNode> parent;
    std::vector<std::shared_ptr<AstNode>> sons;

    // made from token, expression (single)
    bool is_token_leaf;
    Token token_leaf;

    AstNode();
    ~AstNode();
};

extern std::shared_ptr<AstNode> astnode_root;

std::shared_ptr<AstNode> make_from_token(Token token);
