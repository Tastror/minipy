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

AstNode* make_astnode(astnode_type type) {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->type = type;
    res->is_token_leaf = false;
    return res;
}

AstNode* make_astnode_from_token(Token token, astnode_type type) {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->type = type;
    res->is_token_leaf = true;
    res->token_leaf = token;
    return res;
}

AstNode* make_astnode_from_token(Token* token, astnode_type type) {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->type = type;
    res->is_token_leaf = true;
    res->token_leaf = *token;
    return res;
}

void remove_from_astnode_buff(AstNode*& del) {
    for (auto i = astnode_buff.begin(); i != astnode_buff.end(); ++i) {
        if (i->get() == del) {
            astnode_buff.erase(i);
            break;
        }
    }
    del = nullptr;
}



// --- 2 ---
// type to_string

std::string std::to_string(astnode_type tt) {
    switch (tt) {
        case astnode_type::error: return "error";
        case astnode_type::placeholder: return "placeholder";
        case astnode_type::statements: return "statements";

        case astnode_type::assignment: return "assignment";
        case astnode_type::pass_stmt: return "pass_stmt";
        case astnode_type::break_stmt: return "break_stmt";
        case astnode_type::continue_stmt: return "continue_stmt";
        
        case astnode_type::power: return "power";
        case astnode_type::primary: return "primary";
        case astnode_type::primary_attr: return "primary_attr";
        case astnode_type::primary_call: return "primary_call";
        case astnode_type::primary_index: return "primary_index";

        case astnode_type::slices: return "slices";
        case astnode_type::slice: return "slice";
        case astnode_type::atom: return "atom";
        case astnode_type::group: return "group";
    }
    return "";
}



// --- 3 ---
// class (include class to_string)

Attribute::Attribute() {}
Attribute::~Attribute() {}

AstNode::AstNode() {}
AstNode::~AstNode() {}

AstNode* AstNode::eat(AstNode* son) {
    this->sons.push_back(son);
    son->parent = this;
    return this;
}

AstNode* AstNode::eat_sons(AstNode* old_mother) {
    for (auto i : old_mother->sons) {
        this->sons.push_back(i);
        i->parent = this;
    }
    old_mother->sons.clear();
    return this;
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
    Logger << Log::info;
    for (int i = 0; i < depth; ++i) {
        Logger << "  ";
    }
    Logger << "(" << std::to_string(depth) << ") ";
    Logger << astnode->to_string() << Log::endl;
}

void log_ast_inside(AstNode* parent, int depth) {
    log_ast_data(parent, depth);
    for (auto i : parent->sons) {
        log_ast_inside(i, depth + 1);
    }
}

void log_ast(AstNode* head) {
    log_ast_inside(head, 0);
}