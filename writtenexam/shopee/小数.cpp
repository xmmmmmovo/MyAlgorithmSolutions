#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

string s;

int gcd(int x, int y) {
    do {
        auto t = x % y;
        x      = y;
        y      = t;
    } while (y);
    return x;
}

int main() {
    cin >> s;
    int rs = 0, rd = 0;
    int ps = 0, pd = 0;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '.') {
            ps = i + 1;
        } else if (c == '(') {
            pd = i;
            rs = i + 1;
        } else if (c == ')') {
            rd = i;
        }
    }

    int ptmp = pd - ps;
    if (rd - rs >= ptmp) {
        int rn = 0, pn = 0;
        for (int i = 0; i < ptmp; i++) {
            int t = 1;
            for (int j = ptmp - 1; j > i; j--)
                t *= 10;
            rn += t * 9;
            pn += t * (s[ps + i] - '0');
            // printf("%d %d\n", rn, pn);
        }

        // printf("%d %d\n", rn, pn);
        // 辗转相除法
        auto res = gcd(rn, pn);
        // printf("%d\n", res);
        printf("%d/%d\n", pn / res, rn / res);
    } else {
    }

    return 0;
}