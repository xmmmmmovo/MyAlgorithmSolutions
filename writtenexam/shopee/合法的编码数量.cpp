#include <cstdio>
#include <iostream>

using ll = long long;

const int N   = 1e6 + 10;
const int MOD = 1000000369;

int n;

int main() {
    scanf("%d", &n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    ll res = 0;

    // 大包含小 小不包含大
    for(int i = n;;){}

    printf("%lld", res % MOD);
    return 0;
}