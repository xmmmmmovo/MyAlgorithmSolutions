//
// Created by xmmmmmovo on 2021/1/9.
//
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 1e5 + 10;
int q[N];

int main() {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    sort(q, q + n);

    int mid = q[n / 2];

    for (int i = 0; i < n; i++) {
        res += abs(q[i] - mid);
    }

    printf("%d", res);
    return 0;
}