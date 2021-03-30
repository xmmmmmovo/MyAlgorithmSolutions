/**
 * author: xmmmmmovo
 * generation time: 2021/03/30
 * filename: 剑指 Offer 14- I. 剪绳子.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int qmi(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = (ll)res * a;
        k >>= 1;
        a = (ll)a * a;
    }
    return res;
}

class Solution {
  public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;
        if (n % 3 == 0)
            return qmi(3, n / 3);
        if (n % 3 == 1)
            return qmi(3, (n - 3) / 3) * 4;
        return qmi(3, n / 3) * 2;
    }
};