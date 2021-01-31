/**
 * author: xmmmmmovo
 * generation time: 2021/01/31
 * filename: 829. 模拟队列.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int       n, s[N];
int       l = 0, r = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    string op;
    int    val;
    while (n--) {
        cin >> op;

        if (op == "push") {
            cin >> val;
            s[++r] = val;
        } else if (op == "query") {
            printf("%d\n", s[l]);
        } else if (op == "pop") {
            l++;
        } else {
            printf("%s\n", (l > r) ? "YES" : "NO");
        }
    }

    return 0;
}