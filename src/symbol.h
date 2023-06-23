#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "timing.h"
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

// this is a single type, such as int, str, ...
// or function(return_type, )
struct SymbolType {
    basic_type base_type;
    high_type high_level_type;
    std::vector<SymbolType> son_types;
    std::string class_name;
    std::string to_string() const;
};

SymbolType make_basic(basic_type type);
SymbolType make_tuple(const std::vector<SymbolType>& types);
SymbolType make_same_set(const SymbolType& contain_type);
SymbolType make_same_list(const SymbolType& contain_type);
SymbolType make_same_dict(const SymbolType& contain_key, const SymbolType& contain_value);
SymbolType make_function(const SymbolType& return_value, const std::vector<SymbolType>& args);
SymbolType make_class(const std::string& class_name, const SymbolType& base_class = make_basic(basic_type::none));

struct SymbolTableNode {
    std::unordered_map<std::string, SymbolType> map;
    SymbolTableNode* son;
    SymbolTableNode* parent;
};

class SymbolTable {
private:
    SymbolTableNode* now;
    std::vector<std::unique_ptr<SymbolTableNode>> node_buff;
public:
    SymbolTable();
    void add_son_goto_son();
    void del_son_goto_parent();
    void update(const std::string& name, const SymbolType& type);
    bool del(const std::string& name);
    bool is_in_and_get(const std::string& name, SymbolType& result);
};