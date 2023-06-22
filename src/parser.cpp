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
    res->is_empty = false;
    res->is_token_leaf = false;
    return res;
}

AstNode* make_empty_astnode() {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->type = astnode_type::placeholder;
    res->is_empty = true;
    res->is_token_leaf = false;
    return res;
}

AstNode* make_astnode_from_token(Token token, astnode_type type) {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->type = type;
    res->is_empty = false;
    res->is_token_leaf = true;
    res->token_leaf = token;
    return res;
}

AstNode* make_astnode_from_token(Token* token, astnode_type type) {
    astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = astnode_buff.back().get();
    res->type = type;
    res->is_empty = false;
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
        case astnode_type::atom: return "atom";
        case astnode_type::placeholder: return "placeholder";

        case astnode_type::temp: return "temp";
        
        case astnode_type::statements: return "statements";

        case astnode_type::tri_op_assign: return "tri_op_assign";
        case astnode_type::tri_op_augassign: return "tri_op_augassign";
        case astnode_type::zero_op_pass: return "zero_op_pass";
        case astnode_type::zero_op_break: return "zero_op_break";
        case astnode_type::zero_op_continue: return "zero_op_continue";
        case astnode_type::sin_op_return: return "sin_op_return";

        case astnode_type::qua_op_class_block: return "qua_op_class_block";
        case astnode_type::pen_op_function_block: return "pen_op_function_block";
        case astnode_type::tri_op_if_else_block: return "tri_op_if_else_block";

        case astnode_type::sin_op_yield: return "sin_op_yield"; 
        case astnode_type::sin_op_yield_from: return "sin_op_yield_from"; 
        case astnode_type::expressions: return "expressions";
        case astnode_type::sin_op_star: return "sin_op_star";
        case astnode_type::tri_op_if_else_expr: return "tri_op_if_else_expr";
        case astnode_type::list_op_or: return "list_op_or";
        case astnode_type::list_op_and: return "list_op_and";
        case astnode_type::sin_op_not: return "sin_op_not";
        case astnode_type::list_op_comparison: return "list_op_comparison";
        case astnode_type::comp_op_eq: return "comp_op_eq";
        case astnode_type::comp_op_neq: return "comp_op_neq";
        case astnode_type::comp_op_leq: return "comp_op_leq";
        case astnode_type::comp_op_lt: return "comp_op_lt";
        case astnode_type::comp_op_geq: return "comp_op_geq";
        case astnode_type::comp_op_gt: return "comp_op_gt";
        case astnode_type::comp_op_notin: return "comp_op_notin";
        case astnode_type::comp_op_in: return "comp_op_in";
        case astnode_type::comp_op_isnot: return "comp_op_isnot";
        case astnode_type::comp_op_is: return "comp_op_is";
        case astnode_type::bin_op_or: return "bin_op_or";
        case astnode_type::bin_op_xor: return "bin_op_xor";
        case astnode_type::bin_op_and: return "bin_op_and";
        case astnode_type::bin_op_sleft: return "bin_op_sleft";
        case astnode_type::bin_op_sright: return "bin_op_sright";
        case astnode_type::bin_op_add: return "bin_op_add";
        case astnode_type::bin_op_sub: return "bin_op_sub";
        case astnode_type::bin_op_mul: return "bin_op_mul";
        case astnode_type::bin_op_div: return "bin_op_div";
        case astnode_type::bin_op_ediv: return "bin_op_ediv";
        case astnode_type::bin_op_mod: return "bin_op_mod";
        case astnode_type::bin_op_at: return "bin_op_at";
        case astnode_type::sin_op_positive: return "sin_op_positive";
        case astnode_type::sin_op_negative: return "sin_op_negative";
        case astnode_type::sin_op_wavenot: return "sin_op_wavenot";
        case astnode_type::bin_op_power: return "bin_op_power";
        case astnode_type::sin_op_await: return "sin_op_await";
        case astnode_type::bin_op_dot: return "bin_op_dot";
        case astnode_type::bin_op_fcall: return "bin_op_fcall";

        case astnode_type::list_op_slices: return "list_op_slices";
        case astnode_type::list_op_strings: return "list_op_strings";
        case astnode_type::list_op_args_or_prams: return "list_op_args_or_prams";

        case astnode_type::bin_op_aptype: return "bin_op_aptype";
        case astnode_type::sin_op_apstar: return "sin_op_apstar";
        case astnode_type::sin_op_apdstar: return "sin_op_apdstar"; 
        case astnode_type::bin_op_apequ: return "bin_op_apequ";
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
    old_mother->sons = decltype(old_mother->sons)();  // free the capacity
    return this;
}

std::string AstNode::to_string() {
    if (this->is_empty)
        return std::to_string(this->type) + ", empty";
    else if (this->is_token_leaf)
        return std::to_string(this->type) + " >> " + this->token_leaf.to_string();
    else
        return std::to_string(this->type) + " | OT";
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
    if (parent == nullptr) return;
    log_ast_data(parent, depth);
    for (auto i : parent->sons) {
        log_ast_inside(i, depth + 1);
    }
}

void log_ast(AstNode* head) {
    log_ast_inside(head, 0);
}