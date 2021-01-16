/**
 * author: xmmmmmovo
 * generation time: 2021/01/16
 * filename: 836. 合并集合.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];

int find(int x) {// 返回x的跟节点
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < m; i++) {
        char op[2];
        int a, b;
        scanf("%s %d %d", op, &a, &b);
        if (op[0] == 'M') p[find(a)] = find(b);
        else {
            if (find(a) == find(b)) printf("Yes\n");
            else
                printf("No\n");
        }
    }


    return 0;
}