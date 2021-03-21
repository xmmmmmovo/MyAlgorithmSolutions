/**
 * author: xmmmmmovo
 * generation time: 2021/03/14
 * filename: 3302. 表达式求值.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string                   s;
unordered_map<char, int> p{
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
};

void eval(stack<int> &num, stack<char> &op) {
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    char c = op.top();
    op.pop();

    int tmp;
    if (c == '+')
        tmp = a + b;
    else if (c == '-')
        tmp = a - b;
    else if (c == '*')
        tmp = a * b;
    else
        tmp = a / b;
    num.push(tmp);
}

int main() {
    cin >> s;

    stack<int> num; // 这里不用string 定义是为了后面的优化
    stack<char> op;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            int j = i, tmp = 0;
            while (j < s.size() && isdigit(s[j]))
                tmp = tmp * 10 + s[j++] - '0';
            num.push(tmp);
            i = j - 1;
        } else if (c == '(') {
            op.push(c);
        } else if (c == ')') {
            while (op.top() != '(')
                eval(num, op);
            // 弹出'('
            op.pop();
        } else {
            while (op.size() && p[op.top()] >= p[c])
                eval(num, op);
            op.push(c);
        }
    }

    while (op.size())
        eval(num, op);

    cout << num.top() << endl;
    return 0;
}


0 0 1
0 0 2
1 7 2
1 7 3
2 9 3
1 16 1
1 16 2
1 16 3
2 1 3
2 1 4
3 3 4
2 4 2
1 0 0
0