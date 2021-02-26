/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 05. 替换空格.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    string replaceSpace(string s) {
        int    cnt = 0;
        string res(s.size() * 3, '\0');
        for (auto &&c : s) {
            if (c == ' ') {
                res[cnt++] = '%';
                res[cnt++] = '2';
                res[cnt++] = '0';
            } else {
                res[cnt++] = c;
            }
        }

        return res;
    }
};