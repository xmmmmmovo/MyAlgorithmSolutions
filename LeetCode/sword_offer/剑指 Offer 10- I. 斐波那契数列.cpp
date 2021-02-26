/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 10- I. 斐波那契数列.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    const int N = 1e9 + 7;
    int       fib(int n) {
        int a = 0, b = 1, tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp = (a + b) % N;
            a   = b;
            b   = tmp;
        }
        return a;
    }
};