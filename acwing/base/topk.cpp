//
// Created by xmmmmmovo on 2021/1/7.
//

#include <iostream>

using namespace std;

constexpr int N = 1e5 + 10;

int q[N];

int topk(int l, int r, int k) {
    if (l >= r) {
        return q[k];
    }

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++;
        while (q[i] < x);
        do j--;
        while (q[j] > x);

        if (i < j) swap(q[i], q[j]);
    }
    // 这里是判断是左半边里面有topk还是右半边里面有topk
    if (j >= k)
        return topk(l, j, k);
    else
        return topk(j + 1, r, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    printf("%d", topk(0, n - 1, k - 1));

    return 0;
}