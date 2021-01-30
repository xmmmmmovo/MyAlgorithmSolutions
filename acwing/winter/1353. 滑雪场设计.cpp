/**
 * author: xmmmmmovo
 * generation time: 2021/01/28
 * filename: 1353. 滑雪场设计.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1010;
int       n;
int       m[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &m[i]);

    sort(m, m + n);

    int res = 1e8;
    for (int i = 0; i + 17 <= 100; i++) {
        int cost = 0, l = i, r = i + 17;
        for (int j = 0; j < n; j++) {
            if (m[j] < l)
                cost += (l - m[j]) * (l - m[j]);
            else if (m[j] > r)
                cost += (m[j] - r) * (m[j] - r);
        }
        res = min(res, cost);
    }

    printf("%d", res);

    return 0;
}