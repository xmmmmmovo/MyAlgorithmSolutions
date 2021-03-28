/**
 * author: xmmmmmovo
 * generation time: 2021/03/28
 * filename: 5716. 好因子的最大数目.cpp
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

const int M = 1e9 + 7;

ll qmi(ll a, ll k, int p) {
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
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3)
            return primeFactors;

        if (primeFactors % 3 == 0)
            return qmi(3, primeFactors / 3, M);
        if (primeFactors % 3 == 1)
            return qmi(3, (primeFactors - 4) / 3, M) * 4 % M;
        return qmi(3, (primeFactors - 2) / 3, M) * 2 % M;
    }
};