#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include "symbol.h"

enum class symbol_type {
    ints, floats, str, dict, list, tuple, set, function,
};

struct SymAttr {
    symbol_type type;
    std::vector<SymAttr> sons;
};

struct SymbolTable {
    std::unordered_map<std::string, SymAttr> buff;
    void insert(const std::string& name, SymAttr attr);
    void update(const std::string& name, SymAttr attr);
    bool del(const std::string& name);
    bool is_in(const std::string& name);
    SymAttr get(const std::string& name);
};