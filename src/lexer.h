#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

#include "timing.h"
#include "log.h"

extern int yycolumnno;
extern int yylineno;
extern size_t last_string_length;
extern std::string last_string;

enum class none {};



// --- 2 ---
// type to_string and to_num

// token only has indent
//    indent_num.relative_depth > 0 means indent in astnode, 
//    indent_num.relative_depth < 0 means dedent in astnode,
//    indent_num.relative_depth == 0 means nothing in astnode.

// "" or '' will lexerize to <bracket: "> <strtext: (nothing)> <bracket: "> since flex does this more naturally...
// but in ast, we'll still add rule <bracket: "> <bracket: ">

enum class token_type {
    error, newline, indent, identifier, integer, floats, strtext, delimiter, bracket, operators, keyword,
};

std::string to_string(token_type a);

uint64_t translate_python_int(const std::string& str);



// --- 3 ---
// class (include class to_string)

class Token {
public:
    token_type type;

    uint32_t lineno;
    uint32_t columnno;

    // bug occurred when use union, so recommend struct
    struct content_t {

        std::string message;  // error (error message), strtext (string text message)

        none no;  // newline

        struct indent_num_t {
            uint64_t space_num;
            uint64_t tab_num;
            uint64_t absolute_depth;
            int64_t relative_depth;
        } indent_num;  // indent

        union data_t {
            int64_t int_num;  
            double double_num;
        } data;  // integer, floats

        std::string name;  // identifier, delimiter, bracket, operators, keyword

        content_t();
        ~content_t();
    } content;

    Token();

    Token(const Token& other);
    Token(Token&& other);
    Token& operator=(Token&& other);
    Token& operator=(const Token& other);

    std::string to_string() const;
};



// --- 1 ---
// buff and make

Token* make_token();
void delete_token(Token*& del);
