/**
 * author: xmmmmmovo
 * generation time: 2021/01/22
 * filename: 1432. 棋盘挑战.cpp
 * language & build version : C 11 & C++ 17
 */
#include <cstdarg>
#include <iostream>

using namespace std;

int  n, res = 0;
bool col[20], x1[40], x2[40]; // x1, x2是对角线
int  q[20];

bool check(int r, int i) { return !col[i] && !x1[r + i] && !x2[r - i + n]; }

void dfs(int r) {
    if (r == n) {
        if (res < 3) {
            for (int i = 0; i < n; i++)
                printf("%d ", q[i]);
            printf("\n");
        }
        res++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check(r, i)) {
            col[i] = x1[r + i] = x2[r - i + n] = 1;
            q[r]                               = i + 1;
            dfs(r + 1);
            col[i] = x1[r + i] = x2[r - i + n] = 0;
        }
    }
}

int main() {

    scanf("%d", &n);
    dfs(0);
    printf("%d", res);

    return 0;
}