//
// Created by xmmmmmovo on 2020/8/17.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(int x, vector<int> &a, int m) {
        int cnt    = 0;
        int target = a[ 0 ] + x;
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[ i ] < target && a[ i + 1 ] >= target) {
                cnt++;
                target = a[ i + 1 ] + x;
            }
        }
        return cnt >= m - 1;
    }

    int maxDistance(vector<int> &a, int m) {
        sort(a.begin(), a.end());
        int len  = a.size();
        int diff = a[ len - 1 ] - a[ 0 ];// 最大间隔
        int mn   = INT_MAX;              // 记录最小间隔
        for (int i = 0; i < len - 1; i++) {
            if (mn > a[ i + 1 ] - a[ i ]) {
                mn = a[ i + 1 ] - a[ i ];
            }
        }
        if (m == 2) {// 这里特判了m = 2的情况，也可以归到底下的代码中。
            return diff;
        } else {
            int l = mn, r = diff / (m - 1);// 确定左右边界
            while (l <= r) {               // 二分搜索
                int mid = (l + r) / 2;
                // printf("l = %d, r = %d, mid = %d\n", l, r, mid);
                if (check(mid, a, m)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return l - 1;
        }
    }
};

int main() {
    auto a = vector<int>{1, 2, 3, 4, 7};
    Solution().maxDistance(a, 3);

    return 0;// return
}
