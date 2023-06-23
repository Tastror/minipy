#include <vector>
#include <string>
#include <memory>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"
#include "ir.h"

std::string ir_sentence::to_string() const {
    return "";
}

std::vector<ir_sentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTable& sym_table
) {
    std::vector<ir_sentence> res;
    return res;
}