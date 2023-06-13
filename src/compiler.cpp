#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

#include "compiler.h"
#include "log.h"
#include "shell.h"
#include "parser.h"



int main(int argc, char** argv) {



    // <<< 0 >>>

    // Logger and Logfile
    // untargeted output will be dumped in log.txt

    std::ofstream log_file;
    log_file.open("log.txt");
    Logger << Log::to_stdout;
    if (!log_file.is_open()) {
        Logger << Log::error << "log file 'log.txt' cannot open" << Log::endl;
        return 0;
    }
    Logger.change_output_file(log_file);
    Logger << Log::to_stdout_and_file;





    // <<< 1 >>>

    // shell
    // parse the shell args to the program

    ShellConfig shell_config;
    shell_config.arg_parse(argc, argv);

    auto cmd_print = Log::to_file;

    // error, help, time, show
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
    if (shell_config.is_flag_occured(flags::show)) {
        cmd_print = Log::to_stdout_and_file;
    }

    // this two should output after <flags::time>
    Logger << Log::info << "other information will output to log.txt" << Log::endl;
    Logger << Log::std << "|begin| -> shell parsing begin" << Log::endl;

    // input (.py), output (.s) and debug file (.txt)
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
        if (output_filename == "") output_filename = "out.s";
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
            debug_filename = "debug/" + shell_config.get_flag_arg(flags::debug) + ".txt";
        }
        debug_file.open(debug_filename);
        if (!debug_file.is_open()) {
            Logger << Log::error << "output file '" << debug_filename << "' cannot open" << Log::endl;
            return 0;
        }
        Logger << Log::info << shell_config.get_flag_arg(flags::debug)
            << " debug information will output to " << debug_filename << Log::endl;
    }

    // begin debug print
    if (shell_config.debug_type() == debug::shell)
        Logger.add_temp_output_file(debug_file);
    Logger << cmd_print;
    
    // debug print
    Logger << Log::debug << "shell_config.detail_message() begin" << Log::endl;
    Logger << Log::std << shell_config.detail_message() << Log::endl;

    // end debug print
    Logger.del_all_temp_output_file();
    Logger << Log::to_stdout_and_file;

    Logger << Log::std << "           shell parsing done -> |end|" << Log::endl;





    // <<< 2 & 3 >>>

    // lexer & parser
    // lexer and parser, use yyparse to do two thing together

    Logger << Log::std << "|begin| -> lexing & parsing begin" << Log::endl;

    // begin debug print
    if (shell_config.debug_type() == debug::lex) 
        Logger.add_temp_output_file(debug_file);
    Logger << cmd_print;

    // run & debug print
    auto ast_head = make_astnode();
    yyin = input_file_ptr;
    Logger << Log::debug << "yyparse begin" << Log::endl;
    yyparse(ast_head);

    // end debug print
    Logger.del_all_temp_output_file();
    Logger << Log::to_stdout_and_file;

    Logger << Log::std << "           lexing & parsing done -> |end|" << Log::endl;



    // begin debug print
    if (shell_config.debug_type() == debug::parse || shell_config.debug_type() == debug::ast) 
        Logger.add_temp_output_file(debug_file);
    Logger << cmd_print;

    Logger << Log::debug << "log_ast begin" << Log::endl;
    log_ast(ast_head);

    // end debug print
    Logger.del_all_temp_output_file();
    Logger << Log::to_stdout_and_file;





    // <<< 4 & 5 >>>

    // semantic & optimize

    ast_head = nullptr;



    return 0;
}