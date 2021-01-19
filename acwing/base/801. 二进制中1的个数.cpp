/**
 * author: xmmmmmovo
 * generation time: 2021/01/19
 * filename: 801. 二进制中1的个数.cpp
 * language & build version : C 11 & C++ 17
*/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

// 求n的第k位数字: n >> k & 1
// 返回n的最后一位1：lowbit(n) = n & -n

int lowbit(int x) { return x & -x; }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        int res = 0;
        while (a[i])
            a[i] -= lowbit(a[i]), res++;
        printf("%d ", res);
    }

    return 0;
}