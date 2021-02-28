/**
 * author: xmmmmmovo
 * generation time: 2021/02/28
 * filename: 5689. 统计匹配检索规则的物品数量.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countMatches(vector<vector<string>> &items, string ruleKey,
                     string ruleValue) {
        int check = 0, res = 0;
        if (ruleKey == "type") {
            check = 0;
        } else if (ruleKey == "name") {
            check = 2;
        } else {
            check = 1;
        }

        for (auto &&item : items) {
            if (item[check] == ruleValue) {
                res++;
            }
        }

        return res;
    }
};