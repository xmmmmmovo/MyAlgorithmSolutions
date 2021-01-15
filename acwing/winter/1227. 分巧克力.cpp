/**
 * author: xmmmmmovo
 * generation time: 2021/01/15
 * filename: 1227. 分巧克力.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, k;
int H[N], W[N];

bool check(int x) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += ((H[i] / x) * (W[i] / x));
    }

    return sum >= k;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d %d", &H[i], &W[i]);

    int l = 0, r = N;
    while (l < r) {
        int mid = (l + r + 1) >> 1;

        if (check(mid)) l = mid;
        else
            r = mid - 1;
    }

    printf("%d", l);

    return 0;
}