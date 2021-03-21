/**
 * author: xmmmmmovo
 * generation time: 2021/03/10
 * filename: 224. 基本计算器.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int calculate(string s) {
        int         res  = 0;
        int         sign = 1; // 用来*sign
        stack<int> op;
        op.push(1);
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(':
                op.push(sign);
                break;
            case ')':
                op.pop();
                break;
            case '+':
                sign = op.top();
                break;
            case '-':
                sign = -op.top();
                break;
            case ' ':
                break;
            default:
                long n = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    n = n * 10 + s[i] - '0';
                    i++;
                }
                res += sign * n;
                i--;
                break;
            }
        }

        return res;
    }
};