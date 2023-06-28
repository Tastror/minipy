#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"



std::string to_string(sym_basic_type a) {
    switch (a) {
    case sym_basic_type::none: return "none";
    case sym_basic_type::bools: return "bool";
    case sym_basic_type::ints: return "int";
    case sym_basic_type::floats: return "float";
    case sym_basic_type::str: return "str";
    case sym_basic_type::any: return "any";
    }
    return "<enum to_string error>";
}

std::string to_string(sym_high_level_type a) {
    switch (a) {
    case sym_high_level_type::use_basic: return "use_basic";
    case sym_high_level_type::dict: return "dict";
    case sym_high_level_type::list: return "list";
    case sym_high_level_type::tuple: return "tuple";
    case sym_high_level_type::set: return "set";
    case sym_high_level_type::function: return "function";
    case sym_high_level_type::classes: return "class";
    }
    return "<enum to_string error>";
}

SymbolType::SymbolType() : SymbolType(sym_basic_type::none) {}

SymbolType::SymbolType(sym_basic_type type) {
    basic_type = type;
    is_valued = false;
    data.i = 0;
    high_level_type = sym_high_level_type::use_basic;
    is_assigned = false;
}

SymbolType::SymbolType(sym_basic_type type, SymbolType::data_t data) {
    basic_type = type;
    is_valued = true;
    data = data;
    high_level_type = sym_high_level_type::use_basic;
    is_assigned = false;
}

std::string SymbolType::to_string() const {
    if (is_assigned) {
        return "assigned to " + assign_origin;
    } else if (high_level_type == sym_high_level_type::use_basic) {
        return ::to_string(basic_type);
    } else {
        std::string res = "";
        res += ::to_string(high_level_type);
        if (high_level_type == sym_high_level_type::classes) {
            res += ": extend (";
            for (auto i = son_classes.begin(); i < son_classes.end(); ++i) {
                if (i == son_classes.begin())
                    res += *i;
                else
                    res += ", " + *i;
            }
        } else {
            res += ": (";
            for (auto i = son_types.begin(); i < son_types.end(); ++i) {
                if (i == son_types.begin())
                    res += i->to_string();
                else
                    res += ", " + i->to_string();
            }
        }
        res += ")";
        return res;
    }
}

SymbolType make_sym_assign(const std::string& name) {
    auto res = SymbolType();
    res.is_assigned = true;
    res.assign_origin = name;
    return res;
}

SymbolType make_sym_basic(sym_basic_type type) {
    return SymbolType(type);
}

SymbolType make_sym_basic_valued(sym_basic_type type, SymbolType::data_t data) {
    return SymbolType(type, data);
}

SymbolType make_sym_tuple(std::vector<SymbolType>&& types) {
    SymbolType res;
    res.high_level_type = sym_high_level_type::tuple;
    res.son_types = std::move(types);
    return res;
}

SymbolType make_sym_same_set(const SymbolType& contain_type) {
    SymbolType res;
    res.high_level_type = sym_high_level_type::set;
    res.son_types.push_back(contain_type);
    return res;
}

SymbolType make_sym_same_list(const SymbolType& contain_type) {
    SymbolType res;
    res.high_level_type = sym_high_level_type::list;
    res.son_types.push_back(contain_type);
    return res;
}

SymbolType make_sym_same_dict(const SymbolType& contain_key, const SymbolType& contain_value) {
    SymbolType res;
    res.high_level_type = sym_high_level_type::dict;
    res.son_types.push_back(contain_key);
    res.son_types.push_back(contain_value);
    return res;
}

SymbolType make_sym_function(const SymbolType& return_value, std::vector<SymbolType>&& args) {
    SymbolType res;
    res.high_level_type = sym_high_level_type::function;
    res.son_types.push_back(return_value);
    res.son_types.insert(
        res.son_types.end(),
        std::make_move_iterator(args.begin()), 
        std::make_move_iterator(args.end())
    );
    args.erase(args.begin(), args.end());
    return res;
}

SymbolType make_sym_class(const std::string& class_name, std::vector<std::string>&& base_class_names) {
    SymbolType res;
    res.high_level_type = sym_high_level_type::classes;
    res.son_classes = std::move(base_class_names);
    return res;
}



SymbolTableBlockStack::SymbolTableBlockStack() {
    node_buff.push(std::make_unique<SymbolTableNode>());
    now = node_buff.top().get();
    now->parent = nullptr;
    now->son = nullptr;
}

void SymbolTableBlockStack::add_son_goto_son() {
    node_buff.push(std::make_unique<SymbolTableNode>());
    now->son = node_buff.top().get();
    now->son->parent = now;
    now = now->son;
}

void SymbolTableBlockStack::del_son_goto_parent() {
    now = now->parent;
    node_buff.pop();
}

void SymbolTableBlockStack::update(const std::string& name, const SymbolType& type) {
    now->map[name] = type;
    last_update_name = name;
}

// last update name, please make sure it is in.
std::string SymbolTableBlockStack::last_update_to_string() {
    return last_update_name + ": " + now->map[last_update_name].to_string();
}

bool SymbolTableBlockStack::del(const std::string& name) {
    auto i = now->map.find(name);
    if (i == now->map.end()) {
        now->map.erase(i);
        return true;
    }
    return false;
}

bool SymbolTableBlockStack::is_in_and_get(const std::string& name, SymbolType& result) {
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