#include <vector>
#include <string>
#include <memory>
#include <cassert>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"
#include "ir.h"

RegisterManager::RegisterManager() : RegisterManager(false) {}

RegisterManager::RegisterManager(bool is_global): is_global(is_global) {
    id = 0;
}

void RegisterManager::next() {
    id++;
}

int RegisterManager::get_int() {
    return id;
}

int RegisterManager::get_int_and_next() {
    return ++id;
}

std::string RegisterManager::get_str() {
    if (is_global)
        return "@" + std::to_string(id);
    else
        return "%" + std::to_string(id);
}

std::string RegisterManager::get_str_and_next() {
    if (is_global)
        return "@" + std::to_string(++id);
    else
        return "%" + std::to_string(++id);
}

std::string to_string(ir_data_type a) {
    switch (a) {
    case ir_data_type::error: return "error";
    case ir_data_type::any: return "any";
    case ir_data_type::instant: return "instant";
    case ir_data_type::label: return "label";
    case ir_data_type::voids: return "void";
    case ir_data_type::i1: return "i1";
    case ir_data_type::i32: return "i32";
    case ir_data_type::i64: return "i64";
    case ir_data_type::floats: return "float";
    case ir_data_type::doubles: return "double";
    case ir_data_type::i1_p: return "i1*";
    case ir_data_type::i32_p: return "i32*";
    case ir_data_type::i64_p: return "i64*";
    case ir_data_type::float_p: return "float*";
    case ir_data_type::double_p: return "double*";
    }
    return "<enum to_string error>";
}

IRSentence::IRSentence(ir_op_type operator_type) {
    op_type = operator_type;
}

IRSentence::IRSentence(ir_op_type operator_type, std::vector<std::string>& names, std::vector<ir_data_type>& types) {
    op_type = operator_type;
    this->names = std::move(names);
    this->types = std::move(types);
}

std::string IRSentence::to_string() const {
    const std::string four_spaces("    ");
    switch (op_type) {

    case ir_op_type::error:
        return four_spaces + "ir sentence error";

    case ir_op_type::label_hint:
        return names[0] + ":";

    case ir_op_type::declare:
        return four_spaces + "declare " + ::to_string(types[0]) + " " + names[0];

    case ir_op_type::alloca:
        return four_spaces + names[0] + " = alloca " + ::to_string(types[0]);

    case ir_op_type::func_begin: do {
        std::string res = "define " + ::to_string(types[0]) + " " + names[0] + "(";
        auto i = names.begin() + 1;
        auto j = types.begin() + 1;
        if (i != names.end()) {
            res += ::to_string(*j) + " " + *i;
            ++i; ++j;
            while (i != names.end()) {
                res += ", " + ::to_string(*j) + " " + *i;
                ++i; ++j;
            }
        }
        res += ") #0 {";
        return res;
    } while (0); break;

    case ir_op_type::func_end:
        return "}";
    
    }

    return four_spaces + "ir sentence error";
}

Token* get_token_of_parameter(AstNode* parameter_node) {
    if (parameter_node->is_token_leaf) {
        return &parameter_node->token_leaf;
    } else {
        switch (parameter_node->type) {
        case astnode_type::bin_op_apequ:
        case astnode_type::bin_op_aptype:
            return parameter_node->first_token();
        default:
            stdlog::log << stdlog::error << "cannot use such expression in parameters: " << parameter_node->to_string() << stdlog::endl;
            assert((false && "cannot use such expression in parameters"));
            return nullptr;
        }
    }
}

void calculate_expression_and_no_result_name(
    AstNode*& astnode_now, SymbolTable& sym_table, std::vector<IRSentence>& ir_vec, RegisterManager& global_reg
) {
    return;
}

std::string calculate_expression_and_return_result_name(
    AstNode*& astnode_now, SymbolTable& sym_table, std::vector<IRSentence>& ir_vec, RegisterManager& global_reg
) {
    return "";
}

void sausgi(AstNode*& astnode_now, SymbolTable& sym_table, std::vector<IRSentence>& ir_vec, RegisterManager& global_reg) {
    if (astnode_now == nullptr) return;
    switch (astnode_now->type) {

    case astnode_type::error:
        break;

    case astnode_type::statements:
        for (auto i : astnode_now->sons) {
            sausgi(i, sym_table, ir_vec, global_reg);
        }
        break;

    case astnode_type::pen_op_function_block: do {

        std::string name = astnode_now->sons[0]->token_leaf.content.name;
        if (global_reg.is_global) name = "@" + name;
        else name = "%" + name;

        // sym and ir update simultaneously
        auto function_sym_type = make_sym_function(basic_type::none);
        IRSentence define_func_ir(ir_op_type::func_begin);
        define_func_ir.names.push_back(name);
        define_func_ir.types.push_back(ir_data_type::voids);

        // add params (depend on calls) <-- use <any> first, and implement one if a new call comes.
        auto params = astnode_now->sons[1];
        if (params->type != astnode_type::placeholder)
            for (auto i : params->sons) {
                auto tp = get_token_of_parameter(i);
                switch (tp->type) {
                case token_type::identifier:
                    function_sym_type.son_types.emplace_back(basic_type::any);
                    define_func_ir.names.push_back(tp->content.name);
                    define_func_ir.types.push_back(ir_data_type::any);
                    break;
                default:
                    stdlog::log << stdlog::error << "cannot use such expression in parameters: " << tp->to_string() << stdlog::endl;
                    assert((false && "cannot use such expression in parameters"));
                }
            }

        ir_vec.push_back(define_func_ir);
        sym_table.update(name, function_sym_type);
        stdlog::log << stdlog::info << name << ": " << function_sym_type.to_string() << stdlog::endl;
        sym_table.add_son_goto_son();

        // TODO: func params to inner symble table + inner search

        ir_vec.emplace_back(ir_op_type::func_end);
        sym_table.del_son_goto_parent();
    } while (0); break;

    // these are nude (nothing capture the result), so only do the expression
    // and forget it (do not need real add, unless it's a class __add__,
    // but we do not implement __add__ yet, which is a TODO feature)
    case astnode_type::bin_op_or:
    case astnode_type::bin_op_xor:
    case astnode_type::bin_op_and:
    case astnode_type::bin_op_sleft:
    case astnode_type::bin_op_sright:
    case astnode_type::bin_op_add:
    case astnode_type::bin_op_sub:
    case astnode_type::bin_op_mul:
    case astnode_type::bin_op_div:
    case astnode_type::bin_op_ediv:
    case astnode_type::bin_op_mod:
    case astnode_type::bin_op_at:
    case astnode_type::bin_op_power:
        calculate_expression_and_no_result_name(astnode_now->sons[1], sym_table, ir_vec, global_reg);
        calculate_expression_and_no_result_name(astnode_now->sons[0], sym_table, ir_vec, global_reg);
        break;
    case astnode_type::sin_op_positive:
    case astnode_type::sin_op_negative:
    case astnode_type::sin_op_wavenot:
        calculate_expression_and_no_result_name(astnode_now->sons[0], sym_table, ir_vec, global_reg);
        break;

    }
}

std::vector<IRSentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTable& sym_table
) {
    std::vector<IRSentence> res;
    RegisterManager global_reg(true);
    sausgi(ast_root, sym_table, res, global_reg);
    return res;
}