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

    void show_welcome() {
        std::cout << welcome;
    }

    void show_help() {
        std::cout << help;
    }

    void generate_help_occured() {
        help_occured = true;
    }

    void generate_error_not_find_short(const std::string& flag) {
        error = true;
        error_string = "cannot find short flag '" + flag + "'";
    }

    void generate_error_not_find_long(const std::string& flag) {
        error = true;
        error_string = "cannot find long flag '" + flag + "'";
    }

    void generate_error_no_arg_short(const std::string& flag) {
        error = true;
        error_string = "short flag '" + flag + "' requires argument, but cannot find";
    }

    void generate_error_no_arg_long(const std::string& flag) {
        error = true;
        error_string = "long flag '" + flag + "' requires argument, but cannot find";
    }

    void generate_error_more_arg_short(const std::string& flag, const std::string& arg) {
        error = true;
        error_string = "short flag '" + flag + "' does not require argument, but find '" + arg + "'";
    }

    static bool is_arg_flag(const std::string& argv) {
        if (argv == "--" || argv == "-") return false;
        if (argv.at(0) == '-') return true;
        return false;
    }

public:


// warning: INCOMPATIBLE CODE BEGIN

    ShellConfig() {
        flag_short_no_arg["h"] = flags::help;
        flag_short_with_arg["d"] = flags::debug;
        flag_short_with_arg["o"] = flags::out;
        flag_short_with_arg["O"] = flags::optimize;
        flag_short_no_arg["S"] = flags::assembly;

        flag_long_no_arg["help"] = flags::help;
        flag_long_with_arg["debug"] = flags::debug;
        flag_long_with_arg["out"] = flags::out;
        flag_long_with_arg["optimize"] = flags::optimize;
        flag_long_no_arg["assembly"] = flags::assembly;

        help = welcome =
R"(
Welcome to use Tastror's Compiler!

use
    compiler -h
    compiler <input_file> [-d <debug_mode>] [<debug_output_file>] [-S] [-o <output_file>] [-On (-O1, -O2)]
to run, such as
    compiler mytest.py -d ast ast.png -S -o result.s -O2

additionally,
    '-h' can be replaced by '--help'
    '<debug_mode>' can be: shell, lex, parse, ast, sym, ir, cfg, asm
    '-O' can be replaced by '--optimize' (-O1, -O 1, --optimize 1)
    '-d' can be replaced by '--debug'
    '-S' can be replaced by '--assembly'
    '-o' can be replaced by '--out'

    '<debug_output_file>' only works when you specify '<debug_mode>'
    '-o <output_file>' only works when you specify '-S'

flags' order does not matter, you can choose any order you like
)";
    };

    debug debug_type() {
        std::string&& type_str = get_flag_arg(flags::debug);
        if (type_str == "shell") {
            return debug::shell;
        } else if (type_str == "lex") {
            return debug::lex;
        } else if (type_str == "parse") {
            return debug::parse;
        } else if (type_str == "ast") {
            return debug::ast_graph;
        } else if (type_str == "sym") {
            return debug::symbol;
        } else if (type_str == "ir") {
            return debug::ir;
        } else if (type_str == "cfg") {
            return debug::control_graph;
        } else if (type_str == "asm") {
            return debug::assembly;
        } else {
            return debug::none;
        }
    }

// warning: INCOMPATIBLE CODE END


    bool is_help_occured() {
        return help_occured;
    }

    bool is_error() {
        return error;
    }

    std::string error_message() {
        return error_string;
    }

    std::string get_normal_input(std::size_t index = 0) {
        if (index > normal_input.size())
            return "";
        return normal_input.at(index);
    }

    bool is_flag_occured(flags flag) {
        if (
            flag_input_with_arg.find(flag) == flag_input_with_arg.end() &&
            flag_input_no_arg.find(flag) == flag_input_no_arg.end()
        ) {
            return false;
        }
        return true;
    }

    std::string get_flag_arg(flags flag) {
        if (flag_input_with_arg.find(flag) != flag_input_with_arg.end()) {
            return flag_input_with_arg[flag];
        }
        return std::string();
    }

    std::string detail_message() {
        std::string res = "";
        res += "designed flags:\n";
        res += "\tshort flag with no argument:\n";
        for (const auto& [k, v] : flag_short_no_arg) {
            res += "\t\t-" + k + " (enum flags int = " + std::to_string(int(v)) + ")\n";
        }
        res += "\tshort flag with argument:\n";
        for (const auto& [k, v] : flag_short_with_arg) {
            res += "\t\t-" + k + " (enum flags int = " + std::to_string(int(v)) + ")\n";
        }
        res += "\tlong flag with no argument:\n";
        for (const auto& [k, v] : flag_long_no_arg) {
            res += "\t\t--" + k + " (enum flags int = " + std::to_string(int(v)) + ")\n";
        }
        res += "\tlong flag with argument:\n";
        for (const auto& [k, v] : flag_long_with_arg) {
            res += "\t\t--" + k + " (enum flags int = " + std::to_string(int(v)) + ")\n";
        }
        res += "\nreal input flags:\n";
        res += "\tnormal input:\n";
        for (const auto& v : normal_input) {
            res += "\t\t" + v + "\n";
        }
        res += "\tflag input with no argument:\n";
        for (const auto& v : flag_input_no_arg) {
            res += "\t\tenum flags int: " + std::to_string(int(v)) + "\n";
        }
        res += "\tflag input with argument:\n";
        for (const auto& [k, v] : flag_input_with_arg) {
            res += "\t\tenum flags int: " + std::to_string(int(k)) + ", arg: " + v + "\n";
        }
        return res;
    }

    void arg_parse(int argc, char** argv) {

        // no args
        if (argc <= 1) {
            show_welcome();
            generate_help_occured();
            return;
        }

        // has args
        for (int i = 1; i < argc; ++i) {
            std::string name(argv[i]);

            // -f, -fxxx, --flag
            if (is_arg_flag(name)) {

                // --flag
                // --flag xxx
                if (name.size() > 2 && name.at(1) == '-') {
                    std::string flag_name = name.substr(2);
                    std::string arg_name;

                    auto no_arg_find = flag_long_no_arg.find(flag_name);
                    auto with_arg_find = flag_long_with_arg.find(flag_name);

                    // --unexist_flag
                    if (no_arg_find == flag_long_no_arg.end() && with_arg_find == flag_long_with_arg.end()) {
                        generate_error_not_find_long(flag_name);
                        return;
                    }

                    // --flag
                    else if (no_arg_find != flag_long_no_arg.end()) {
                        if (flag_long_no_arg[flag_name] == flags::help) {
                            show_help();
                            generate_help_occured();
                            return;
                        }
                        flag_input_no_arg.insert(flag_long_no_arg[flag_name]);
                    }

                     // --flag xxx
                    else if (with_arg_find != flag_long_with_arg.end()) {
                        i++;
                        if (i >= argc || is_arg_flag(std::string(argv[i]))) {
                            generate_error_no_arg_long(flag_name);
                            return;
                        }
                        arg_name = std::string(argv[i]);
                        flag_input_with_arg[flag_long_with_arg[flag_name]] = arg_name;
                    }
                }

                // -f
                // -fxxx
                // -f xxx
                else {
                    std::string flag_name = name.substr(1, 1);
                    std::string arg_name;

                    if (name.size() > 2) {
                        arg_name = name.substr(2);
                    }

                    auto no_arg_find = flag_short_no_arg.find(flag_name);
                    auto with_arg_find = flag_short_with_arg.find(flag_name);

                    // -unexist_f
                    if (no_arg_find == flag_short_no_arg.end() && with_arg_find == flag_short_with_arg.end()) {
                        generate_error_not_find_short(flag_name);
                        return;
                    }

                    // -f
                    else if (no_arg_find != flag_short_no_arg.end()) {
                        if (flag_short_no_arg[flag_name] == flags::help) {
                            show_help();
                            generate_help_occured();
                            return;
                        }
                        if (arg_name != "") {
                            generate_error_more_arg_short(flag_name, arg_name);
                            return;
                        }
                        flag_input_no_arg.insert(flag_short_no_arg[flag_name]);
                    }

                     // -fxxx and -f xxx
                    else if (with_arg_find != flag_short_with_arg.end()) {
                        if (arg_name == "") {
                            i++;
                            if (i >= argc || is_arg_flag(std::string(argv[i]))) {
                                generate_error_no_arg_short(flag_name);
                                return;
                            }
                            arg_name = std::string(argv[i]);
                        }
                        flag_input_with_arg[flag_short_with_arg[flag_name]] = arg_name;
                    }
                }
            }

            // -, --, other
            else {
                normal_input.push_back(name);
            }
        }
    }
};