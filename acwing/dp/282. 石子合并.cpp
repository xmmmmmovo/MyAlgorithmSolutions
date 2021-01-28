/**
 * author: xmmmmmovo
 * generation time: 2021/01/28
 * filename: 282. 石子合并.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 310;

int n;
int a[N], s[N];
int f[N][N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j   = i + len - 1;
            f[i][j] = 1e8;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    printf("%d", f[1][n]);

    return 0;
}