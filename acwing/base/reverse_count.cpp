//
// Created by xmmmmmovo on 2021/1/7.
//
#include <iostream>

using namespace std;

typedef long long ll;

constexpr int N = 1e5 + 10;
int q[N], tmp[N], cnt = 0;

ll reverse_count(int l, int r) {
    if (l >= r) { return 0; }

    int mid = (l + r) >> 1;

    ll res = reverse_count(l, mid) + reverse_count(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }

    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];

    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    printf("%lld", reverse_count(0, n - 1));
    return 0;
}