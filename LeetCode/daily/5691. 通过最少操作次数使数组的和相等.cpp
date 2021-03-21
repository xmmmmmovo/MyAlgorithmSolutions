/**
 * author: xmmmmmovo
 * generation time: 2021/02/28
 * filename: 5691. 通过最少操作次数使数组的和相等.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        auto sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        auto sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (sum1 == sum2)
            return 0;
        if (sum1 > sum2)
            return minOperations(nums2, nums1);

        int diff = sum2 - sum1;

        vector<int> freq(6);
        for (auto &&n : nums1) {
            ++freq[6 - n];
        }

        for (auto &&n : nums2) {
            ++freq[n - 1];
        }

        int res = 0;
        for (int i = 5; i >= 1 && diff > 0; i--) {
            while (freq[i] && diff > 0) {
                ++res;
                --freq[i];
                diff -= i;
            }
        }

        return diff > 0 ? -1 : res;
    }
};