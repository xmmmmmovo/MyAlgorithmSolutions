//
// Created by xmmmmmovo on 2020/5/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> stack;
        for (decltype(auto) it : s) {
            switch (it) {
                case '(':
                    stack.push(it);
                    break;
                case '[':
                    stack.push(it);
                    break;
                case '{':
                    stack.push(it);
                    break;
                case ')':
                    if (stack.empty() || stack.top() != '(') {
                        return false;
                    }
                    stack.pop();
                    break;
                case ']':
                    if (stack.empty() || stack.top() != '[') {
                        return false;
                    }
                    stack.pop();
                    break;
                case '}':
                    if (stack.empty() || stack.top() != '{') {
                        return false;
                    }
                    stack.pop();
                    break;
                default:
                    return false;
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution();
}