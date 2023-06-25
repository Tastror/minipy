#include <vector>
#include <string>
#include <memory>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"
#include "ir.h"

RegisterManager::RegisterManager() {
    id = 0;
    is_global = false;
}

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
    case ir_data_type::instant: return "instant";
    case ir_data_type::label: return "label";
    case ir_data_type::voids: return "void";
    case ir_data_type::i32: return "i32";
    case ir_data_type::i64: return "i64";
    case ir_data_type::floats: return "float";
    case ir_data_type::doubles: return "double";
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
        std::string res = "define " + ::to_string(types[0]) + " @" + names[0] + "(";
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

void sausgi(AstNode*& astnode_now, SymbolTable& sym_table, std::vector<IRSentence>& ir_vec, RegisterManager global_reg) {
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
        sym_table.update(
            astnode_now->sons[0]->token_leaf.content.name,
            make_sym_function(
                make_sym_basic(basic_type::none),
                std::vector<SymbolType>()  // TODO: add params
            )
        );
        IRSentence define_func_ir(ir_op_type::func_begin);
        define_func_ir.names.push_back(astnode_now->sons[0]->token_leaf.content.name);
        define_func_ir.types.push_back(ir_data_type::voids);
        // TODO: add params
        ir_vec.push_back(define_func_ir);
        sym_table.add_son_goto_son();
        // TODO: inner
        ir_vec.emplace_back(ir_op_type::func_end);
        sym_table.del_son_goto_parent();
    } while (0); break;
    case astnode_type::bin_op_add:
        break;
    }
}

std::vector<IRSentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTable& sym_table
) {
    std::vector<IRSentence> res;
    RegisterManager global_reg;
    sausgi(ast_root, sym_table, res, global_reg);
    return res;
}