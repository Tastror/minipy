#include <iostream>
#include <string>
#include <fstream>

#include "compiler.h"
#include "log.hpp"
#include "shell.hpp"

int main(int argc, char** argv) {


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


    // file
    std::ifstream input_file;
    std::ofstream output_file;
    std::ofstream debug_output_file;

    std::string input_filename = shell_config.get_normal_input(0);
    if (input_filename == "") {
        Logger << Log::warning << "no file specified" << Log::endl;
        return 0;
    }
    input_file.open(input_filename);
    if (!input_file.is_open()) {
        Logger << Log::error << "input file '" << input_filename << "' cannot open" << Log::endl;
        return 0;
    }

    std::string output_filename = shell_config.get_flag_arg(flags::out);
    if (shell_config.is_flag_occured(flags::assembly)) {
        if (output_filename == "") output_filename = "debug/out.s";
        output_file.open(output_filename);
        if (!output_file.is_open()) {
            Logger << Log::error << "output file '" << output_filename << "' cannot open" << Log::endl;
            return 0;
        }
    }

    std::string debug_output_filename = shell_config.get_normal_input(1);
    if (shell_config.is_flag_occured(flags::debug)) {
        if (debug_output_filename == "") {
            debug_output_filename = "debug/" + shell_config.get_flag_arg(flags::debug);
            if (shell_config.debug_type() == debug::ast_graph || shell_config.debug_type() == debug::control_graph) {
                debug_output_filename += ".png";
            } else {
                debug_output_filename += ".txt";
            }
        }
        debug_output_file.open(debug_output_filename);
        if (!output_file.is_open()) {
            Logger << Log::error << "output file '" << debug_output_filename << "' cannot open" << Log::endl;
            return 0;
        }
    }


    // shell output
    if (shell_config.debug_type() == debug::shell) {
        Logger << Log::std << shell_config.detail_message() << Log::flush;
        debug_output_file << shell_config.detail_message() << std::flush;
    }


    return 0;
}