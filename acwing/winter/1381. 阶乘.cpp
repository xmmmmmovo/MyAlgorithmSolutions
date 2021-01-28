/**
 * author: xmmmmmovo
 * generation time: 2021/01/27
 * filename: 1381. 阶乘.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int res = 1, c2 = 0, c5 = 0;

    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t % 2 == 0)
            t /= 2, c2++;
        while (t % 5 == 0)
            t /= 5, c5++;
        res = res * t % 10;
    }

    int k = min(c2, c5);
    for (int i = k; i < c2; i++)
        res = res * 2 % 10;
    for (int i = k; i < c5; i++)
        res = res * 5 % 10;

    printf("%d", res);
    return 0;
}