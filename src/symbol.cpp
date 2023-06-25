#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"



std::string to_string(basic_type a) {
    switch (a) {
    case basic_type::none: return "none";
    case basic_type::bools: return "bool";
    case basic_type::ints: return "int";
    case basic_type::floats: return "float";
    case basic_type::str: return "str";
    }
    return "<enum to_string error>";
}

std::string to_string(high_type a) {
    switch (a) {
    case high_type::use_basic: return "use_basic";
    case high_type::dict: return "dict";
    case high_type::list: return "list";
    case high_type::tuple: return "tuple";
    case high_type::set: return "set";
    case high_type::function: return "function";
    case high_type::classes: return "class";
    }
    return "<enum to_string error>";
}

std::string SymbolType::to_string() const {
    if (high_level_type == high_type::use_basic) {
        return ::to_string(base_type);
    } else {
        std::string res = "";
        if (high_level_type == high_type::classes) {
            res += "<class>" + class_name;
        } else {
            res += ::to_string(high_level_type);
        }
        res += ": (";
        for (auto i = son_types.begin(); i < son_types.end(); ++i) {
            if (i == son_types.begin())
                res += i->to_string();
            else
                res += ", " + i->to_string();
        }
        res += ")";
        return res;
    }
}

SymbolType make_sym_basic(basic_type type) {
    SymbolType res;
    res.high_level_type = high_type::use_basic;
    res.base_type = type;
    return res;
}

SymbolType make_sym_tuple(const std::vector<SymbolType>& types) {
    SymbolType res;
    res.high_level_type = high_type::tuple;
    for (const auto& i : types)
        res.son_types.push_back(i);
    return res;
}

SymbolType make_sym_same_set(const SymbolType& contain_type) {
    SymbolType res;
    res.high_level_type = high_type::set;
    res.son_types.push_back(contain_type);
    return res;
}

SymbolType make_sym_same_list(const SymbolType& contain_type) {
    SymbolType res;
    res.high_level_type = high_type::list;
    res.son_types.push_back(contain_type);
    return res;
}

SymbolType make_sym_same_dict(const SymbolType& contain_key, const SymbolType& contain_value) {
    SymbolType res;
    res.high_level_type = high_type::dict;
    res.son_types.push_back(contain_key);
    res.son_types.push_back(contain_value);
    return res;
}

SymbolType make_sym_function(const SymbolType& return_value, const std::vector<SymbolType>& args) {
    SymbolType res;
    res.high_level_type = high_type::function;
    res.son_types.push_back(return_value);
    for (const auto& i : args)
        res.son_types.push_back(i);
    return res;
}

SymbolType make_sym_class(const std::string& class_name, const SymbolType& base_class) {
    SymbolType res;
    res.high_level_type = high_type::classes;
    res.class_name = class_name;
    res.son_types.push_back(base_class);
    return res;
}

SymbolTable::SymbolTable() {
    node_buff.push_back(std::make_unique<SymbolTableNode>());
    now = node_buff.back().get();
    now->parent = nullptr;
    now->son = nullptr;
}

void SymbolTable::add_son_goto_son() {
    node_buff.push_back(std::make_unique<SymbolTableNode>());
    now->son = node_buff.back().get();
    now->son->parent = now;
    now = now->son;
}

void SymbolTable::del_son_goto_parent() {
    auto del = now;
    now = now->parent;
    for (auto i = node_buff.begin(); i != node_buff.end(); ++i) {
        if (i->get() == del) {
            node_buff.erase(i);
            break;
        }
    }
}

void SymbolTable::update(const std::string& name, const SymbolType& type) {
    now->map[name] = type;
}

bool SymbolTable::del(const std::string& name) {
    auto i = now->map.find(name);
    if (i == now->map.end()) {
        now->map.erase(i);
        return true;
    }
    return false;
}

bool SymbolTable::is_in_and_get(const std::string& name, SymbolType& result) {
    auto mama = now;
    auto i = mama->map.find(name);
    while (i == mama->map.end()) {
        if (mama->parent == nullptr) {
            return false;
        } else {
            mama = mama->parent;
            i = mama->map.find(name);
        }
    }
    result = i->second;
    return true;
}