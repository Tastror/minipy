#include <cstdint>
#include <string>

#include "common.h"
#include "lexer.h"



// --- 1 ---
// buff and make

std::vector<std::unique_ptr<Token>> token_buff;

Token* make_token() {
    token_buff.push_back(std::make_unique<Token>());
    return token_buff.back().get();
}



// --- 2 ---
// type to_string and to_num

std::string std::to_string(token_type tt) {
    switch (tt) {
        case token_type::error: return "error";
        case token_type::newline: return "newline";
        case token_type::indent: return "indent";
        case token_type::identifier: return "identifier";
        case token_type::integer: return "integer";
        case token_type::floats: return "floats";
        case token_type::strtext: return "strtext";
        case token_type::delimiter: return "delimiter";
        case token_type::bracket: return "bracket";
        case token_type::operators: return "operators";
        case token_type::keyword: return "keyword"; 
    }
    return "";
}

uint64_t translate_python_int(const std::string& str) {
    if (str.substr(0, 2) == "0x") {
        return std::stoul(str.substr(2), nullptr, 16);
    } else if (str.substr(0, 2) == "0o") {
        return std::stoul(str.substr(2), nullptr, 8);
    } else if (str.substr(0, 2) == "0b") {
        return std::stoul(str.substr(2), nullptr, 2);
    } else {
        return std::stoul(str, nullptr, 10);
    }
}



// --- 3 ---
// class (include class to_string)

// class with none-trivial union should implement those functions

Token::content_t::content_t() {};
Token::content_t::~content_t() {};

Token::Token() {};
Token::~Token() {};

Token::Token(const Token& other) {
    this->type = other.type;
    this->lineno = other.lineno;
    this->columnno = other.columnno;
    switch (other.type) {
    case token_type::error:
    case token_type::strtext:
        this->content.message = other.content.message;
        break;
    case token_type::newline:
        this->content.no = other.content.no;
        break;
    case token_type::indent:
        this->content.indent_num = other.content.indent_num;
        break;
    case token_type::integer:
    case token_type::floats:
        this->content.data = other.content.data;
        break;
    case token_type::identifier:
    case token_type::delimiter:
    case token_type::bracket:
    case token_type::operators:
    case token_type::keyword:
        this->content.name = other.content.name;
        break;
    }
}

Token& Token::operator=(Token&& other) {
    this->type = std::move(other.type);
    this->lineno = std::move(other.lineno);
    this->columnno = std::move(other.columnno);
    switch (other.type) {
    case token_type::error:
    case token_type::strtext:
        this->content.message = std::move(other.content.message);
        break;
    case token_type::newline:
        this->content.no = std::move(other.content.no);
        break;
    case token_type::indent:
        this->content.indent_num = std::move(other.content.indent_num);
        break;
    case token_type::integer:
    case token_type::floats:
        this->content.data = std::move(other.content.data);
        break;
    case token_type::identifier:
    case token_type::delimiter:
    case token_type::bracket:
    case token_type::operators:
    case token_type::keyword:
        this->content.name = std::move(other.content.name);
        break;
    }
    return *this;
}

Token::Token(Token&& other) {
    *this = std::move(other);
}

Token& Token::operator=(const Token& other) {
    Token temp(other);
    *this = std::move(temp);
    return *this;
};

std::string Token::to_string() {
    std::string res;
    res += std::to_string(this->type) + ", ";
    res += std::to_string(this->lineno) + "-";
    res += std::to_string(this->columnno);
    switch (this->type) {
    case token_type::error:
    case token_type::strtext:
        res += ", " + this->content.message;
        break;
    case token_type::newline:
        break;
    case token_type::indent:
        res += ", "
            "space: " + std::to_string(this->content.indent_num.space_num) +
            ", tab: " + std::to_string(this->content.indent_num.tab_num) +
            ", absolute: " + std::to_string(this->content.indent_num.absolute_depth) +
            ", relative: " + std::to_string(this->content.indent_num.relative_depth) ;
        break;
    case token_type::integer:
        res += ", " + std::to_string(this->content.data.int_num);
        break;
    case token_type::floats:
        res += ", " + std::to_string(this->content.data.double_num);
        break;
    case token_type::identifier:
    case token_type::delimiter:
    case token_type::bracket:
    case token_type::operators:
    case token_type::keyword:
        res += ", " + this->content.name;
        break;
    }
    return res;
}
