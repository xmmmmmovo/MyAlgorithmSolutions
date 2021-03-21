/**
 * author: xmmmmmovo
 * generation time: 2021/03/07
 * filename: 5697. 检查二进制字符串字段.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool checkOnesSegment(string s) {
        int status = 0;
        for (auto &&c : s) {
            if (c == '1' && status == 2) {
                return false;
            } else if (c == '1' && status == 0) {
                status = 1;
            } else if (c == '0' && status == 1) {
                status = 2;
            }
        }

        return true;
    }
};