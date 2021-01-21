/**
 * author: xmmmmmovo
 * generation time: 2021/01/19
 * filename: 826. 单链表.cpp
 * language & build version : C 11 & C++ 17
 */
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int m;
// head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx  = 0;
}

// 在链表头插入一个数val
void insert(int val) { e[idx] = val, ne[idx] = head, head = idx++; }

void add(int pos, int val) {
    e[idx]  = val;
    ne[idx] = ne[pos];
    ne[pos] = idx;
    idx++;
}

// 将头结点删除，需要保证头结点存在
void remove(int pos) { ne[pos] = ne[ne[pos]]; }

int main() {
    scanf("%d", &m);

    init();

    while (m--) {
        char op[2];
        scanf("%s", op);

        if (op[0] == 'H') {
            int val;
            scanf("%d", &val);
            insert(val);
        } else if (op[0] == 'D') {
            int pos;
            scanf("%d", &pos);
            if(!pos) head = ne[head];
            else remove(pos - 1);
        } else if (op[0] == 'I') {
            int pos, val;
            scanf("%d %d", &pos, &val);
            add(pos - 1, val);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);

    return 0;
}