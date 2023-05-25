#include <iostream>
#include <string>
#include <fstream>

#include "compiler.h"
#include "log.hpp"
#include "shell.hpp"

int main(int argc, char** argv) {

    ShellConfig shell_config;
    shell_config.arg_parse(argc, argv);

    if (shell_config.is_error()) {
        Logger << Log::error << shell_config.error_message() << Log::endl;
        return 0;
    }
    if (shell_config.is_help_occured()) {
        return 0;
    }
    if (shell_config.get_normal_input(0) == "") {
        Logger << Log::warning << "no file specified" << Log::endl;
        return 0;
    }
    std::ifstream input_file;
    input_file.open(shell_config.get_normal_input(0));
    if (!input_file.is_open()) {
        Logger << Log::error << "file '" << shell_config.get_normal_input(0) << "' cannot open" << Log::endl;
        return 0;
    }

    // if (shell_config.get_normal_input(1))
    // std::ofstream file;
    // file.open();

    if (shell_config.debug_type() == debug::shell) {
        Logger << Log::info << shell_config.detail_message() << Log::endl;
    }


    return 0;
}