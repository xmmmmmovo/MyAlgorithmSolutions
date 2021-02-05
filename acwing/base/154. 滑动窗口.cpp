/**
 * author: xmmmmmovo
 * generation time: 2021/02/05
 * filename: 154. 滑动窗口.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int       n, k;
int       a[N], q[N];

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        //判断队头是否滑出窗口
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    printf("\n");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        //判断队头是否滑出窗口
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }

    return 0;
}