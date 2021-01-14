/**
 * author: xmmmmmovo
 * generation time: 2021/01/13
 * filename: 844走迷宫.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int g[110][110];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

typedef struct node {
    int x, y, d;
    node(int xx, int yy, int dd) {
        x = xx;
        y = yy;
        d = dd;
    }
} node;


int bfs(int sx, int sy) {
    queue<node> q;
    q.push(node(sx, sy, 0));
    g[sx][sy] = 1;

    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = now.x + dx[i], ty = now.y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && !g[tx][ty]) {
                if (tx == n - 1 && ty == m - 1) {
                    return now.d + 1;
                } else {
                    g[tx][ty] = 1;
                    q.push(node(tx, ty, now.d + 1));
                }
            }
        }
    }

    return -1;
}

int main() {
    int x = 1, y = 1;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    printf("%d", bfs(0, 0));


    return 0;
}