/**
 * author: xmmmmmovo
 * generation time: 2021/03/09
 * filename: 1047. 删除字符串中的所有相邻重复项.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    string removeDuplicates(string s) {
        size_t idx = 0;
        for (auto &&c : s) {
            if (idx && s[idx - 1] == c) {
                idx--;
            } else {
                s[idx++] = c;
            }
        }
        s.resize(idx);
        return s;
    }
};