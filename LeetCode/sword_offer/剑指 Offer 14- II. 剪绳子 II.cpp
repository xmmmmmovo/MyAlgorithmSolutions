/**
 * author: xmmmmmovo
 * generation time: 2021/03/30
 * filename: 剑指 Offer 14- II. 剪绳子 II.cpp
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

const int M = 1e9 + 7;

ll qmi(ll a, ll k, ll p) {
    ll res = 1;
    while (k) {
        if (k & 1)
            res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

class Solution {
  public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;
        if (n % 3 == 0)
            return (int)qmi(3, n / 3, M);
        if (n % 3 == 1)
            return (int)(qmi(3, (n / 3) - 1, M) * 4 % M);
        return (int)(qmi(3, n / 3, M) * 2 % M);
    }
};