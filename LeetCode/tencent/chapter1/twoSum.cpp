//
// Created by xmmmmmovo on 2020/5/8.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[ i ]) != m.end()) {
                return vector<int>{m[ target - nums[ i ] ], i};
            }
            m[ nums[ i ] ] = i;
        }
        return vector<int>();
    }
};

int main() {
    Solution();
}