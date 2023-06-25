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
class SymbolType {

public:
    // for basic

    basic_type base_type;  // if <high_level_type> is "use_basic" then it is basic_type; or it is high_type
    bool is_valued;
    union data_t {
        bool b; int i; double d; char* s;
    } data;

    // for higher

    high_type high_level_type;
    std::vector<SymbolType> son_types;  // for list(1), set(1), dict(2), function(1 + n), tuple(n)
    std::vector<std::string> son_classes;  // for class

    // for assign

    bool is_assigned;
    // if b = a, then the `assign_origin` of b is "a"
    // if b = 1, then b is valued, see `data`, not `assign_origin`
    // if b = (a, 1), then b's son_types will have two: 1st is `assign_origin` "a", 2nd is `data` 1
    std::string assign_origin;

    SymbolType();
    SymbolType(basic_type type);
    SymbolType(basic_type type, SymbolType::data_t data);
    
    std::string to_string() const;
};

SymbolType make_sym_basic(basic_type type);
SymbolType make_sym_basic_valued(basic_type type, SymbolType::data_t data);
// careful, your vector will be passed to son_types and deleted (moved). do not use it anymore if you do this
SymbolType make_sym_tuple(std::vector<SymbolType>&& types);
SymbolType make_sym_same_set(const SymbolType& contain_type);
SymbolType make_sym_same_list(const SymbolType& contain_type);
SymbolType make_sym_same_dict(const SymbolType& contain_key, const SymbolType& contain_value);
// careful, your vector will be passed to son_types and deleted (moved). do not use it anymore if you do this
SymbolType make_sym_function(const SymbolType& return_value, std::vector<SymbolType>&& args = std::vector<SymbolType>());
// careful, your vector will be passed to son_classes and deleted (moved). do not use it anymore if you do this
SymbolType make_sym_class(const std::string& class_name, std::vector<std::string>&& base_class_names = std::vector<std::string>());

class SymbolTableNode {
public:
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