//
// Created by xmmmmmovo on 2020/5/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            swap(s[ i ], s[ s.size() - i - 1 ]);
        }
    }

    string multiply(string num1, string num2) {
        string res(num1.length() + num2.length(), '\0');

        for_each(num1.begin(), num1.end(), [ & ](auto &item) {
            item = item - '0';
        });

        for_each(num2.begin(), num2.end(), [ & ](auto &item) {
            item = item - '0';
        });

        int st = 0, up = 0;
        for (decltype(auto) it = num2.rbegin(); it != num2.rend(); it++) {
            for (int i = num1.length() - 1; i >= 0; --i) {
                char t = num1[ i ] * (*it);
                up     = t / 10;
                res[ st + i ] += t % 10;
                if (res[ st + i ] >= 10) {
                    up += 1;
                    res[ st + i ] = res[ st + i ] % 10;
                }
                res[ st + i + 1 ] += up;
            }
            st++;
        }

        if (res[ res.length() - 1 ] == '\0') {
            res.resize(res.length() - 1);
        }
        for_each(res.begin(), res.end(), [ & ](auto &item) {
            item += '0';
        });
        reverseString(res);

        cout << res << endl;
        return res;
    }
};

int main() {
    //    Solution().multiply("2", "3");
    Solution().multiply("123", "456");

    return 0;
}