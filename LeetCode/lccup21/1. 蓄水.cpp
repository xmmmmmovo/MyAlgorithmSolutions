/**
 * author: xmmmmmovo
 * generation time: 2021/04/10
 * filename: 1. 蓄水.cpp
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

int times_cnt(int vat, int bucket) {
    if (bucket == 0)
        return 0xfffffff;
    return ceil(vat * 1.0 / bucket);
}

class Solution {
  public:
    int storeWater(vector<int> &bucket, vector<int> &vat) {
        int times = 0xfffffff, res = 0;
        for (int i = 0; i < bucket.size(); i++) {
            int tmp = times_cnt(vat[i], bucket[i]);
            if (tmp < times)
                times = tmp;
        }

        for (int i = 0; i < bucket.size(); i++) {
            while (times_cnt(vat[i], bucket[i]) > times) {
                bucket[i]++;
                res++;
            }
        }
        times = 0;
        for (int i = 0; i < bucket.size(); i++) {
            int tmp = times_cnt(vat[i], bucket[i]);
            if (tmp > times)
                times = tmp;
        }

        return res + times;
    }
};