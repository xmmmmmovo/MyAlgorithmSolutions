/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 11. 旋转数组的最小数字.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minArray(vector<int> &numbers) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (numbers[mid] > numbers[r])
                l = mid + 1;
            else if (numbers[mid] < numbers[r])
                r = mid;
            else
                r = r - 1;
        }

        return numbers[l];
    }
};
