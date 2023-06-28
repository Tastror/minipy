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



void PointerManager::next() {
    id++;
}

int PointerManager::get_int() {
    return id;
}

int PointerManager::get_int_and_next() {
    return ++id;
}

std::string PointerManager::get_str() {
    return "$" + std::to_string(id);
}

std::string PointerManager::get_str_and_next() {
    return "$" + std::to_string(++id);
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

    // print ir_node to std::string
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


// utils functions

// always use xxx_name() after getting token's xxx.name
inline std::string local_name(const std::string& name) {
    return "%" + name;
}

// always use xxx_name() after getting token's xxx.name
inline std::string global_name(const std::string& name) {
    return "@" + name;
}

// change to global or local name
// always use xxx_name() after getting token's xxx.name
inline std::string global_or_local_name(const std::string& name, bool is_global) {
    if (is_global) return "@" + name;
    else return "%" + name;
}

// always get the first token if has
// if no, will assert false!
inline Token* get_token_of_parameter(AstNode* parameter_node) {
    if (parameter_node->is_token_leaf) {
        return parameter_node->token_leaf;
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

inline void calculate_expression_and_no_result_name(
    AstNode*& astnode_now, SymbolTableTree& sym_table, std::vector<IRSentence>& ir_vec,
    RegisterManager& global_reg, PointerManager& pointer_mgr
) {
    return;
}

inline std::string calculate_expression_and_return_result_name(
    AstNode*& astnode_now, SymbolTableTree& sym_table, std::vector<IRSentence>& ir_vec,
    RegisterManager& global_reg, PointerManager& pointer_mgr
) {
    return "";
}



// search astnode, update symboltable, generate ir
void sausgi(
    AstNode*& astnode_now, SymbolTableTree& sym_table, std::vector<IRSentence>& ir_vec,
    RegisterManager& global_or_local_reg, PointerManager& pointer_mgr
) {
    
    if (astnode_now == nullptr) return;

    // updating symboltable, generating ir
    // searching astnode is in specific cases such as `astnode_type::statements`
    switch (astnode_now->type) {


    case astnode_type::error: do {
        ; // nothing
    } while (0); break;


    case astnode_type::statements: do {
        for (auto i : astnode_now->sons) {
            sausgi(i, sym_table, ir_vec, global_or_local_reg, pointer_mgr);
        }
        break;
    } while (0); break;

    case astnode_type::pen_op_function_block: do {
        // astnode_now->sons[0]: name
        // astnode_now->sons[1]: params (may be placeholder)
        // astnode_now->sons[2]: return type_comment (fake type) (may be placeholder) (useless)
        // astnode_now->sons[3]: block
        // astnode_now->sons[3]: decorators  (may be placeholder)
        auto name_node = astnode_now->sons[0];
        auto params_node = astnode_now->sons[1];
        auto block_node = astnode_now->sons[3];
        auto decorators_node = astnode_now->sons[4];

        std::string name = global_or_local_name(
            name_node->token_leaf->content.name, global_or_local_reg.is_global
        );

        // sym and ir update simultaneously
        auto function_sym_type = make_sym_function(sym_basic_type::none);
        IRSentence define_func_ir(ir_op_type::func_begin);
        define_func_ir.names.push_back(name);
        define_func_ir.types.push_back(ir_data_type::any);

        // add params (depend on calls) <-- use <any> first, and implement one if a new call comes.
        if (params_node->type != astnode_type::placeholder)
            for (auto i : params_node->sons) {
                auto tp = get_token_of_parameter(i);
                switch (tp->type) {
                case token_type::identifier:
                    function_sym_type.son_types.emplace_back(sym_basic_type::any);
                    define_func_ir.names.push_back(local_name(tp->content.name));
                    define_func_ir.types.push_back(ir_data_type::any);
                    break;
                default:
                    stdlog::log << stdlog::error << "cannot use such expression in parameters: " << tp->to_string() << stdlog::endl;
                    assert((false && "cannot use such expression in parameters"));
                    break;
                }
            }

        ir_vec.push_back(define_func_ir);
        sym_table.update(name, function_sym_type);
        stdlog::log << stdlog::info << sym_table.last_update_to_string() << stdlog::endl;
        sym_table.add_son_goto_son();

        // +1: no funtion name
        for (auto i = define_func_ir.names.begin() + 1; i < define_func_ir.names.end(); ++i) {
            sym_table.update(*i, sym_basic_type::any);
            stdlog::log << stdlog::info << sym_table.last_update_to_string() << stdlog::endl;
        }

        // inner block, if is global, change to a new local var
        if (global_or_local_reg.is_global) {
            RegisterManager local_reg;
            for (auto i : block_node->sons) {
                sausgi(i, sym_table, ir_vec, local_reg, pointer_mgr);
            }
        } else {
            for (auto i : block_node->sons) {
                sausgi(i, sym_table, ir_vec, global_or_local_reg, pointer_mgr);
            }
        }

        ir_vec.emplace_back(ir_op_type::func_end);
        sym_table.del_son_goto_parent();
    } while (0); break;


    case astnode_type::tri_op_assign: do {
        // astnode_now->sons[0]: type_comment (fake type) (useless) (may be placeholder)
        // astnode_now->sons[1]: lhs
        // astnode_now->sons[2]: rhs
        auto lhs_node = astnode_now->sons[1];
        auto rhs_node = astnode_now->sons[2];
        switch (lhs_node->type)
        {
        // a, b = 1, 2
        // a, *b = 1, 2, 3
        // *a, b = 1, 2, 3
        case astnode_type::expressions: do {

        } while (0); break;

        // a = 1
        //     -> @a/%a = 1
        // a = 1, 2, 3
        //     -> $1 = (1, 2 ,3); @a/%a = $1
        // a = b
        //     -> a = $r [b = $r]; or
        //     -> @a/%a = 1 [b = 1]
        // a = b = c = 1
        //     -> c = 1; b = (c = 1); a = (b = c = 1)
        //     -> @c/%c = 1; @b/%b = 1; @a/%a = 1
        // a = b = c = 1, 2 ,3
        //     -> c = (1, 2 ,3); b = (c = (1, 2 ,3)); a = (b = c = (1, 2 ,3))
        //     -> $1 = (1, 2 ,3); @c/%c = $1; @b/%b = $1; @a/%a = $1
        // a = b = c = d
        //     -> c = d; b = (c = d); a = (b = c = d)
        //     -> c = $r; @b/%b = $r; a = $r [d = $r]; or
        //     -> @c/%c = 1; @b/%b = 1; @a/%a = 1 [d = 1]
        case astnode_type::atom: do {
            auto atom_token = lhs_node->first_token();
            if (atom_token->type == token_type::identifier) {
                
            } else {
                stdlog::log << stdlog::error << "cannot use such expression in assign: " << atom_token->to_string() << stdlog::endl;
                assert((false && "cannot use such expression in assign"));
            }
        } while (0); break;

        default:
            stdlog::log << stdlog::error << "cannot use such expression in assign: " << lhs_node->to_string() << stdlog::endl;
            assert((false && "cannot use such expression in assign"));
            break;
        }
    } while (0); break;


    case astnode_type::tri_op_augassign: do {
        // astnode_now->sons[0]: operator
        // astnode_now->sons[1]: lhs
        // astnode_now->sons[2]: rhs
        auto operator_node = astnode_now->sons[0];
        auto lhs_node = astnode_now->sons[1];
        auto rhs_node = astnode_now->sons[2];

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
    case astnode_type::bin_op_power: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        calculate_expression_and_no_result_name(expr1_node, sym_table, ir_vec, global_or_local_reg, pointer_mgr);
        calculate_expression_and_no_result_name(expr2_node, sym_table, ir_vec, global_or_local_reg, pointer_mgr);
    } while (0); break;


    // these are nude (nothing capture the result), so only do the expression
    case astnode_type::sin_op_positive:
    case astnode_type::sin_op_negative:
    case astnode_type::sin_op_wavenot: do {
        // astnode_now->sons[0]: expr1
        auto expr1_node = astnode_now->sons[0];
        calculate_expression_and_no_result_name(expr1_node, sym_table, ir_vec, global_or_local_reg, pointer_mgr);
    } while (0); break;


    }
}



std::vector<IRSentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTableTree& sym_table
) {
    std::vector<IRSentence> res;
    RegisterManager global_reg(true);
    PointerManager pointer_mgr;
    sausgi(ast_root, sym_table, res, global_reg, pointer_mgr);
    return res;
}