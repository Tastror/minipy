#include <vector>
#include <string>
#include <memory>

#include "timing.h"
#include "log.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"
#include "ir.h"

Reg::Reg() {
    id = 0;
}

int Reg::get_int() {
    return ++id;
}

std::string Reg::get_str() {
    return std::to_string(++id);
}

std::string ir_sentence::to_string() const {
    return "";
}

void sausgi(AstNode*& astnode_now, SymbolTable& sym_table, std::vector<ir_sentence>& ir_vec) {
    if (astnode_now == nullptr) return;
    switch (astnode_now->type) {
    case astnode_type::statements:
        for (auto i : astnode_now->sons) {
            sausgi(i, sym_table, ir_vec);
        }
        break;
    case astnode_type::bin_op_add:
        break;
    }
}

std::vector<ir_sentence> search_astnode_update_symboltable_generate_ir(
    AstNode*& ast_root, SymbolTable& sym_table
) {
    std::vector<ir_sentence> res;
    Reg reg;
    sausgi(ast_root, sym_table, res);
    return res;
}