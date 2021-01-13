/**
 * author: xmmmmmovo
 * generation time: 2021/01/13
 * filename: circle_square.cpp
 * language & build version : C 11 & C++ 17
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int b;

string to_B(int i, int b) {
    string tmp;
    char c;
    int num = 0;
    while (i != 0) {
        num = i % b;
        tmp.push_back(num < 10 ? num + '0' : ((num - 10) + 'A'));
        i /= b;
    }
    return string(tmp.rbegin(), tmp.rend());
}

bool judge(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &b);
    for (int i = 1; i <= 300; i++) {
        auto square = to_B(i * i, b);
        if (judge(square)) {
            auto num = to_B(i, b);
            cout << num << " " << square << endl;
        }
    }

    return 0;
}