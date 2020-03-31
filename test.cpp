#define _CRT_SBCURE_MO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int       n, m;
const int INF = (int)1e9;
int       G[ 25 ][ 1010 ], d[ 25 ][ 1010 ], vis[ 25 ][ 1010 ];

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int dfs(int x, int y) {
    if (x == 0 && y == 0)
        return G[ 0 ][ 0 ]; //边界条件
    if (vis[ x ][ y ] == 1)
        return d[ x ][ y ]; //已经走过
    vis[ x ][ y ] = 1;
    int res       = -INF; //此处的幸运值
    for (int i = 0; i < y; i++) {
        if ((y + 1) % (i + 1) == 0)
            res = max(res, G[ x ][ y ] + dfs(x, i));
    }
    if ((x - 1) >= 0)
        res =
            max(res, dfs(x - 1, y) + G[ x ][ y ]); //只能向右走，只判断是否大于0
    if ((y - 1) >= 0)
        res = max(res, dfs(x, y - 1) + G[ x ][ y ]);

    return d[ x ][ y ] = res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &G[ i ][ j ]);
            }
        }
        memset(vis, 0, sizeof(vis));
        vis[ 0 ][ 0 ] = 1;
        cout << dfs(n - 1, m - 1) << endl;
    }
    // system("pause");
    return 0;
}