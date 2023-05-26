#include <cstdint>
#include <string>
#include <memory>
#include <vector>

#include "common.h"
#include "lexer.h"
#include "parser.h"

AstNode::AstNode() {}
AstNode::~AstNode() {}

std::shared_ptr<AstNode> make_from_token(Token token) {
    auto res = std::make_shared<AstNode>();
    res->is_token_leaf = true;
    res->token_leaf = token;
    return res;
}
