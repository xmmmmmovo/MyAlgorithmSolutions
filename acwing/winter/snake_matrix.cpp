/**
 * author: xmmmmmovo
 * generation time: 2021/01/11
 * filename: snake_matrix.cpp
 * language & build version : C 11 & C++ 17
*/
// 模拟题目
// 网格题

#include <iostream>

int q[110][110];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    int x = 0, y = 0, d = 1;

    for (int i = 1; i <= n * m; i++) {
        q[x][y] = i;
        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m || q[a][b]) {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }

    return 0;
}