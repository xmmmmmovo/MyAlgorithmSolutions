/**
 * author: xmmmmmovo
 * generation time: 2021/01/17
 * filename: 1001 A+B Format.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    auto s = to_string(a + b);
    // 100,000
    for (int i = 0; i < s.length(); i++) {
        printf("%c", s[i]);
        if (s[i] == '-')
            continue;
        if ((i + 1) % 3 == s.length() % 3 && i != s.length() - 1)
            printf(",");
    }

    return 0;
}