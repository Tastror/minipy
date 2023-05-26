#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>


// you only need to change:
//     enum class flags
//     enum class debug
//     ShellConfig::ShellConfig()
//     ShellConfig::debug_type()
// other code are compatible with all situation.


// warning: INCOMPATIBLE CODE BEGIN

enum class flags {help, debug, assembly, out, optimize};
enum class debug {none, shell, lex, parse, ast_graph, symbol, ir, control_graph, assembly};

// warning: INCOMPATIBLE CODE END


class ShellConfig {

private:
    std::unordered_map<std::string, flags> flag_short_no_arg;
    std::unordered_map<std::string, flags> flag_short_with_arg;
    std::unordered_map<std::string, flags> flag_long_no_arg;
    std::unordered_map<std::string, flags> flag_long_with_arg;

    std::vector<std::string> normal_input;
    std::set<flags> flag_input_no_arg;
    std::unordered_map<flags, std::string> flag_input_with_arg;

    bool help_occured = false;
    bool error = false;
    std::string error_string;

    std::string welcome, help;

    void show_welcome();

    void show_help();

    void generate_help_occured();

    void generate_error_not_find_short(const std::string& flag);

    void generate_error_not_find_long(const std::string& flag);

    void generate_error_no_arg_short(const std::string& flag);

    void generate_error_no_arg_long(const std::string& flag);

    void generate_error_more_arg_short(const std::string& flag, const std::string& arg);

    static bool is_arg_flag(const std::string& argv);

public:


// warning: INCOMPATIBLE CODE BEGIN

    ShellConfig();

    debug debug_type();

// warning: INCOMPATIBLE CODE END


    bool is_help_occured();

    bool is_error();

    std::string error_message();

    std::string get_normal_input(std::size_t index = 0);

    bool is_flag_occured(flags flag);

    std::string get_flag_arg(flags flag);

    std::string detail_message();

    void arg_parse(int argc, char** argv);

};