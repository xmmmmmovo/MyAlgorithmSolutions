/**
 * author: xmmmmmovo
 * generation time: 2021/03/30
 * filename: 剑指 Offer 15. 二进制中1的个数.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

int lowbit(uint32_t x) { return x & -x; }

class Solution {
  public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n -= lowbit(n), res++;
        }
        return res;
    }
};