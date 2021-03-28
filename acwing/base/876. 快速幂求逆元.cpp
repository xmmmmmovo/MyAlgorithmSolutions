/**
 * author: xmmmmmovo
 * generation time: 2021/03/28
 * filename: 876. 快速幂求逆元.cpp
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

int n;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        int a, p;
        scanf("%d %d", &a, &p);
        a % p ? printf("%d\n", qmi(a, p - 2, p))
              : printf("impossible\n");
    }

    return 0;
}