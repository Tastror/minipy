#pragma once

#include <vector>
#include <string>
#include <memory>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"

class RegisterManager {
private:
    int id;
    bool is_global;
public:
    RegisterManager();
    RegisterManager(bool is_global);
    void next();
    int get_int();
    int get_int_and_next();
    std::string get_str();
    std::string get_str_and_next();
};

enum class ir_op_type {
    error,
    label_hint,  // label_name1:  # type1 == label, but not show here; number should be <label>:num:
    declare,  // declare type1 name1
    alloca,  // name1 = alloca type1
    load,  // name1 = load type1, ptr_type2 name2
    store,  // store type1 name1, ptr_type2 name2
    add, sub, mul, div, rems,  // name1 = <op> type1 name2, name3
    uadd, usub, umul, udiv, urems,  // name1 = <op> type1 name2, name3
    fadd, fsub, fmul, fdiv,  // name1 = <op> type1 name2, name3
    eq, ne, ugt, uge, ult, ule, sgt, sge, slt, sle,  // name1 = icmp <op> type1 name2, name3
    br_1,  // br label_type1 name1
    br_3,  // br type1 name1, label_type2 name2, label_type3 name3
    ret,  // ret type1 name1
    switch_begin,  // switch type1 name1, label_type2 name2 [  # this label is for default
    switch_inner,  // type1 value1, label_type2 name2 
    switch_end,  // ]
    func_begin,  // define return_value[type1] \@func_name[name1] (type name, ...) #0 {
    func_end,  // } 
};

enum class ir_data_type {
    error,
    instant,  // instant number
    label, voids,
    i32, i64, floats, doubles,
    i32_p, i64_p, float_p, double_p,  // pointer
};

class IRSentence {
public:
    ir_op_type op_type;
    std::vector<std::string> names;
    std::vector<ir_data_type> types;
    IRSentence(ir_op_type operator_type);
    // names and types outside will be deleted!
    IRSentence(ir_op_type operator_type, std::vector<std::string>& names, std::vector<ir_data_type>& types);
    std::string to_string() const;
};

std::vector<IRSentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTable& sym_table
);