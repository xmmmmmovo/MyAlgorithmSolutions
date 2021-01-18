/**
 * author: xmmmmmovo
 * generation time: 2021/01/18
 * filename: 798. 差分矩阵.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, m, q;
int a[ N ][ N ], b[ N ][ N ];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[ x1 ][ y1 ] += c;
    b[ x1 ][ y2 + 1 ] -= c;
    b[ x2 + 1 ][ y1 ] -= c;
    b[ x2 + 1 ][ y2 + 1 ] += c;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[ i ][ j ]);
            insert(i, j, i, j, a[ i ][ j ]);
        }
    }

    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[ i ][ j ] += b[ i - 1 ][ j ] + b[ i ][ j - 1 ] - b[ i - 1 ][ j - 1 ];
            printf("%d ", b[ i ][ j ]);
        }
        printf("\n");
    }

    return 0;
}