/**
 * author: xmmmmmovo
 * generation time: 2021/03/06
 * filename: 503. 下一个更大元素 I.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int>  s;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (s.size() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }

        return res;
    }
};