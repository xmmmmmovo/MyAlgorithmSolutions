/**
 * author: xmmmmmovo
 * generation time: 2021/03/03
 * filename: 338. 比特位计数.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int low_bit(int x) { return x & -x; }

class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);

        for (int i = 0; i <= num; i++) {
            int t = 0, tt = i;
            while (tt)
                tt -= low_bit(tt), t++;
            res[i] = t;
        }

        return res;
    }
};

class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }

        return res;
    }
};