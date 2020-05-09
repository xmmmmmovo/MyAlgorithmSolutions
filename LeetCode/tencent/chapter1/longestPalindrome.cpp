//
// Created by xmmmmmovo on 2020/5/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    decltype(auto) expandCenter(string &s, int l, int r) {
        while (l >= 0 && r < s.length() && s[ l ] == s[ r ]) {
            l--;
            r++;
        }

        return make_pair(l + 1, r - l - 2);
    }


    string longestPalindrome(string s) {
        if (s == "") {
            return "";
        }

        pair<int, int> slpodd(0, 0), slpeven(0, 0);
        decltype(auto) res = make_pair(0, 0);


        for (int i = 0; i < s.length(); ++i) {
            slpodd  = expandCenter(s, i, i);
            slpeven = expandCenter(s, i, i + 1);
            res     = max(slpodd, slpeven,
                      [](const pair<int, int> &a, const pair<int, int> &b) {
                          return a.second < b.second;
                      });
            cout << res.first << " " << res.second << endl;
        }

        return s.substr(res.first, res.second);
    }
};

int main() {
    Solution();
}