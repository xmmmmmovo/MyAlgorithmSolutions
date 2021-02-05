/**
 * author: xmmmmmovo
 * generation time: 2021/01/31
 * filename: 830. 单调栈.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

const int  N = 1e5 + 10;
int        n;
stack<int> s;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        while (!s.empty() && s.top() >= t)
            s.pop();
        if (!s.empty())
            cout << s.top() << " ";
        else
            cout << -1 << " ";

        s.push(t);
    }

    return 0;
}