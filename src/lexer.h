#pragma once

#include <cstdint>
#include <string>

#include "common.h"

extern int yycolumnno;
extern int yylineno;
extern size_t last_string_length;
extern std::string last_string;

enum class token_type {
    error, identifier, integer, floats, operators, delimiter, keyword, indent, newline
};

uint64_t translate_python_int(const std::string& str);

struct Token {
    token_type type;

    uint32_t lineno;
    uint32_t columnno;

    struct content_t {
        none no;  // <- newline
        std::string message;  // <- error (error message)
        std::string name;  // <- identifier, operators, delimiter, keyword
        struct indent_num_t {
            uint64_t space_num;
            uint64_t tab_num;
        } indent_num;  // <- indent
        union data_t {
            int64_t int_num;  
            double double_num;
        } data;  // <- integer, floats

        // class with none-trivial union should implement those functions
        content_t();
        ~content_t();
    } content;

    // class with none-trivial union should implement those functions
    Token();
    ~Token();
    Token(const Token& other);
    Token(Token&& other);
    Token& operator=(Token&& other);
    Token& operator=(const Token& other);
};