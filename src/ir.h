#pragma once

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

class RegisterManager {
private:
    int id;
public:
    bool is_global;
    RegisterManager();
    RegisterManager(bool is_global);
    void next();
    int get_int();
    int get_int_and_next();
    std::string get_str();
    std::string get_str_and_next();
};

class FuntionManager {
public:
    std::stack<int> func_entry_stack;
    FuntionManager();
};

enum class ir_op_type {
    error,
    label_hint,  // label_name0:  # type0 == label, but not show here; number should be <label>:num:
    declare,  // declare type0 name0
    // assign,  // name0 = assign name1  // no, it is no use to just "assign", x = a, c = x + b --> c = a + b
    alloca,  // name0 = alloca type0
    load,  // name0 = load type0, ptr_type1 name1
    store,  // store type0 name0, ptr_type1 name1
    add, sub, mul, div, rems,  // name0 = <op> type0 name1, name2
    uadd, usub, umul, udiv, urems,  // name0 = <op> type0 name1, name2
    fadd, fsub, fmul, fdiv,  // name0 = <op> type0 name1, name2
    eq, ne, ugt, uge, ult, ule, sgt, sge, slt, sle,  // name0 = icmp <op> type0 name1, name2
    br_1,  // br label_type0 name0
    br_3,  // br type0 name0, label_type1 name1, label_type2 name2
    ret,  // ret type0 name0
    switch_begin,  // switch type0 name0, label_type1 name1 [  # this label is for default
    switch_inner,  // type0 value1, label_type1 name1
    switch_end,  // ]
    func_begin,  // define return_value[type0] \@func_name[name0] (type name, ...) #0 {
    func_end,  // }
    func_call,  // call type0 @name0(type1 name1, ...)
    func_call_assign,  // name0 = call type1[not type0!!!] @name1(type2 name2, ...)
};

enum class ir_data_type {
    error,
    any,
    instant,  // instant number
    label, voids,
    i1, i8, i16, i32, i64, floats, doubles,
    i1_p, i8_p, i16_p, i32_p, i64_p, float_p, double_p,  // pointer
};

ir_data_type symbol_to_ir_data_type(const SymbolType& type);
std::string symbol_to_value_string(const std::string& backward_str, const SymbolType& type);

class IRSentence {
public:
    ir_op_type op_type;
    std::vector<std::string> names;
    std::vector<ir_data_type> types;
    IRSentence(ir_op_type operator_type);
    // use std::move for vectors, so names and types outside will be deleted!
    IRSentence(ir_op_type operator_type, std::vector<std::string>&& names, std::vector<ir_data_type>&& types);
    std::string to_string() const;
};

std::vector<IRSentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTableBlockStack& sym_table
);
