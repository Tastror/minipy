#include <cstdint>
#include <string>
#include <memory>
#include <vector>

#include "common.h"
#include "lexer.h"
#include "parser.h"

AstNode::AstNode() {}
AstNode::~AstNode() {}

std::vector<std::unique_ptr<AstNode>> astnode_buff;

AstNode* make_astnode() {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->is_token_leaf = false;
    return res;
}

AstNode* make_astnode_from_token(Token token) {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->is_token_leaf = true;
    res->token_leaf = token;
    return res;
}

AstNode* make_astnode_from_token(Token* token) {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->is_token_leaf = true;
    res->token_leaf = *token;
    return res;
}
