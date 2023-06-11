#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

#include "compiler.h"
#include "log.h"
#include "shell.h"
#include "parser.h"

int main(int argc, char** argv) {

    // Logger and Logfile
    // untargeted output will be dumped in log.txt
    std::ofstream log_file;
    log_file.open("log.txt");
    if (!log_file.is_open()) {
        Logger << Log::error << "log file 'log.txt' cannot open" << Log::endl;
        return 0;
    }
    Logger.change_output_file(log_file);
    Logger << Log::to_stdout_and_file;


    // shell
    ShellConfig shell_config;
    shell_config.arg_parse(argc, argv);

    if (shell_config.is_error()) {
        Logger << Log::error << shell_config.error_message() << Log::endl;
        return 0;
    }
    if (shell_config.is_help_occured()) {
        return 0;
    }
    if (shell_config.is_flag_occured(flags::time)) {
        Log::add_time = true;
    }


    // input (.py), output (.s) and debug file (.txt / .png)
    FILE* input_file_ptr;
    std::ofstream output_file;
    std::ofstream debug_file;

    std::string input_filename = shell_config.get_normal_input(0);
    if (input_filename == "") {
        Logger << Log::warning << "no file specified" << Log::endl;
        return 0;
    }
    if ((input_file_ptr = fopen(input_filename.c_str(), "r")) == nullptr) {
        Logger << Log::error << "input file '" << input_filename << "' cannot open" << Log::endl;
        return 0;
    }

    if (shell_config.is_flag_occured(flags::assembly)) {
        std::string output_filename = shell_config.get_flag_arg(flags::out);
        if (output_filename == "") output_filename = "debug/out.s";
        output_file.open(output_filename);
        if (!output_file.is_open()) {
            Logger << Log::error << "output file '" << output_filename << "' cannot open" << Log::endl;
            return 0;
        }
        Logger << Log::info << "assembly will output to " << output_filename << Log::endl;
    }

    if (shell_config.is_flag_occured(flags::debug) && shell_config.debug_type() != debug::none) {
        std::string debug_filename = shell_config.get_normal_input(1);
        if (debug_filename == "") {
            debug_filename = "debug/" + shell_config.get_flag_arg(flags::debug);
            if (shell_config.debug_type() == debug::ast_graph || shell_config.debug_type() == debug::control_graph) {
                debug_filename += ".png";
            } else {
                debug_filename += ".txt";
            }
        }
        debug_file.open(debug_filename);
        if (!debug_file.is_open()) {
            Logger << Log::error << "output file '" << debug_filename << "' cannot open" << Log::endl;
            return 0;
        }
        Logger << Log::info << shell_config.get_flag_arg(flags::debug)
            << " debug information will output to " << debug_filename << Log::endl;
    }

    Logger << Log::info << "other information will output to log.txt" << Log::endl;


    // shell output
    Logger << Log::std << "-> shell parsing done" << Log::endl;
    if (shell_config.debug_type() == debug::shell) {
        Logger.add_temp_output_file(debug_file);
    }
    Logger << Log::to_file;

    Logger << Log::std << shell_config.detail_message() << Log::endl;
    
    Logger.del_all_temp_output_file();
    Logger << Log::to_stdout_and_file;


    // lexer & parser
    Logger << Log::std << "-> lexing & parsing begin" << Log::endl;
    if (shell_config.debug_type() == debug::lex || shell_config.debug_type() == debug::parse) {
        Logger.add_temp_output_file(debug_file);
    }
    // Logger << Log::to_file;
    Logger << Log::to_stdout_and_file;

    yyin = input_file_ptr;
    auto ast_head = make_astnode();
    yyparse(ast_head);
    log_ast(ast_head);

    Logger.del_all_temp_output_file();
    Logger << Log::to_stdout_and_file;


    // use ast_head next

    return 0;
}