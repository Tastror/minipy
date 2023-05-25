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
    std::ofstream debug_file;

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

    if (shell_config.is_flag_occured(flags::debug)) {
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


    // shell output
    if (shell_config.debug_type() == debug::shell) {
        // Logger << Log::std << shell_config.detail_message() << Log::flush;
        debug_file << shell_config.detail_message() << std::flush;
    }


    return 0;
}