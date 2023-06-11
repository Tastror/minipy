#include <cstdint>
#include <string>
#include <memory>
#include <vector>

#include "common.h"
#include "lexer.h"
#include "parser.h"
#include "log.h"



// --- 1 ---
// buff and make

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



// --- 2 ---
// type to_string

std::string std::to_string(astnode_type tt) {
    switch (tt) {
        case astnode_type::error: return "error";
        case astnode_type::file: return "file";
        case astnode_type::statement: return "statement";
        case astnode_type::simple_stmt: return "simple_stmt";
        case astnode_type::compound_stmt: return "compound_stmt";
        case astnode_type::assignment: return "assignment";
        case astnode_type::block: return "block";
        case astnode_type::expression: return "expression"; 
    }
    return "";
}



// --- 3 ---
// class (include class to_string)

AstNode::AstNode() {}
AstNode::~AstNode() {}

AstNode* AstNode::eat(AstNode* son) {
    this->sons.push_back(son);
    son->parent = this;
    return this;
}

AstNode* AstNode::give(AstNode* mother) {
    mother->sons.push_back(this);
    this->parent = mother;
    return mother;
}

std::string AstNode::to_string() {
    if (this->is_token_leaf)
        return std::to_string(this->type) + " >> " + this->token_leaf.to_string();
    else
        return std::to_string(this->type) + " | inner";
}



// --- 4 ---
// head log show

void log_ast_data(AstNode* astnode, int depth) {
    Logger << Log::std;
    for (int i = 0; i < depth; ++i) {
        Logger << " ";
    }
    Logger << astnode->to_string() << Log::endl;
}

void log_ast_inside(AstNode* parent, int depth) {
    log_ast_data(parent, depth);
    for (auto* i : parent->sons) {
        log_ast_inside(i, depth + 1);
    }
}

void log_ast(AstNode* head) {
    Logger << Log::info << "begin to print ast tree" << Log::endl;
    log_ast_inside(head, 0);
}