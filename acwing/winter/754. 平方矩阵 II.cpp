/**
 * author: xmmmmmovo
 * generation time: 2021/01/21
 * filename: 754. 平方矩阵 II.cpp
 * language & build version : C 11 & C++ 17
 */
#include <iostream>

using namespace std;

int n;

int main() {
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", abs(j - i) + 1);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}