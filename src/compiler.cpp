#include <iostream>
#include <string>

#include "compiler.h"
#include "shell.hpp"

int main(int argc, char** argv) {

    ShellConfig shell_config;
    shell_config.arg_parse(argc, argv);

    if (shell_config.is_error()) {
        std::cout << shell_config.error_message() << std::endl;
        return 0;
    }
    if (shell_config.is_help_occured()) {
        return 0;
    }
    if (shell_config.debug_type() == debug::shell) {
        std::cout << shell_config.detail_message();
    }

    
    return 0;
}