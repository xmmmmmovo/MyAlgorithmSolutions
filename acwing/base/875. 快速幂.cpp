/**
 * author: xmmmmmovo
 * generation time: 2021/03/28
 * filename: 875. 快速幂.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n;

using ll = long long;

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
        int a, k, p;
        scanf("%d %d %d", &a, &k, &p);
        printf("%d\n", qmi(a, k, p));
    }

    return 0;
}