#include <vector>
#include <stack>
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



FuntionManager::FuntionManager() = default;



std::string to_string(ir_data_type a) {
    switch (a) {
    case ir_data_type::error: return "error";
    case ir_data_type::any: return "any";
    case ir_data_type::instant: return "instant";
    case ir_data_type::label: return "label";
    case ir_data_type::voids: return "void";
    case ir_data_type::i1: return "i1";
    case ir_data_type::i8: return "i8";
    case ir_data_type::i16: return "i16";
    case ir_data_type::i32: return "i32";
    case ir_data_type::i64: return "i64";
    case ir_data_type::floats: return "float";
    case ir_data_type::doubles: return "double";
    case ir_data_type::i1_p: return "i1*";
    case ir_data_type::i8_p: return "i8*";
    case ir_data_type::i16_p: return "i16*";
    case ir_data_type::i32_p: return "i32*";
    case ir_data_type::i64_p: return "i64*";
    case ir_data_type::float_p: return "float*";
    case ir_data_type::double_p: return "double*";
    }
    return "<enum to_string error>";
}


inline ir_data_type symbol_basic_type_to_ir_data_type(sym_basic_type type) {
    switch (type) {
    case sym_basic_type::any: return ir_data_type::any;
    case sym_basic_type::none: return ir_data_type::voids;
    case sym_basic_type::bools: return ir_data_type::i1;
    case sym_basic_type::ints: return ir_data_type::i32;
    case sym_basic_type::floats: return ir_data_type::doubles;
    case sym_basic_type::str: return ir_data_type::i8_p;
    }
    return ir_data_type::any;
}

ir_data_type symbol_to_ir_data_type(const SymbolType& type) {
    if (type.is_alias) return ir_data_type::any;
    if (type.high_level_type != sym_high_level_type::use_basic) return ir_data_type::any;
    return symbol_basic_type_to_ir_data_type(type.basic_type);
}

std::string symbol_to_value_string(const std::string& backward_str, const SymbolType& type) {
    if (type.is_alias) return type.alias_origin;
    if (type.high_level_type != sym_high_level_type::use_basic) return backward_str;
    if (!type.is_valued) return backward_str;
    switch (type.basic_type) {
    case sym_basic_type::any: return backward_str;
    case sym_basic_type::none: return "void";
    case sym_basic_type::bools: return type.data.b ? "1" : "0";
    case sym_basic_type::ints: return std::to_string(type.data.i);
    case sym_basic_type::floats: return std::to_string(type.data.d);
    case sym_basic_type::str: return {type.data.s};
    }
    return "symbol_to_value_string error";
}



IRSentence::IRSentence(ir_op_type operator_type) {
    op_type = operator_type;
}

IRSentence::IRSentence(ir_op_type operator_type, std::vector<std::string>&& names, std::vector<ir_data_type>&& types) {
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


    case ir_op_type::ret:
        if (types[0] == ir_data_type::voids)
            return four_spaces + "ret";
        else
            return four_spaces + "ret " + ::to_string(types[0]) + " " + names[0];


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
        res += ") {";
        return res;
    } while (false); break;

    case ir_op_type::func_end:
        return "}";

    case ir_op_type::add:
        return four_spaces + names[0] + " = " + "add " + ::to_string(types[0]) + " " + names[1] + ", " + names[2];

    case ir_op_type::sitofp_to:
        return four_spaces + names[0] + " = " + "sitofp " + ::to_string(types[1]) + " " + names[1] + " to " + ::to_string(types[0]);

    }

    return four_spaces + "ir sentence did not find: " + std::to_string(int(op_type));
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
inline Token* get_name_token_of_parameter_node(AstNode* parameter_node) {
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



void calculate_expression(
    AstNode*& astnode_now, SymbolTableBlockStack& sym_table, std::vector<IRSentence>& ir_vec,
    RegisterManager& global_or_local_reg, bool add_sym_pointer_to_astnode_if_could
) {
    // calculate each kind of expressions
    switch (astnode_now->type) {

    // 0, right value atom
    case astnode_type::atom: do {
        auto atom_token = astnode_now->token_leaf;
        SymbolType result_sym_type;

        switch (atom_token->type) {

        case token_type::keyword: do {
            if (atom_token->content.name == "True") {
                SymbolType::data_t data;
                data.b = true;
                result_sym_type = make_sym_basic_valued(sym_basic_type::bools, data);
            } else if (atom_token->content.name == "False") {
                SymbolType::data_t data;
                data.b = false;
                result_sym_type = make_sym_basic_valued(sym_basic_type::bools, data);
            } else if (atom_token->content.name == "None") {
                result_sym_type = make_sym_basic_valued(sym_basic_type::none, SymbolType::data_t());
            } else {  // including "_", "...", "__in", "__out"
                stdlog::log << stdlog::error << "cannot use such keyword as an right value expression: " << atom_token->to_string() << stdlog::endl;
                assert((false && "cannot use such keyword as an right value expression"));
            }
        } while (false); break;

        case token_type::integer: do {
            SymbolType::data_t data;
            data.i = atom_token->content.data.int_num;
            result_sym_type = make_sym_basic_valued(sym_basic_type::ints, data);
        } while (false); break;

        case token_type::floats: do {
            SymbolType::data_t data;
            data.d = atom_token->content.data.double_num;
            result_sym_type = make_sym_basic_valued(sym_basic_type::floats, data);
        } while (false); break;

        case token_type::identifier: do {
            std::string id_name = global_or_local_name(
                atom_token->content.name, global_or_local_reg.is_global
            );
            if (!sym_table.is_in_and_get(id_name, result_sym_type)) {
                stdlog::log << stdlog::error << "identifier used before defined: " << atom_token->to_string() << stdlog::endl;
                assert((false && "identifier used before defined"));
            }
            if (result_sym_type.is_alias) {  // normal
                astnode_now->is_expression_built = true;
                astnode_now->bound_value_name = result_sym_type.alias_origin;
            } else {  // function, class, function_parameters
                astnode_now->is_expression_built = true;
                astnode_now->bound_value_name = id_name;
            }
        } while (false); break;

        default: do {
            stdlog::log << stdlog::error << "cannot use such thing as an right value expression: " << atom_token->to_string() << stdlog::endl;
            assert((false && "cannot use such thing as an right value expression"));
        } while (false); break;
        }

        if (add_sym_pointer_to_astnode_if_could && atom_token->type != token_type::identifier) {
            astnode_now->is_expression_built = true;
            astnode_now->bound_value_name = global_or_local_reg.get_str_and_next();;
            sym_table.insert_or_change(astnode_now->bound_value_name, result_sym_type);
            stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
        }
    } while (false); break;


    // 1, assignment
    case astnode_type::tri_op_assign: do {
        // astnode_now->sons[0]: type_comment (fake type) (useless) (may be placeholder)
        // astnode_now->sons[1]: lhs
        // astnode_now->sons[2]: rhs
        auto lhs_node = astnode_now->sons[1];
        auto rhs_node = astnode_now->sons[2];

        calculate_expression(
            rhs_node, sym_table, ir_vec, global_or_local_reg, true
        );

        switch (lhs_node->type)
        {

            // a, b = 1, 2
            // a, *b = 1, 2, 3
            // *a, b = 1, 2, 3
        case astnode_type::expressions: do {

            // TODO;

        } while (false); break;

            // a = 1, 2, 3
            //     -> $1 stores &(1, 2 ,3); @a/%a = $1
            // a = b
            //     -> a = $r [b = $r]
            // a = b = c = 1, 2 ,3
            //     -> c = (1, 2 ,3); b = (c = (1, 2 ,3)); a = (b = c = (1, 2 ,3))
            //     -> $1 stores &(1, 2 ,3); @c/%c = $1; @b/%b = $1; @a/%a = $1
            // a = b = c = d
            //     -> c = d; b = (c = d); a = (b = c = d)
            //     -> c = $r; @b/%b = $r; a = $r [d = $r]
            // a: int
            //     -> ignore
        case astnode_type::atom: do {
            auto name_token = lhs_node->first_token();

            // (1) name

            if (name_token->type != token_type::identifier) {
                stdlog::log << stdlog::error << "cannot use such name in assign: " << name_token->to_string() << stdlog::endl;
                assert((false && "cannot use such name in assign"));
            }

            // a: int
            //     -> ignore
            if (rhs_node->type == astnode_type::placeholder) {
                return;
            }

            std::string lhs_name = global_or_local_name(
                name_token->content.name, global_or_local_reg.is_global
            );

            // 2 updates:
            // update symbol table
            // update self node
            // well, don't add ir like: 
            //     data = load i32* bound_name, align 4
            //     store i32 data, i32* now_name, align 4
            // since
            //     a = 1 (%1); a = 2 (%2)
            // is to change the alias of A from %1 to %2, not change the data stored in %1
            if (!rhs_node->is_expression_built) {
                stdlog::log << stdlog::error << "cannot define the value of rhs " << rhs_node->to_string() << stdlog::endl;
                assert((false && "cannot use such name in assign"));
            }

            // update symbol table
            auto rhs_name = rhs_node->bound_value_name;
            sym_table.insert_or_change(lhs_name, make_sym_assign(rhs_name));
            stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;

            // update self node
            if (add_sym_pointer_to_astnode_if_could) {
                astnode_now->is_expression_built = true;
                astnode_now->bound_value_name = rhs_name;
            }

        } while (false); break;

        default:
            stdlog::log << stdlog::error << "cannot use such expression in assign: " << lhs_node->to_string() << stdlog::endl;
            assert((false && "cannot use such expression in assign"));
            break;
        }
    } while (false); break;


    // 2, +=, -=, ...
    case astnode_type::tri_op_augassign: do {
        // astnode_now->sons[0]: operator
        // astnode_now->sons[1]: lhs
        // astnode_now->sons[2]: rhs
        auto operator_node = astnode_now->sons[0];
        auto lhs_node = astnode_now->sons[1];
        auto rhs_node = astnode_now->sons[2];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_or: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_xor: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_and: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_sleft: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_sright: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_add: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        calculate_expression(expr1_node, sym_table, ir_vec, global_or_local_reg, true);
        calculate_expression(expr2_node, sym_table, ir_vec, global_or_local_reg, true);
        SymbolType res1, res2;
        bool b1 = sym_table.is_in_and_get(expr1_node->bound_value_name, res1);
        bool b2 = sym_table.is_in_and_get(expr2_node->bound_value_name, res2);
        if (add_sym_pointer_to_astnode_if_could) {
            if (!b1 || !b2) {
                assert((false && "sym_table get result is false"));
            }
            if (res1.is_alias || res2.is_alias) {
                assert((false && "sym_table get result is alias"));
            }
            if (res1.high_level_type == sym_high_level_type::use_basic && res2.high_level_type == sym_high_level_type::use_basic) {
                if (res1.basic_type == sym_basic_type::ints && res2.basic_type == sym_basic_type::ints) {
                    // update sym
                    SymbolType result_sym_type = make_sym_basic(sym_basic_type::ints);
                    astnode_now->is_expression_built = true;
                    astnode_now->bound_value_name = global_or_local_reg.get_str_and_next();
                    sym_table.insert_or_change(astnode_now->bound_value_name, result_sym_type);
                    stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
                    // update ir
                    IRSentence expr_ir(ir_op_type::add);
                    expr_ir.types.push_back(ir_data_type::i32);
                    expr_ir.names.push_back(astnode_now->bound_value_name);
                    expr_ir.names.push_back(symbol_to_value_string(expr1_node->bound_value_name, res1));
                    expr_ir.names.push_back(symbol_to_value_string(expr2_node->bound_value_name, res2));
                    ir_vec.push_back(expr_ir);
                }
                else if (res1.basic_type == sym_basic_type::ints && res2.basic_type == sym_basic_type::floats) {
                    // int to double
                    IRSentence cast_ir(ir_op_type::sitofp_to);
                    std::string temp = global_or_local_reg.get_str_and_next();
                    cast_ir.types.push_back(ir_data_type::doubles);
                    cast_ir.types.push_back(ir_data_type::i32);
                    cast_ir.names.push_back(temp);
                    cast_ir.names.push_back(symbol_to_value_string(expr1_node->bound_value_name, res1));
                    ir_vec.push_back(cast_ir);
                    // update sym
                    SymbolType result_sym_type = make_sym_basic(sym_basic_type::floats);
                    astnode_now->is_expression_built = true;
                    astnode_now->bound_value_name = global_or_local_reg.get_str_and_next();
                    sym_table.insert_or_change(astnode_now->bound_value_name, result_sym_type);
                    stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
                    // update ir
                    IRSentence expr_ir(ir_op_type::add);
                    expr_ir.types.push_back(ir_data_type::doubles);
                    expr_ir.names.push_back(astnode_now->bound_value_name);
                    expr_ir.names.push_back(temp);
                    expr_ir.names.push_back(symbol_to_value_string(expr2_node->bound_value_name, res2));
                    ir_vec.push_back(expr_ir);
                } else if (res1.basic_type == sym_basic_type::floats && res2.basic_type == sym_basic_type::ints) {
                    // int to double
                    IRSentence cast_ir(ir_op_type::sitofp_to);
                    std::string temp = global_or_local_reg.get_str_and_next();
                    cast_ir.types.push_back(ir_data_type::doubles);
                    cast_ir.types.push_back(ir_data_type::i32);
                    cast_ir.names.push_back(temp);
                    cast_ir.names.push_back(symbol_to_value_string(expr2_node->bound_value_name, res2));
                    ir_vec.push_back(cast_ir);
                    // update sym
                    SymbolType result_sym_type = make_sym_basic(sym_basic_type::floats);
                    astnode_now->is_expression_built = true;
                    astnode_now->bound_value_name = global_or_local_reg.get_str_and_next();
                    sym_table.insert_or_change(astnode_now->bound_value_name, result_sym_type);
                    stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
                    // update ir
                    IRSentence expr_ir(ir_op_type::add);
                    expr_ir.types.push_back(ir_data_type::doubles);
                    expr_ir.names.push_back(astnode_now->bound_value_name);
                    expr_ir.names.push_back(symbol_to_value_string(expr1_node->bound_value_name, res1));
                    expr_ir.names.push_back(temp);
                    ir_vec.push_back(expr_ir);
                }

                // TODO: add other expression kinds, such as str.

            } else {
                assert((false && "add two high_level_type"));
            }
        }
    } while (false); break;


    case astnode_type::bin_op_sub: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_mul: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_div: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_ediv: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_mod: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_at: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::bin_op_power: do {
        // astnode_now->sons[0]: expr1
        // astnode_now->sons[1]: expr2
        auto expr1_node = astnode_now->sons[0];
        auto expr2_node = astnode_now->sons[1];
        // TODO;

    } while (false); break;


    case astnode_type::sin_op_positive: do {
        // astnode_now->sons[0]: expr1
        auto expr1_node = astnode_now->sons[0];
        // TODO;

    } while (false); break;


    case astnode_type::sin_op_negative: do {
        // astnode_now->sons[0]: expr1
        auto expr1_node = astnode_now->sons[0];
        // TODO;

    } while (false); break;


    case astnode_type::sin_op_wavenot: do {
        // astnode_now->sons[0]: expr1
        auto expr1_node = astnode_now->sons[0];
        // TODO;

    } while (false); break;


    default:
        break;

    }

    return;
}



// search astnode, update symboltable, generate ir
void sausgi(
    AstNode*& astnode_now, SymbolTableBlockStack& sym_table, std::vector<IRSentence>& ir_vec,
    RegisterManager& global_or_local_reg, FuntionManager& func_mgr
) {
    if (astnode_now == nullptr) return;

    // updating symboltable, generating ir
    // searching astnode is in specific cases such as `astnode_type::statements`
    switch (astnode_now->type) {


    case astnode_type::error: do {
        ; // nothing
    } while (false); break;


    case astnode_type::statements: do {
        for (auto i : astnode_now->sons) {
            sausgi(i, sym_table, ir_vec, global_or_local_reg, func_mgr);
        }
        break;
    } while (false); break;


    case astnode_type::sin_op_return: do {
        // astnode_now->sons[0]: expr (may be placeholder)
        auto expr_node = astnode_now->sons[0];

        if (func_mgr.func_entry_stack.empty()) {
            stdlog::log << stdlog::error << "cannot use such return outside functions: " << astnode_now->to_string() << stdlog::endl;
            assert((false && "cannot use such return outside functions"));
        }

        ir_vec.emplace_back(
            ir_op_type::label_hint,
            std::vector<std::string>{"return"},
            std::vector<ir_data_type>{ir_data_type::label}
        );

        if (expr_node->type == astnode_type::placeholder) {
            ir_vec.emplace_back(
                ir_op_type::ret,
                std::vector<std::string>{"void"},
                std::vector<ir_data_type>{ir_data_type::voids}
            );
            // This will change the types of the function to the last return statment
            // so please return the same types, for example in if-else
            ir_vec[func_mgr.func_entry_stack.top()].types[0] = ir_vec.back().types[0];
            if (!sym_table.update_func_return(ir_vec[func_mgr.func_entry_stack.top()].names[0], sym_basic_type::none)) {
                stdlog::log << stdlog::error << "fatal error: [1] function update return error: " << expr_node->to_string() << stdlog::endl;
                assert((false && "fatal error: [1] function update return error"));
            }
            stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
        } else {
            calculate_expression(
                expr_node, sym_table, ir_vec, global_or_local_reg, true
            );
            if (!expr_node->is_expression_built) {
                stdlog::log << stdlog::error << "cannot use such expression in return statement: " << expr_node->to_string() << stdlog::endl;
                assert((false && "cannot use such expression in return statement"));
            }
            SymbolType return_sym_type;
            if (!sym_table.is_in_and_get(expr_node->bound_value_name, return_sym_type)) {
                stdlog::log << stdlog::error << "identifier used before defined: " << expr_node->to_string() << stdlog::endl;
                assert((false && "identifier used before defined"));
            }
            ir_vec.emplace_back(
                ir_op_type::ret,
                std::vector<std::string>{symbol_to_value_string(expr_node->bound_value_name, return_sym_type)},
                std::vector<ir_data_type>{symbol_to_ir_data_type(return_sym_type)}
            );
            // This will change the types of the function to the last return statment
            // so please return the same types, for example in if-else
            ir_vec[func_mgr.func_entry_stack.top()].types[0] = ir_vec.back().types[0];
            if (!sym_table.update_func_return(ir_vec[func_mgr.func_entry_stack.top()].names[0], return_sym_type)) {
                stdlog::log << stdlog::error << "fatal error: [2] function update return error: " << expr_node->to_string() << stdlog::endl;
                assert((false && "fatal error: [2] function update return error"));
            }
            stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
        }
    } while (false); break;


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

        // (1) name

        if (!name_node->is_token_leaf) {
            stdlog::log << stdlog::error << "cannot use such name in function define: " << name_node->to_string() << stdlog::endl;
            assert((false && "cannot use such name in function define"));
        }

        if (name_node->token_leaf->type != token_type::identifier) {
            stdlog::log << stdlog::error << "cannot use such name in function define: " << name_node->token_leaf->to_string() << stdlog::endl;
            assert((false && "cannot use such name in function define"));
        }

        std::string func_name = global_or_local_name(
            name_node->token_leaf->content.name, global_or_local_reg.is_global
        );

        // (2) parameters

        // sym and ir update simultaneously

        // update sym
        auto function_sym_type = make_sym_function(sym_basic_type::none);
        // update ir
        IRSentence define_func_ir(ir_op_type::func_begin);
        define_func_ir.names.push_back(func_name);
        define_func_ir.types.push_back(ir_data_type::any);

        // add params (depend on calls) <-- use <any> first, and implement one if a new call comes.
        if (params_node->type != astnode_type::placeholder)
            for (auto i : params_node->sons) {
                auto param_token = get_name_token_of_parameter_node(i);

                if (param_token->type != token_type::identifier) {
                    stdlog::log << stdlog::error << "cannot use such expression in parameters: " << param_token->to_string() << stdlog::endl;
                    assert((false && "cannot use such expression in parameters"));
                }

                std::string param_name = local_name(param_token->content.name);

                // update sym
                function_sym_type.son_types.emplace_back(sym_basic_type::any);
                // update ir
                define_func_ir.names.push_back(param_name);
                define_func_ir.types.push_back(ir_data_type::any);
            }

        // update sym
        sym_table.insert_or_change(func_name, function_sym_type);
        stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
        // update ir
        ir_vec.push_back(define_func_ir);

        func_mgr.func_entry_stack.push(ir_vec.end() - ir_vec.begin() - 1);

        ir_vec.emplace_back(
            ir_op_type::label_hint,
            std::vector<std::string>{"entry"},
            std::vector<ir_data_type>{ir_data_type::label}
        );

        // (3) blocks

        sym_table.goto_inner_block();

        // .begin() + 1: ignore funtion name
        for (auto i = define_func_ir.names.begin() + 1; i < define_func_ir.names.end(); ++i) {
            sym_table.insert_or_change(*i, sym_basic_type::any);
            stdlog::log << stdlog::info << sym_table.last_to_string() << stdlog::endl;
        }

        // inner block, if is global, change to a new local var
        if (global_or_local_reg.is_global) {
            RegisterManager local_reg;
            for (auto i : block_node->sons) {
                sausgi(i, sym_table, ir_vec, local_reg, func_mgr);
            }
        } else {
            for (auto i : block_node->sons) {
                sausgi(i, sym_table, ir_vec, global_or_local_reg, func_mgr);
            }
        }

        // update ir (})
        ir_vec.emplace_back(ir_op_type::func_end);

        func_mgr.func_entry_stack.pop();

        sym_table.goto_outside_block();

    } while (false); break;

    case astnode_type::bin_op_fcall: do {
        // astnode_now->sons[0]: name
        // astnode_now->sons[1]: args (may be placeholder)
        auto name_node = astnode_now->sons[0];
        auto args_node = astnode_now->sons[1];

        // TODO;

    } while (false); break;

    // these are nude (nothing capture the result),
    // so only do the expression assign to anything
    case astnode_type::tri_op_assign:
    case astnode_type::tri_op_augassign:
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
    case astnode_type::sin_op_positive:
    case astnode_type::sin_op_negative:
    case astnode_type::sin_op_wavenot:
    case astnode_type::atom: do {
        calculate_expression(astnode_now, sym_table, ir_vec, global_or_local_reg, false);
    } while (false); break;


    }
}



std::vector<IRSentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTableBlockStack& sym_table
) {
    std::vector<IRSentence> res;
    RegisterManager global_reg(true);
    FuntionManager func_mgr;
    sausgi(ast_root, sym_table, res, global_reg, func_mgr);
    return res;
}