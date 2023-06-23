#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

#include "common.h"
#include "log.h"
#include "shell.h"
#include "lexer.h"
#include "parser.h"
#include "symbol.h"
#include "ir.h"
#include "compiler.h"

#define BEGIN_DEBUG_PRINT_FILE(condition) \
    do { \
        if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_off; \
        if (condition) { \
            stdlog::log.add_temp_output_file(debug_file); \
            stdlog::log << stdlog::temp_files_on; \
        } \
    } while (0)

#define END_DEBUG_PRINT_FILE(condition) \
    do { \
        if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_on; \
        if (condition) { \
            stdlog::log.del_all_temp_output_file(); \
            stdlog::log << stdlog::temp_files_off; \
        } \
    } while (0)


int main(int argc, char** argv) {

    // <<< 0 >>>

    // log and Logfile
    // untargeted output will be dumped in log.txt

    std::ofstream log_file;
    log_file.open("log.txt");
    stdlog::log << stdlog::stdout_on;
    if (!log_file.is_open()) {
        stdlog::log << stdlog::error << "log file 'log.txt' cannot open" << stdlog::endl;
        return 0;
    }
    stdlog::log.change_output_file(log_file);
    stdlog::log << stdlog::stdout_on << stdlog::file_on;





    // <<< 1 >>>

    // shell
    // parse the shell args to the program

    ShellConfig shell_config;
    shell_config.arg_parse(argc, argv);

    // error, help, time, show
    if (shell_config.is_error()) {
        stdlog::log << stdlog::error << shell_config.error_message() << stdlog::endl;
        return 0;
    }
    if (shell_config.is_help_occured()) {
        return 0;
    }
    if (shell_config.is_flag_occured(flags::time)) {
        stdlog::log << stdlog::add_time;
    } else {
        stdlog::log << stdlog::no_time;
    }

    // this two should output after <flags::time>
    stdlog::log << stdlog::info << "other information will output to log.txt" << stdlog::endl;
    stdlog::log << stdlog::std << "|begin| -> shell parsing begin" << stdlog::endl;

    // input (.py), output (.s) and debug file (.txt)
    FILE* input_file_ptr;
    std::ofstream output_file;
    std::ofstream debug_file;

    std::string input_filename = shell_config.get_normal_input(0);
    if (input_filename == "") {
        stdlog::log << stdlog::warning << "no file specified" << stdlog::endl;
        return 0;
    }
    if ((input_file_ptr = fopen(input_filename.c_str(), "r")) == nullptr) {
        stdlog::log << stdlog::error << "input file '" << input_filename << "' cannot open" << stdlog::endl;
        return 0;
    }

    if (shell_config.is_flag_occured(flags::assembly)) {
        std::string output_filename = shell_config.get_flag_arg(flags::out);
        if (output_filename == "") output_filename = "out.s";
        output_file.open(output_filename);
        if (!output_file.is_open()) {
            stdlog::log << stdlog::error << "output file '" << output_filename << "' cannot open" << stdlog::endl;
            return 0;
        }
        stdlog::log << stdlog::info << "assembly will output to " << output_filename << stdlog::endl;
    }

    if (shell_config.is_flag_occured(flags::debug) && shell_config.debug_type() != debug::none) {
        std::string debug_filename = shell_config.get_normal_input(1);
        if (debug_filename == "") {
            debug_filename = "debug/" + shell_config.get_flag_arg(flags::debug) + ".txt";
        }
        debug_file.open(debug_filename);
        if (!debug_file.is_open()) {
            stdlog::log << stdlog::error << "output file '" << debug_filename << "' cannot open" << stdlog::endl;
            return 0;
        }
        stdlog::log << stdlog::info << shell_config.get_flag_arg(flags::debug)
            << " debug information will output to " << debug_filename << stdlog::endl;
    }

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::shell);
    
    stdlog::log << stdlog::debug << "shell_config.detail_message() begin" << stdlog::endl;
    stdlog::log << stdlog::std << shell_config.detail_message() << stdlog::endl;

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::shell);

    stdlog::log << stdlog::std << "           shell parsing done -> |end|" << stdlog::endl;





    // <<< 2 & 3 >>>

    // lexer & parser
    // lexer and parser, use yyparse to do two thing together

    stdlog::log << stdlog::std << "|begin| -> lexing & parsing begin" << stdlog::endl;

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::lex);

    AstNode* ast_head = nullptr;
    yyin = input_file_ptr;
    stdlog::log << stdlog::debug << "yyparse begin" << stdlog::endl;
    yyparse(ast_head);

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::lex);

    stdlog::log << stdlog::std << "           lexing & parsing done -> |end|" << stdlog::endl;

    BEGIN_DEBUG_PRINT_FILE(
        shell_config.debug_type() == debug::parse ||
        shell_config.debug_type() == debug::ast
    );

    stdlog::log << stdlog::debug << "log_ast begin" << stdlog::endl;
    log_ast(ast_head);

    END_DEBUG_PRINT_FILE(
        shell_config.debug_type() == debug::parse ||
        shell_config.debug_type() == debug::ast
    );





    // <<< 4 & 5 >>>

    // semantic & ir

    stdlog::log << stdlog::std << "|begin| -> symbol table & ir" << stdlog::endl;

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::symbol);

    SymbolTable symbol_table;
    auto ir_result = search_astnode_update_symboltable_generate_ir(ast_head, symbol_table);

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::symbol);

    stdlog::log << stdlog::std << "           symbol table & ir -> |end|" << stdlog::endl;

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::ir);

    for (const auto& i : ir_result) {
        stdlog::log << stdlog::info << i.to_string() << stdlog::endl;
    }

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::ir);

    return 0;
}