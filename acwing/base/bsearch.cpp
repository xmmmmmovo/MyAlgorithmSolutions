//
// Created by xmmmmmovo on 2021/1/7.
//
#include <iostream>

using namespace std;

constexpr int N = 1e5 + 10;
int q[N];

bool check(int x) { /* ... */
    return false;
}// 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;// check()判断mid是否满足性质
        else
            l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) { scanf("%d", &q[i]); }
    while (m--) {
        int x;
        scanf("%d", &x);
        // 取左边界
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= x) r = mid;
            else
                l = mid + 1;
        }

        if (q[l] != x) printf("-1 -1\n");
        else {
            printf("%d ", l);
            // 取右边界
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (q[mid] <= x) l = mid;
                else
                    r = mid - 1;
            }
            printf("%d\n", l);
        }
    }


    return 0;
}