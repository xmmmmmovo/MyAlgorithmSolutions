/**
 * author: xmmmmmovo
 * generation time: 2021/01/19
 * filename: 800. 数组元素的目标和.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main() {
    scanf("%d %d %d", &n, &m, &x);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        if (a[i] + b[j] < x)
            i++;
        else if (a[i] + b[j] > x)
            j--;
        else {
            printf("%d %d", i, j);
            return 0;
        }
    }

    return 0;
}