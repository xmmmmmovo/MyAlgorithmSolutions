/**
 * author: xmmmmmovo
 * generation time: 2021/03/30
 * filename: 剑指 Offer 16. 数值的整数次方.cpp
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

double qmi(double a, long k) {
    double res = 1;
    while (k) {
        if (k & 1)
            res = res * a;
        k >>= 1;
        a = a * a;
    }
    return res;
}

class Solution {
  public:
    double myPow(double x, long n) {
        if (n < 0)
            x = (1.0 / x), n = -n;
        return qmi(x, n);
    }
};