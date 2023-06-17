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
        case astnode_type::temp: return "temp";
        case astnode_type::placeholder: return "placeholder";
        
        case astnode_type::statements: return "statements";

        case astnode_type::assignment: return "assignment";
        case astnode_type::pass_stmt: return "pass_stmt";
        case astnode_type::break_stmt: return "break_stmt";
        case astnode_type::continue_stmt: return "continue_stmt";
        
        case astnode_type::expression_type: return "expression_type";
        case astnode_type::expressions_lhs: return "expressions_lhs";
        case astnode_type::expression_lhs: return "expression_lhs";
        case astnode_type::primary_lhs: return "primary_lhs";

        case astnode_type::expressions: return "expressions";
        case astnode_type::expression: return "expression";
        case astnode_type::yield_expr: return "yield_expr"; 
        case astnode_type::star_expressions: return "star_expressions";
        case astnode_type::star_expression: return "star_expression";
        case astnode_type::star_named_expressions: return "star_named_expressions";
        case astnode_type::star_named_expression: return "star_named_expression";
        case astnode_type::assignment_expression: return "assignment_expression";
        case astnode_type::named_expression: return "named_expression";
        case astnode_type::disjunction: return "disjunction";
        case astnode_type::conjunction: return "conjunction";
        case astnode_type::inversion: return "inversion";
        case astnode_type::comparison: return "comparison";
        case astnode_type::compare_op_bitwise_or_pair: return "compare_op_bitwise_or_pair";
        case astnode_type::eq_bitwise_or: return "eq_bitwise_or";
        case astnode_type::noteq_bitwise_or: return "noteq_bitwise_or";
        case astnode_type::lte_bitwise_or: return "lte_bitwise_or";
        case astnode_type::lt_bitwise_or: return "lt_bitwise_or";
        case astnode_type::gte_bitwise_or: return "gte_bitwise_or";
        case astnode_type::gt_bitwise_or: return "gt_bitwise_or";
        case astnode_type::notin_bitwise_or: return "notin_bitwise_or";
        case astnode_type::in_bitwise_or: return "in_bitwise_or";
        case astnode_type::isnot_bitwise_or: return "isnot_bitwise_or";
        case astnode_type::is_bitwise_or: return "is_bitwise_or";
        case astnode_type::bitwise_or: return "bitwise_or";
        case astnode_type::bitwise_xor: return "bitwise_xor";
        case astnode_type::bitwise_and: return "bitwise_and";
        case astnode_type::shift_left: return "shift_left";
        case astnode_type::shift_right: return "shift_right";
        case astnode_type::sum_add: return "sum_add";
        case astnode_type::sum_sub: return "sum_sub";
        case astnode_type::term_mul: return "term_mul";
        case astnode_type::term_div: return "term_div";
        case astnode_type::term_ediv: return "term_ediv";
        case astnode_type::term_mod: return "term_mod";
        case astnode_type::term_at: return "term_at";
        case astnode_type::factor_positive: return "factor_positive";
        case astnode_type::factor_negative: return "factor_negative";
        case astnode_type::factor_not: return "factor_not";
        case astnode_type::power: return "power";
        case astnode_type::await_primary: return "await_primary";
        case astnode_type::primary: return "primary";

        case astnode_type::sign_annotate: return "sign_annotate";
        case astnode_type::atom: return "atom";

        case astnode_type::slices: return "slices";
        case astnode_type::slice: return "slice";
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
    old_mother->sons = decltype(old_mother->sons)();  // free the capacity
    return this;
}

std::string AstNode::to_string() {
    if (this->is_empty)
        return std::to_string(this->type) + ", empty";
    else if (this->is_token_leaf)
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
    if (parent == nullptr) return;
    log_ast_data(parent, depth);
    for (auto i : parent->sons) {
        log_ast_inside(i, depth + 1);
    }
}

void log_ast(AstNode* head) {
    log_ast_inside(head, 0);
}