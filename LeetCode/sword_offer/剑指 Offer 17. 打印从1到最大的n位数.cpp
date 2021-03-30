/**
 * author: xmmmmmovo
 * generation time: 2021/03/30
 * filename: 剑指 Offer 17. 打印从1到最大的n位数.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
  public:
    vector<int> printNumbers(int n) {
        int         edge = (int)pow(10, n);
        vector<int> res(edge - 1);
        for (int i = 1; i < edge; i++) {
            res[i - 1] = i;
        }
        return res;
    }
};