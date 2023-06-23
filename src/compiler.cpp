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

    // default values

    std::string default_log_file_path = "log.txt";
    std::string default_output_file_path = "out.s";
    std::string default_debug_file_dir = "debug/";
    std::string default_debug_file_suffix = ".txt";



    // <<< 1 >>>

    // init log

    // all outputs will be dumped to "default_log_file_path"

    // open the log file
    std::ofstream log_file;
    log_file.open(default_log_file_path);
    if (!log_file.is_open()) {
        stdlog::log << stdlog::stdout_on << stdlog::error
            << "log file '" << default_log_file_path << "' cannot open"
            << stdlog::endl;
        return 0;
    }

    // initialize the stdlog::log (logstream)
    stdlog::log.change_output_file(log_file);
    stdlog::log << stdlog::stdout_on << stdlog::file_on;



    // <<< 2 >>>

    // shell

    // parse cmd input
    ShellConfig shell_config;
    shell_config.arg_parse(argc, argv);

    // deal "error, help, time" first
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

    // why put it here? 'cause these should be printed after <flags::time> is determined
    stdlog::log << stdlog::info << "other information will output to " << default_log_file_path << stdlog::endl;
    stdlog::log << stdlog::std << "|begin| -> shell parsing begin" << stdlog::endl;

    // 3 files. input, output and debug files
    FILE* input_file_ptr;  // since yyin use FILE*
    std::ofstream output_file;
    std::ofstream debug_file;

    // open the input file
    std::string input_file_path = shell_config.get_normal_input(0);
    if (input_file_path == "") {
        stdlog::log << stdlog::warning << "no file specified" << stdlog::endl;
        return 0;
    }
    if ((input_file_ptr = fopen(input_file_path.c_str(), "r")) == nullptr) {
        stdlog::log << stdlog::error << "input file '" << input_file_path << "' cannot open" << stdlog::endl;
        return 0;
    }

    // open the output file
    if (shell_config.is_flag_occured(flags::assembly)) {
        std::string output_file_path = shell_config.get_flag_arg(flags::out);
        if (output_file_path == "") output_file_path = default_output_file_path;
        output_file.open(output_file_path);
        if (!output_file.is_open()) {
            stdlog::log << stdlog::error << "output file '" << output_file_path << "' cannot open" << stdlog::endl;
            return 0;
        }
        stdlog::log << stdlog::info << "assembly will output to " << output_file_path << stdlog::endl;
    }

    // open the debug file
    if (shell_config.is_flag_occured(flags::debug) && shell_config.debug_type() != debug::none) {
        std::string debug_file_path = shell_config.get_normal_input(1);
        if (debug_file_path == "") {
            debug_file_path =
                default_debug_file_dir +
                shell_config.get_flag_arg(flags::debug) +
                default_debug_file_suffix;
        }
        debug_file.open(debug_file_path);
        if (!debug_file.is_open()) {
            stdlog::log << stdlog::error << "output file '" << debug_file_path << "' cannot open" << stdlog::endl;
            return 0;
        }
        stdlog::log << stdlog::info << shell_config.get_flag_arg(flags::debug)
            << " debug information will output to " << debug_file_path << stdlog::endl;
    }

    // print detail message of shell

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::shell);
    
    stdlog::log << stdlog::debug << "shell_config.detail_message() begin" << stdlog::endl;
    stdlog::log << stdlog::std << shell_config.detail_message() << stdlog::endl;

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::shell);

    stdlog::log << stdlog::std << "           shell parsing done -> |end|" << stdlog::endl;



    // <<< 3 & 4 >>>

    // lexer & parser

    // use yyparse() to do lex (by flex) and parse (by bison)
    // result is the root of AST node, save in ast_head

    stdlog::log << stdlog::std << "|begin| -> lexing & parsing begin" << stdlog::endl;

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::lex);

    AstNode* ast_head = nullptr;
    yyin = input_file_ptr;
    stdlog::log << stdlog::debug << "yyparse begin" << stdlog::endl;
    yyparse(ast_head);

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::lex);

    stdlog::log << stdlog::std << "           lexing & parsing done -> |end|" << stdlog::endl;

    // print the AST tree for visualization

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



    // <<< 5 & 6 >>>

    // semantic & ir

    // search the AST tree to generate IR
    // result is vector of IR, save in ir_result

    stdlog::log << stdlog::std << "|begin| -> symbol table & ir" << stdlog::endl;

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::symbol);

    SymbolTable symbol_table;
    auto ir_result = search_astnode_update_symboltable_generate_ir(ast_head, symbol_table);

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::symbol);

    stdlog::log << stdlog::std << "           symbol table & ir -> |end|" << stdlog::endl;

    // print the IR vector for visualization
    // and save it to output file

    BEGIN_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::ir);

    for (const auto& i : ir_result) {
        stdlog::log << stdlog::info << i.to_string() << stdlog::endl;
        output_file << i.to_string() << std::endl;
    }

    END_DEBUG_PRINT_FILE(shell_config.debug_type() == debug::ir);

    return 0;
}