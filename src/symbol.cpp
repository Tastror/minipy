#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "common.h"
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
    return "<to_string error>";
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
    return "<to_string error>";
}

std::string SymbolType::to_string() {
    if (high_level_type == high_type::use_basic) {
        return ::to_string(base_type);
    } else {
        std::string res = "";
        res += ::to_string(high_level_type) + ": ";
        for (auto i : base_types) {
            res += ::to_string(i) + " ";
        }
        return res;
    }
}