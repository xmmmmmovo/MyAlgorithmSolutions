/**
 * author: xmmmmmovo
 * generation time: 2021/01/27
 * filename: 2. 01背包问题.cpp
 * language & build version : C 11 & C++ 17
 */
// 优化解法
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &v[i], &w[i]);

    for (int i = 1; i <= n; i++) {
        // j的意思是体积合法值
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    printf("%d", f[m]);

    return 0;
} 