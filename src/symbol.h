#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <stack>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"

enum class sym_basic_type {
    none, bools, ints, floats, str, any,
};

std::string to_string(sym_basic_type a);

enum class sym_high_level_type {
    use_basic, dict, list, tuple, set, function, classes,
};

std::string to_string(sym_high_level_type a);

// this is a single type, such as int, str, ...
// or function(return_type, )
class SymbolType {

public:

    // for assign

    // if `true`, enable this and use <assign_origin>
    // if you need <high_level_type> or <basic_type>, this must be `false`
    bool is_assigned;
    // see <is_assigned>
    // if b = a, then the `assign_origin` of b is "a"
    // if b = 1, then b is valued, see `data`, not `assign_origin`
    // if b = (a, 1), then b's son_types will have two: 1st is `assign_origin` "a", 2nd is `data` 1
    std::string assign_origin;

    // for higher

    // if <is_assigned> is `false`, then this could be enabled
    // if not `use_basic`, enabled this and use <son_types> or <son_classes>
    // if you need <basic_type>, this must be `use_basic`
    sym_high_level_type high_level_type;
    // see <high_level_type>
    // for list(1), set(1), dict(2), function(1 + n), tuple(n)
    std::vector<SymbolType> son_types;
    // see <high_level_type>
    // for class
    std::vector<std::string> son_classes;

    // for basic

    // if <is_assigned> is `false`, and <high_level_type> is `use_basic`, then this is enabled
    // use <is_valued> if you need
    sym_basic_type basic_type;
    // see <basic_type>
    // must use <data>
    bool is_valued;
    // see <is_valued>
    // bool, int, double or char* (b, i, d, s)
    union data_t {
        bool b; int i; double d; char* s;
    } data;

    // <basic_type> = sym_basic_type::none
    SymbolType();
    // <basic_type> = input type
    SymbolType(sym_basic_type type);
    // <basic_type> = input type, is_valued, data = input data
    SymbolType(sym_basic_type type, SymbolType::data_t data);

    std::string to_string() const;
};

// please make sure name is valid.
SymbolType make_sym_assign(const std::string& name);
SymbolType make_sym_basic(sym_basic_type type);
SymbolType make_sym_basic_valued(sym_basic_type type, SymbolType::data_t data);
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

class SymbolTableBlockStack {
private:
    SymbolTableNode* now;
    std::stack<std::unique_ptr<SymbolTableNode>> node_buff;
    std::string last_update_name;
public:
    SymbolTableBlockStack();
    void goto_inner_block();
    void goto_outside_block();
    void update(const std::string& name, const SymbolType& type);
    // last update name, please make sure it is in.
    std::string last_update_to_string();
    bool del(const std::string& name);
    bool is_in_and_get(const std::string& name, SymbolType& result);
};