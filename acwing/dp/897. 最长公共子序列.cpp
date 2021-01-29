/**
 * author: xmmmmmovo
 * generation time: 2021/01/28
 * filename: 897. 最长公共子序列.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int  n, m;
char a[N], b[N];
int  f[N][N];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", a + 1);
    scanf("%s", b + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    printf("%d", f[n][m]);

    return 0;
}