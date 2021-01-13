/**
 * author: xmmmmmovo
 * generation time: 2021/01/12
 * filename: red_and_black.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

char g[25][25];
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

// 宽度优先搜索
int dfs(int i, int j) {
    int res = 1;
    g[i][j] = '#';
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];

        if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.')
            res += dfs(x, y);
    }
    return res;
}

// 广度优先搜索
int bfs(int i, int j) {
    queue<PII> q;
    q.push({i, j});
    g[i][j] = '#';
    int res = 0;
    while (q.size()) {
        auto tmp = q.front();
        q.pop();
        res++;

        for (int i = 0; i < 4; i++) {
            int x = tmp.x + dx[i], y = tmp.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.') continue;
            g[x][y] = '#';
            q.push({x, y});
        }
    }

    return res;
}

int main() {
    out: while (scanf("%d %d", &m, &n), n || m) {
        for (int i = 0; i < n; i++) {
            scanf("%s", &g[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '@') {
                    // printf("%d\n", bfs(i, j));
                    printf("%d\n", dfs(i, j));
                    goto out;
                }
            }
        }
    }


    return 0;
}