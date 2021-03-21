/**
 * author: xmmmmmovo
 * generation time: 2021/03/07
 * filename: 5698. 构成特定和需要添加的最少元素.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

class Solution {
  public:
    int minElements(vector<int> &nums, int limit, int goal) {
        ll sum = 0;
        for (auto &&n : nums) {
            sum += n;
        }
        ll diff = goal - sum;

        return (diff % limit) == 0 ? abs((diff / limit))
                                   : abs((diff / limit)) + 1;
    }
};