//
// Created by xmmmmmovo on 2020/6/9.
//
#include "../include/algorithm/charset_tools.hpp"
#include <iostream>

using namespace ds;
using namespace std;

constexpr int BUF_SIZE = 1024;// buf

int main(int argc, char const *argv[]) {
    char utf[ BUF_SIZE ];
    char gbk[ BUF_SIZE ];

    decltype(auto) file_utf = fopen("../text/utf8.txt", "rw");
    decltype(auto) file_gbk = fopen("../text/gb.txt", "rw");

    fgets(utf, BUF_SIZE, file_utf);
    fgets(gbk, BUF_SIZE, file_gbk);

    cout << calculate_char_utf8(utf) << endl;
    cout << calculate_char_gbk(gbk) << endl;

    return 0;
}