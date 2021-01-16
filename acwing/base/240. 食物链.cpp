/**
 * author: xmmmmmovo
 * generation time: 2021/01/16
 * filename: 240. 食物链.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 5e4 + 10;
int n, k, cnt = 0;
int t, x, y;
int p[N], d[N];

int find(int x) {// 返回x的跟节点
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < k; i++) {

        scanf("%d %d %d", &t, &x, &y);
        if (x > n || y > n) cnt++;
        else {
            int px = find(x), py = find(y);
            if (t == 1) {
                if (px == py && (d[x] - d[y]) % 3) cnt++;
                else if (px != py) {
                    p[px] = p[py];
                    d[px] = d[y] - d[x];
                }
            } else {
                if (px == py && (d[x] - d[y] - 1) % 3) cnt++;
                else if (px != py) {
                    p[px] = p[py];
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }

    printf("%d", cnt);

    return 0;
}