/**
 * author: xmmmmmovo
 * generation time: 2021/01/31
 * filename: 828. 模拟栈.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;
int       n, s[N];
int       idx = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    string op;
    int    val;
    while (n--) {
        cin >> op;

        // cout << op << " " << idx << endl;

        if (op == "push") {
            cin >> val;
            s[++idx] = val;
        } else if (op == "query") {
            printf("%d\n", s[idx]);
        } else if (op == "pop") {
            idx--;
        } else {
            printf("%s\n", (idx > 0) ? "NO" : "YES");
        }
    }

    return 0;
}