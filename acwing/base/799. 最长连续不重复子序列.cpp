/**
 * author: xmmmmmovo
 * generation time: 2021/01/19
 * filename: 799. 最长连续不重复子序列.cpp
 * language & build version : C 11 & C++ 17
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[ N ], s[ N ];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[ i ]);
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        s[ a[ i ] ]++;
        while (s[ a[ i ] ] > 1) {
            s[ a[ j ] ]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    printf("%d", res);

    return 0;
}