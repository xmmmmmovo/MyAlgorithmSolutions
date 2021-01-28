/**
 * author: xmmmmmovo
 * generation time: 2021/01/25
 * filename: 827. 双链表.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int e[N], l[N], r[N], idx;

// l[k], x 在k左边插入
int add(int k, int val) {
    e[idx]  = val;
    l[idx]  = k;
    r[idx]  = r[k];
    l[r[k]] = idx;
    r[k]    = idx;
    idx++;
}

void del(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main() {
    scanf("%d", &m);
    r[0] = 1, l[1] = 0;
    idx = 2;

    while (m--) {
        char op[3];
        int  pos, val;
        scanf("%s", op);
        if (op[0] == 'L') {
            scanf("%d", &val);
            add(0, val);
        } else if (op[0] == 'R') {
            scanf("%d", &val);
            add(l[1], val);
        } else if (op[0] == 'D') {
            scanf("%d", &pos);
            del(pos + 1);
        } else if (op[0] == 'I') {
            if (op[1] == 'L') {
                scanf("%d %d", &pos, &val);
                add(l[pos + 1], val);
            } else {
                scanf("%d %d", &pos, &val);
                add(pos + 1, val);
            }
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) {
        printf("%d ", e[i]);
    }

    return 0;
}