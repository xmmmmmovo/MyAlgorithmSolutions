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
    a += b;

    string res;
    bool   minus = false;
    if (a < 0) {
        a     = -a;
        minus = true;
    }

    int flag = 1, k = a;
    while (k != 0) {
        res.push_back((k % 10) + '0');
        k /= 10;
        if (a > 9999 && flag % 3 == 0)
            res.push_back(',');
        flag++;
    }

    while (res.back() == ',')
        res.pop_back();

    if (minus)
        cout << "-";
    cout << string(res.rbegin(), res.rend());

    return 0;
}