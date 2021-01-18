/**
 * author: xmmmmmovo
 * generation time: 2021/01/18
 * filename: 795. 前缀和.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}