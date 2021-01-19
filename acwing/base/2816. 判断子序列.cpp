/**
 * author: xmmmmmovo
 * generation time: 2021/01/19
 * filename: 2816. 判断子序列.cpp
 * language & build version : C 11 & C++ 17
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int i = 0, j = 0;
    for (i = 0, j = 0; i < n && j < m; j++) {
        if (a[i] == b[j])
            i++;
    }
    // printf("%d", res);
    if (i == n)
        printf("Yes");
    else
        printf("No");

    return 0;
}