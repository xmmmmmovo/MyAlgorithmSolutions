/**
 * author: xmmmmmovo
 * generation time: 2021/01/22
 * filename: 1371. 货币系统.cpp
 * language & build version : C 11 & C++ 17
 */
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 30, M = 1e4 + 10;
int       v, n;
int       vals[N];
LL        f[M];

int main() {
    scanf("%d %d", &v, &n);
    for (int i = 1; i <= v; i++)
        scanf("%d", &vals[i]);
    f[0] = 1;

    for (int i = 1; i <= v; i++) {
        for (int j = vals[i]; j <= n; j++) {
            f[j] += f[j - vals[i]];
        }
    }

    printf("%lld", f[n]);

    return 0;
}