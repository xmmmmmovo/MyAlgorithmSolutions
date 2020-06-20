//
// Created by xmmmmmovo on 2020/6/9.
//

#ifndef DS_CHARACTER_SET_TOOLS_HPP
#define DS_CHARACTER_SET_TOOLS_HPP

#include <cstring>
#include <string>

namespace ds {

using std::string;

// 下面的都没用到 只不过给个参考常量
constexpr int mask_0  = 0b00000000;// ascii码
constexpr int mask_10 = 0b10000000;// 四位占位
constexpr int mask_1  = 0b11000000;// 二位占位
constexpr int mask_2  = 0b11100000;// 三位占位
constexpr int mask_3  = 0b11110000;// 四位占位

int calculate_char_utf8(const char *s, int len = -1) {
    if (len == -1) {
        len = strlen(s);
    }
    int cl = 0;
    for (int i = 0; i < len; ++i) {
        unsigned char uc = (unsigned char) s[ i ];
        if (uc <= 0b01111111 || uc >= 0b11011111) {
            cl += 1;
        }
    }

    return cl;
}

int calculate_char_utf8(string s) {
    calculate_char_utf8(s.c_str(), s.size());
}

// gbk直接冲就完事儿了 没转unsigned
int calculate_char_gbk(const char *s, int len = -1) {
    int cl = 0;
    if (len == -1) {
        len = strlen(s);
    }
    for (int i = 0; i < len; ++i) {
        if (s[ i ] < 0) {
            i++;
        }
        cl++;
    }
    return cl;
}

int calculate_char_gbk(string s) {
    return calculate_char_gbk(s.c_str(), s.size());
}

}// namespace ds

#endif//DS_CHARACTER_SET_TOOLS_HPP
