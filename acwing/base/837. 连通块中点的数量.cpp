/**
 * author: xmmmmmovo
 * generation time: 2021/01/16
 * filename: 837. 连通块中点的数量.cpp
 * language & build version : C 11 & C++ 17
*/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N], p_size[N];

int find(int x) {// 返回x的跟节点
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        p_size[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        char op[5];
        int a, b;
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) continue;
            p_size[find(b)] += p_size[find(a)];
            p[find(a)] = find(b);
        } else if (op[1] == '1') {
            scanf("%d %d", &a, &b);
            if (find(a) == find(b)) printf("Yes\n");
            else
                printf("No\n");
        } else {
            scanf("%d", &a);
            printf("%d\n", p_size[find(a)]);
        }
    }


    return 0;
}