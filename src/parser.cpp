#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <cassert>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"



// --- 1 ---
// buff and make

namespace _buff {
    // 所有权 (unique_ptr) 在这个 vector 里，其他函数只能获得 AstNode*，即 AstNode 的读写权限，并非所有权。
    std::vector<std::unique_ptr<AstNode>> astnode_buff;
}

AstNode* make_empty_astnode() {
    _buff::astnode_buff.push_back(std::make_unique<AstNode>());
    auto res = _buff::astnode_buff.back().get();
    return res;
}

AstNode* make_astnode(astnode_type type) {
    _buff::astnode_buff.push_back(std::make_unique<AstNode>(type));
    auto res = _buff::astnode_buff.back().get();
    return res;
}

AstNode* make_astnode_from_token(Token* token, astnode_type type) {
    _buff::astnode_buff.push_back(std::make_unique<AstNode>(token, type));
    auto res = _buff::astnode_buff.back().get();
    return res;
}

void remove_from_astnode_buff(AstNode*& del) {
    for (auto i = _buff::astnode_buff.begin(); i != _buff::astnode_buff.end(); ++i) {
        if (i->get() == del) {
            _buff::astnode_buff.erase(i);
            break;
        }
    }
    del = nullptr;
}



// --- 2 ---
// type to_string

std::string to_string(astnode_type a) {
    switch (a) {
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
        case astnode_type::bin_op_index: return "bin_op_index";

        case astnode_type::list_mayempty_op_list: return "list_mayempty_op_list";
        case astnode_type::list_mayempty_op_tuple: return "list_mayempty_op_tuple";
        case astnode_type::list_mayempty_op_set: return "list_mayempty_op_set";
        case astnode_type::list_mayempty_op_dict: return "list_mayempty_op_dict";

        case astnode_type::tri_op_slice: return "tri_op_slice";
        case astnode_type::list_op_strings: return "list_op_strings";
        case astnode_type::list_op_args_or_prams: return "list_op_args_or_prams";

        case astnode_type::bin_op_aptype: return "bin_op_aptype";
        case astnode_type::sin_op_apstar: return "sin_op_apstar";
        case astnode_type::sin_op_apdstar: return "sin_op_apdstar"; 
        case astnode_type::bin_op_apequ: return "bin_op_apequ";
    }
    return "<enum to_string error>";
}



// --- 3 ---
// class (include class to_string)

AstNode::AstNode() {
    this->type = astnode_type::placeholder;
    this->is_token_leaf = false;
    this->is_symbol_built = false;
}

AstNode::AstNode(astnode_type type) {
    this->type = type;
    this->is_token_leaf = false;
    this->is_symbol_built = false;
}

AstNode::AstNode(Token* token, astnode_type type) {
    this->type = type;
    this->is_token_leaf = true;
    this->token_leaf = token;
    this->is_symbol_built = false;
}

// <son> cannot be `nullptr`
AstNode* AstNode::eat(AstNode* son) {
    this->sons.push_back(son);
    son->parent = this;
    return this;
}

// <old_mother> cannot be `nullptr`, but can be empty (no sons)
AstNode* AstNode::eat_sons(AstNode* old_mother) {
    for (auto i : old_mother->sons) {
        this->sons.push_back(i);
        i->parent = this;
    }
    old_mother->sons.clear();
    old_mother->sons = decltype(old_mother->sons)();  // free the capacity
    return this;
}

// do not use it with/contains `placeholder` and `zero_op_...`, or it will `assert(false)`
Token* AstNode::first_token() {
    if (is_token_leaf) return token_leaf;
    if (sons.empty()) {
        assert((false && "use AstNode::first_token() with no token as the leaf! (maybe: placeholder, zero_op_... or just error)"));
        return nullptr;
    }
    return sons[0]->first_token();
}

std::string AstNode::to_string() const {
    if (this->is_token_leaf)
        return ::to_string(this->type) + " >> " + this->token_leaf->to_string();
    else
        return ::to_string(this->type) + " | OT";
}



// --- 4 ---
// head log show

void log_ast_data(AstNode* astnode, int depth) {
    stdlog::log << stdlog::info;
    for (int i = 0; i < depth; ++i) {
        stdlog::log << "  ";
    }
    stdlog::log << "(" << std::to_string(depth) << ") ";
    stdlog::log << astnode->to_string() << stdlog::endl;
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