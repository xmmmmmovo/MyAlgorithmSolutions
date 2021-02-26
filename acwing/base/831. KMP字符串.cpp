/**
 * author: xmmmmmovo
 * generation time: 2021/02/25
 * filename: 831. KMP字符串.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <mutex>

using namespace std;

const int N = 10010, M = 100010;

int  n, m;
char p[N], s[M];
int  ne[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;

    // 求next过程
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] == j;
    }

    // 匹配过程
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n) {
            printf("%d", i - n);
            j = ne[j];
        }
    }

    return 0;
}