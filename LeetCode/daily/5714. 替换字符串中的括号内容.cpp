/**
 * author: xmmmmmovo
 * generation time: 2021/03/28
 * filename: 5714. 替换字符串中的括号内容.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    string evaluate(string s, vector<vector<string>> &knowledge) {
        string tmp;
        bool   f = false;
        string res;
        unordered_map<string, string> k;

        for(auto &&kn: knowledge){
            k[kn[0]] = kn[1];
        }
        
        for (auto &&c : s) {
            if (c == '(') {
                tmp = "";
                f   = true;
            } else if (c == ')') {
                f = false;
                if(k.count(tmp) == 0){
                    res += '?';
                } else {
                    res += k[tmp];
                }
            } else {
                if (f) {
                    tmp += c;
                } else {
                    res += c;
                }
            }
        }

        return res;
    }
};