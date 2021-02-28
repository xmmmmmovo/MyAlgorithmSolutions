/**
 * author: xmmmmmovo
 * generation time: 2021/02/28
 * filename: 5690. 最接近目标价格的甜点成本.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                    int target) {
        int res = 0xffffff, tmp = 0;
        sort(baseCosts.begin(), baseCosts.end());
        sort(toppingCosts.begin(), toppingCosts.end());
        int end = pow(3, toppingCosts.size());
        for (auto &&bc : baseCosts) {
            for (int i = 0; i < end; i++) {
                int ti = i;
                tmp    = bc;
                for (auto &&tc : toppingCosts) {
                    tmp += (ti % 3) * tc;
                    ti /= 3;
                }

                if (abs(res - target) > abs(tmp - target)) {
                    res = tmp;
                } else if (abs(res - target) == abs(tmp - target)) {
                    res = min(res, tmp);
                }
            }
        }

        return res;
    }
};

class Solution {
  public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                    int target) {
        int res = 0xffffff, tmp = 0;

        for (auto &&bc : baseCosts) {
            for (int j = 0; j < (1 << toppingCosts.size()); j++) {
                for (int k = j; k < (1 << toppingCosts.size()); k++) {
                    tmp = bc;
                    for (int i = 0; i < toppingCosts.size(); i++) {
                        // 第一次加
                        if (j & (1 << i))
                            tmp += toppingCosts[i];
                        // 第二次加
                        if (k & (1 << i))
                            tmp += toppingCosts[i];
                    }

                    if (abs(res - target) > abs(tmp - target)) {
                        res = tmp;
                    } else if (abs(res - target) ==
                               abs(tmp - target)) {
                        res = min(res, tmp);
                    }
                }
            }
        }

        return res;
    }
};