/**
 * author: xmmmmmovo
 * generation time: 2021/01/26
 * filename: 1128. 等价多米诺骨牌对的数量.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        int         res = 0;
        vector<int> n(100, 0);
        for (auto const &d : dominoes) {
            res += n[max(d[0], d[1]) * 10 + min(d[0], d[1])]++;
        }
        return res;
    }
};