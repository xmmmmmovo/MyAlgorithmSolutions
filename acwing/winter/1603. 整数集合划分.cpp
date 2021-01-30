/**
 * author: xmmmmmovo
 * generation time: 2021/01/30
 * filename: 1603. 整数集合划分.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int       n;
int       r[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &r[i]);
    sort(r, r + n);
    int s1 = 0, s2 = 0;
    for (int i = 0, j = n - 1; i < (n / 2); i++, j--) {
        s1 += r[i];
        s2 += r[j];
    }
    printf("%d %d", n % 2, s2 - s1 + (n % 2 ? r[n / 2] : 0));

    return 0;
}