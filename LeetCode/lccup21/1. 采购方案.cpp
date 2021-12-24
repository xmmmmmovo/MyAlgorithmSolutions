/**
 * author: xmmmmmovo
 * generation time: 2021/04/05
 * filename: 1. 采购方案.cpp
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
using ll = long long;

const int MOD = 1e9 + 7;

class Solution {
  public:
    int purchasePlans(vector<int> &nums, int target) {
        ll res = 0;

        if (nums.size() < 2)
            return res;

        sort(nums.begin(), nums.end());

        ll i = 0, j = nums.size() - 1;

        while (i < j) {
            if (nums[i] + nums[j] <= target) {
                res += (j - i) % MOD;
                i++;
            } else {
                j--;
            }
        }

        return res % MOD;
    }
};