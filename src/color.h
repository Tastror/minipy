#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <type_traits>
#include <utility>
#include <windows.h>

namespace hue
{
    constexpr int DEFAULT_COLOR = 7;
    constexpr int BAD_COLOR = -256;

    extern const std::map<std::string, int> CODES;

    extern const std::map<int, std::string> NAMES;

    inline bool is_good(int c);

    inline int itoc(int c);

    inline int itoc(int a, int b);

    // std::string to color
    int stoc(std::string a);

    int stoc(std::string a, std::string b);

    std::string ctos(int c);

    int get();

    int get_text();

    int get_background();

    void set(int c);

    void set(int a, int b);

    void set(std::string a, std::string b);

    void set_text(std::string a);

    void set_background(std::string b);

    void reset();

    int invert(int c);

    std::ostream & reset(std::ostream &);
    std::ostream & black(std::ostream & os);
    std::ostream & blue(std::ostream & os);
    std::ostream & green(std::ostream & os);
    std::ostream & aqua(std::ostream & os);
    std::ostream & red(std::ostream & os);
    std::ostream & purple(std::ostream & os);
    std::ostream & yellow(std::ostream & os);
    std::ostream & white(std::ostream & os);
    std::ostream & grey(std::ostream & os);
    std::ostream & light_blue(std::ostream & os);
    std::ostream & light_green(std::ostream & os);
    std::ostream & light_aqua(std::ostream & os);
    std::ostream & light_red(std::ostream & os);
    std::ostream & light_purple(std::ostream & os);
    std::ostream & light_yellow(std::ostream & os);
    std::ostream & bright_white(std::ostream & os);
    std::ostream & on_black(std::ostream & os);
    std::ostream & on_blue(std::ostream & os);
    std::ostream & on_green(std::ostream & os);
    std::ostream & on_aqua(std::ostream & os);
    std::ostream & on_red(std::ostream & os);
    std::ostream & on_purple(std::ostream & os);
    std::ostream & on_yellow(std::ostream & os);
    std::ostream & on_white(std::ostream & os);
    std::ostream & on_grey(std::ostream & os);
    std::ostream & on_light_blue(std::ostream & os);
    std::ostream & on_light_green(std::ostream & os);
    std::ostream & on_light_aqua(std::ostream & os);
    std::ostream & on_light_red(std::ostream & os);
    std::ostream & on_light_purple(std::ostream & os);
    std::ostream & on_light_yellow(std::ostream & os);
    std::ostream & on_bright_white(std::ostream & os);
    std::ostream & black_on_black(std::ostream & os);
    std::ostream & black_on_blue(std::ostream & os);
    std::ostream & black_on_green(std::ostream & os);
    std::ostream & black_on_aqua(std::ostream & os);
    std::ostream & black_on_red(std::ostream & os);
    std::ostream & black_on_purple(std::ostream & os);
    std::ostream & black_on_yellow(std::ostream & os);
    std::ostream & black_on_white(std::ostream & os);
    std::ostream & black_on_grey(std::ostream & os);
    std::ostream & black_on_light_blue(std::ostream & os);
    std::ostream & black_on_light_green(std::ostream & os);
    std::ostream & black_on_light_aqua(std::ostream & os);
    std::ostream & black_on_light_red(std::ostream & os);
    std::ostream & black_on_light_purple(std::ostream & os);
    std::ostream & black_on_light_yellow(std::ostream & os);
    std::ostream & black_on_bright_white(std::ostream & os);
    std::ostream & blue_on_black(std::ostream & os);
    std::ostream & blue_on_blue(std::ostream & os);
    std::ostream & blue_on_green(std::ostream & os);
    std::ostream & blue_on_aqua(std::ostream & os);
    std::ostream & blue_on_red(std::ostream & os);
    std::ostream & blue_on_purple(std::ostream & os);
    std::ostream & blue_on_yellow(std::ostream & os);
    std::ostream & blue_on_white(std::ostream & os);
    std::ostream & blue_on_grey(std::ostream & os);
    std::ostream & blue_on_light_blue(std::ostream & os);
    std::ostream & blue_on_light_green(std::ostream & os);
    std::ostream & blue_on_light_aqua(std::ostream & os);
    std::ostream & blue_on_light_red(std::ostream & os);
    std::ostream & blue_on_light_purple(std::ostream & os);
    std::ostream & blue_on_light_yellow(std::ostream & os);
    std::ostream & blue_on_bright_white(std::ostream & os);
    std::ostream & green_on_black(std::ostream & os);
    std::ostream & green_on_blue(std::ostream & os);
    std::ostream & green_on_green(std::ostream & os);
    std::ostream & green_on_aqua(std::ostream & os);
    std::ostream & green_on_red(std::ostream & os);
    std::ostream & green_on_purple(std::ostream & os);
    std::ostream & green_on_yellow(std::ostream & os);
    std::ostream & green_on_white(std::ostream & os);
    std::ostream & green_on_grey(std::ostream & os);
    std::ostream & green_on_light_blue(std::ostream & os);
    std::ostream & green_on_light_green(std::ostream & os);
    std::ostream & green_on_light_aqua(std::ostream & os);
    std::ostream & green_on_light_red(std::ostream & os);
    std::ostream & green_on_light_purple(std::ostream & os);
    std::ostream & green_on_light_yellow(std::ostream & os);
    std::ostream & green_on_bright_white(std::ostream & os);
    std::ostream & aqua_on_black(std::ostream & os);
    std::ostream & aqua_on_blue(std::ostream & os);
    std::ostream & aqua_on_green(std::ostream & os);
    std::ostream & aqua_on_aqua(std::ostream & os);
    std::ostream & aqua_on_red(std::ostream & os);
    std::ostream & aqua_on_purple(std::ostream & os);
    std::ostream & aqua_on_yellow(std::ostream & os);
    std::ostream & aqua_on_white(std::ostream & os);
    std::ostream & aqua_on_grey(std::ostream & os);
    std::ostream & aqua_on_light_blue(std::ostream & os);
    std::ostream & aqua_on_light_green(std::ostream & os);
    std::ostream & aqua_on_light_aqua(std::ostream & os);
    std::ostream & aqua_on_light_red(std::ostream & os);
    std::ostream & aqua_on_light_purple(std::ostream & os);
    std::ostream & aqua_on_light_yellow(std::ostream & os);
    std::ostream & aqua_on_bright_white(std::ostream & os);
    std::ostream & red_on_black(std::ostream & os);
    std::ostream & red_on_blue(std::ostream & os);
    std::ostream & red_on_green(std::ostream & os);
    std::ostream & red_on_aqua(std::ostream & os);
    std::ostream & red_on_red(std::ostream & os);
    std::ostream & red_on_purple(std::ostream & os);
    std::ostream & red_on_yellow(std::ostream & os);
    std::ostream & red_on_white(std::ostream & os);
    std::ostream & red_on_grey(std::ostream & os);
    std::ostream & red_on_light_blue(std::ostream & os);
    std::ostream & red_on_light_green(std::ostream & os);
    std::ostream & red_on_light_aqua(std::ostream & os);
    std::ostream & red_on_light_red(std::ostream & os);
    std::ostream & red_on_light_purple(std::ostream & os);
    std::ostream & red_on_light_yellow(std::ostream & os);
    std::ostream & red_on_bright_white(std::ostream & os);
    std::ostream & purple_on_black(std::ostream & os);
    std::ostream & purple_on_blue(std::ostream & os);
    std::ostream & purple_on_green(std::ostream & os);
    std::ostream & purple_on_aqua(std::ostream & os);
    std::ostream & purple_on_red(std::ostream & os);
    std::ostream & purple_on_purple(std::ostream & os);
    std::ostream & purple_on_yellow(std::ostream & os);
    std::ostream & purple_on_white(std::ostream & os);
    std::ostream & purple_on_grey(std::ostream & os);
    std::ostream & purple_on_light_blue(std::ostream & os);
    std::ostream & purple_on_light_green(std::ostream & os);
    std::ostream & purple_on_light_aqua(std::ostream & os);
    std::ostream & purple_on_light_red(std::ostream & os);
    std::ostream & purple_on_light_purple(std::ostream & os);
    std::ostream & purple_on_light_yellow(std::ostream & os);
    std::ostream & purple_on_bright_white(std::ostream & os);
    std::ostream & yellow_on_black(std::ostream & os);
    std::ostream & yellow_on_blue(std::ostream & os);
    std::ostream & yellow_on_green(std::ostream & os);
    std::ostream & yellow_on_aqua(std::ostream & os);
    std::ostream & yellow_on_red(std::ostream & os);
    std::ostream & yellow_on_purple(std::ostream & os);
    std::ostream & yellow_on_yellow(std::ostream & os);
    std::ostream & yellow_on_white(std::ostream & os);
    std::ostream & yellow_on_grey(std::ostream & os);
    std::ostream & yellow_on_light_blue(std::ostream & os);
    std::ostream & yellow_on_light_green(std::ostream & os);
    std::ostream & yellow_on_light_aqua(std::ostream & os);
    std::ostream & yellow_on_light_red(std::ostream & os);
    std::ostream & yellow_on_light_purple(std::ostream & os);
    std::ostream & yellow_on_light_yellow(std::ostream & os);
    std::ostream & yellow_on_bright_white(std::ostream & os);
    std::ostream & white_on_black(std::ostream & os);
    std::ostream & white_on_blue(std::ostream & os);
    std::ostream & white_on_green(std::ostream & os);
    std::ostream & white_on_aqua(std::ostream & os);
    std::ostream & white_on_red(std::ostream & os);
    std::ostream & white_on_purple(std::ostream & os);
    std::ostream & white_on_yellow(std::ostream & os);
    std::ostream & white_on_white(std::ostream & os);
    std::ostream & white_on_grey(std::ostream & os);
    std::ostream & white_on_light_blue(std::ostream & os);
    std::ostream & white_on_light_green(std::ostream & os);
    std::ostream & white_on_light_aqua(std::ostream & os);
    std::ostream & white_on_light_red(std::ostream & os);
    std::ostream & white_on_light_purple(std::ostream & os);
    std::ostream & white_on_light_yellow(std::ostream & os);
    std::ostream & white_on_bright_white(std::ostream & os);
    std::ostream & grey_on_black(std::ostream & os);
    std::ostream & grey_on_blue(std::ostream & os);
    std::ostream & grey_on_green(std::ostream & os);
    std::ostream & grey_on_aqua(std::ostream & os);
    std::ostream & grey_on_red(std::ostream & os);
    std::ostream & grey_on_purple(std::ostream & os);
    std::ostream & grey_on_yellow(std::ostream & os);
    std::ostream & grey_on_white(std::ostream & os);
    std::ostream & grey_on_grey(std::ostream & os);
    std::ostream & grey_on_light_blue(std::ostream & os);
    std::ostream & grey_on_light_green(std::ostream & os);
    std::ostream & grey_on_light_aqua(std::ostream & os);
    std::ostream & grey_on_light_red(std::ostream & os);
    std::ostream & grey_on_light_purple(std::ostream & os);
    std::ostream & grey_on_light_yellow(std::ostream & os);
    std::ostream & grey_on_bright_white(std::ostream & os);
    std::ostream & light_blue_on_black(std::ostream & os);
    std::ostream & light_blue_on_blue(std::ostream & os);
    std::ostream & light_blue_on_green(std::ostream & os);
    std::ostream & light_blue_on_aqua(std::ostream & os);
    std::ostream & light_blue_on_red(std::ostream & os);
    std::ostream & light_blue_on_purple(std::ostream & os);
    std::ostream & light_blue_on_yellow(std::ostream & os);
    std::ostream & light_blue_on_white(std::ostream & os);
    std::ostream & light_blue_on_grey(std::ostream & os);
    std::ostream & light_blue_on_light_blue(std::ostream & os);
    std::ostream & light_blue_on_light_green(std::ostream & os);
    std::ostream & light_blue_on_light_aqua(std::ostream & os);
    std::ostream & light_blue_on_light_red(std::ostream & os);
    std::ostream & light_blue_on_light_purple(std::ostream & os);
    std::ostream & light_blue_on_light_yellow(std::ostream & os);
    std::ostream & light_blue_on_bright_white(std::ostream & os);
    std::ostream & light_green_on_black(std::ostream & os);
    std::ostream & light_green_on_blue(std::ostream & os);
    std::ostream & light_green_on_green(std::ostream & os);
    std::ostream & light_green_on_aqua(std::ostream & os);
    std::ostream & light_green_on_red(std::ostream & os);
    std::ostream & light_green_on_purple(std::ostream & os);
    std::ostream & light_green_on_yellow(std::ostream & os);
    std::ostream & light_green_on_white(std::ostream & os);
    std::ostream & light_green_on_grey(std::ostream & os);
    std::ostream & light_green_on_light_blue(std::ostream & os);
    std::ostream & light_green_on_light_green(std::ostream & os);
    std::ostream & light_green_on_light_aqua(std::ostream & os);
    std::ostream & light_green_on_light_red(std::ostream & os);
    std::ostream & light_green_on_light_purple(std::ostream & os);
    std::ostream & light_green_on_light_yellow(std::ostream & os);
    std::ostream & light_green_on_bright_white(std::ostream & os);
    std::ostream & light_aqua_on_black(std::ostream & os);
    std::ostream & light_aqua_on_blue(std::ostream & os);
    std::ostream & light_aqua_on_green(std::ostream & os);
    std::ostream & light_aqua_on_aqua(std::ostream & os);
    std::ostream & light_aqua_on_red(std::ostream & os);
    std::ostream & light_aqua_on_purple(std::ostream & os);
    std::ostream & light_aqua_on_yellow(std::ostream & os);
    std::ostream & light_aqua_on_white(std::ostream & os);
    std::ostream & light_aqua_on_grey(std::ostream & os);
    std::ostream & light_aqua_on_light_blue(std::ostream & os);
    std::ostream & light_aqua_on_light_green(std::ostream & os);
    std::ostream & light_aqua_on_light_aqua(std::ostream & os);
    std::ostream & light_aqua_on_light_red(std::ostream & os);
    std::ostream & light_aqua_on_light_purple(std::ostream & os);
    std::ostream & light_aqua_on_light_yellow(std::ostream & os);
    std::ostream & light_aqua_on_bright_white(std::ostream & os);
    std::ostream & light_red_on_black(std::ostream & os);
    std::ostream & light_red_on_blue(std::ostream & os);
    std::ostream & light_red_on_green(std::ostream & os);
    std::ostream & light_red_on_aqua(std::ostream & os);
    std::ostream & light_red_on_red(std::ostream & os);
    std::ostream & light_red_on_purple(std::ostream & os);
    std::ostream & light_red_on_yellow(std::ostream & os);
    std::ostream & light_red_on_white(std::ostream & os);
    std::ostream & light_red_on_grey(std::ostream & os);
    std::ostream & light_red_on_light_blue(std::ostream & os);
    std::ostream & light_red_on_light_green(std::ostream & os);
    std::ostream & light_red_on_light_aqua(std::ostream & os);
    std::ostream & light_red_on_light_red(std::ostream & os);
    std::ostream & light_red_on_light_purple(std::ostream & os);
    std::ostream & light_red_on_light_yellow(std::ostream & os);
    std::ostream & light_red_on_bright_white(std::ostream & os);
    std::ostream & light_purple_on_black(std::ostream & os);
    std::ostream & light_purple_on_blue(std::ostream & os);
    std::ostream & light_purple_on_green(std::ostream & os);
    std::ostream & light_purple_on_aqua(std::ostream & os);
    std::ostream & light_purple_on_red(std::ostream & os);
    std::ostream & light_purple_on_purple(std::ostream & os);
    std::ostream & light_purple_on_yellow(std::ostream & os);
    std::ostream & light_purple_on_white(std::ostream & os);
    std::ostream & light_purple_on_grey(std::ostream & os);
    std::ostream & light_purple_on_light_blue(std::ostream & os);
    std::ostream & light_purple_on_light_green(std::ostream & os);
    std::ostream & light_purple_on_light_aqua(std::ostream & os);
    std::ostream & light_purple_on_light_red(std::ostream & os);
    std::ostream & light_purple_on_light_purple(std::ostream & os);
    std::ostream & light_purple_on_light_yellow(std::ostream & os);
    std::ostream & light_purple_on_bright_white(std::ostream & os);
    std::ostream & light_yellow_on_black(std::ostream & os);
    std::ostream & light_yellow_on_blue(std::ostream & os);
    std::ostream & light_yellow_on_green(std::ostream & os);
    std::ostream & light_yellow_on_aqua(std::ostream & os);
    std::ostream & light_yellow_on_red(std::ostream & os);
    std::ostream & light_yellow_on_purple(std::ostream & os);
    std::ostream & light_yellow_on_yellow(std::ostream & os);
    std::ostream & light_yellow_on_white(std::ostream & os);
    std::ostream & light_yellow_on_grey(std::ostream & os);
    std::ostream & light_yellow_on_light_blue(std::ostream & os);
    std::ostream & light_yellow_on_light_green(std::ostream & os);
    std::ostream & light_yellow_on_light_aqua(std::ostream & os);
    std::ostream & light_yellow_on_light_red(std::ostream & os);
    std::ostream & light_yellow_on_light_purple(std::ostream & os);
    std::ostream & light_yellow_on_light_yellow(std::ostream & os);
    std::ostream & light_yellow_on_bright_white(std::ostream & os);
    std::ostream & bright_white_on_black(std::ostream & os);
    std::ostream & bright_white_on_blue(std::ostream & os);
    std::ostream & bright_white_on_green(std::ostream & os);
    std::ostream & bright_white_on_aqua(std::ostream & os);
    std::ostream & bright_white_on_red(std::ostream & os);
    std::ostream & bright_white_on_purple(std::ostream & os);
    std::ostream & bright_white_on_yellow(std::ostream & os);
    std::ostream & bright_white_on_white(std::ostream & os);
    std::ostream & bright_white_on_grey(std::ostream & os);
    std::ostream & bright_white_on_light_blue(std::ostream & os);
    std::ostream & bright_white_on_light_green(std::ostream & os);
    std::ostream & bright_white_on_light_aqua(std::ostream & os);
    std::ostream & bright_white_on_light_red(std::ostream & os);
    std::ostream & bright_white_on_light_purple(std::ostream & os);
    std::ostream & bright_white_on_light_yellow(std::ostream & os);
    std::ostream & bright_white_on_bright_white(std::ostream & os);
}
