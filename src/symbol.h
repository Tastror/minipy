#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "common.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"

enum class basic_type {
    none, bools, ints, floats, str,
};

std::string to_string(basic_type a);

enum class high_type {
    use_basic, dict, list, tuple, set, function, classes,
};

std::string to_string(high_type a);

struct SymbolType {
    basic_type base_type;
    high_type high_level_type;
    std::vector<basic_type> base_types;
    std::string to_string();
};

struct SymAttr {
    SymbolType type;
    std::vector<SymbolType> sons;
};

struct SymbolTableNode {
    std::unordered_map<std::string, SymAttr> buff;
    std::vector<SymbolTableNode*> sons;
    SymbolTableNode* parent;
};

class SymbolTable {
private:
    std::vector<std::unique_ptr<SymbolTableNode>> node_list;
public:
    SymbolTableNode* now;
    void add_son_goto_son();
    void del_son_goto_parent();
    void insert(const std::string& name, SymAttr attr);
    void update(const std::string& name, SymAttr attr);
    bool del(const std::string& name);
    bool is_in(const std::string& name);
    SymAttr get(const std::string& name);
};