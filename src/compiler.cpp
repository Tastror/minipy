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
#include "compiler.h"



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



    // begin debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_off;
    if (shell_config.debug_type() == debug::shell) {
        stdlog::log.add_temp_output_file(debug_file);
        stdlog::log << stdlog::temp_files_on;
    }
    
    // debug print
    stdlog::log << stdlog::debug << "shell_config.detail_message() begin" << stdlog::endl;
    stdlog::log << stdlog::std << shell_config.detail_message() << stdlog::endl;

    // end debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_on;
    if (shell_config.debug_type() == debug::shell) {
        stdlog::log.del_all_temp_output_file();
        stdlog::log << stdlog::temp_files_off;
    }

    stdlog::log << stdlog::std << "           shell parsing done -> |end|" << stdlog::endl;





    // <<< 2 & 3 >>>

    // lexer & parser
    // lexer and parser, use yyparse to do two thing together

    stdlog::log << stdlog::std << "|begin| -> lexing & parsing begin" << stdlog::endl;

    // begin debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_off;
    if (shell_config.debug_type() == debug::lex) {
        stdlog::log.add_temp_output_file(debug_file);
        stdlog::log << stdlog::temp_files_on;
    }

    // run & debug print
    AstNode* ast_head = nullptr;
    yyin = input_file_ptr;
    stdlog::log << stdlog::debug << "yyparse begin" << stdlog::endl;
    yyparse(ast_head);

    // end debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_on;
    if (shell_config.debug_type() == debug::lex) {
        stdlog::log.del_all_temp_output_file();
        stdlog::log << stdlog::temp_files_off;
    }

    stdlog::log << stdlog::std << "           lexing & parsing done -> |end|" << stdlog::endl;



    // begin debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_off;
    if (shell_config.debug_type() == debug::parse || shell_config.debug_type() == debug::ast) {
        stdlog::log.add_temp_output_file(debug_file);
        stdlog::log << stdlog::temp_files_on;
    }

    stdlog::log << stdlog::debug << "log_ast begin" << stdlog::endl;
    log_ast(ast_head);

    // end debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_on;
    if (shell_config.debug_type() == debug::parse || shell_config.debug_type() == debug::ast) {
        stdlog::log.del_all_temp_output_file();
        stdlog::log << stdlog::temp_files_off;
    }





    // <<< 4 & 5 >>>

    // semantic & ir

    stdlog::log << stdlog::std << "|begin| -> symbol table & ir" << stdlog::endl;

    // begin debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_off;
    if (shell_config.debug_type() == debug::symbol) {
        stdlog::log.add_temp_output_file(debug_file);
        stdlog::log << stdlog::temp_files_on;
    }

    SymbolTable symbol_table;
    search_and_update_symboltable(symbol_table, ast_head);

    // end debug print
    if (!shell_config.is_flag_occured(flags::show)) stdlog::log << stdlog::stdout_on;
    if (shell_config.debug_type() == debug::symbol) {
        stdlog::log.del_all_temp_output_file();
        stdlog::log << stdlog::temp_files_off;
    }

    stdlog::log << stdlog::std << "           symbol table & ir -> |end|" << stdlog::endl;



    return 0;
}