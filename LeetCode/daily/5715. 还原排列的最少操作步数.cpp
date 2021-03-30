/**
 * author: xmmmmmovo
 * generation time: 2021/03/28
 * filename: 5715. 还原排列的最少操作步数.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != i)
            return false;
    }
    return true;
}

class Solution {
  public:
    int reinitializePermutation(int n) {
        int         cnt = 0;
        vector<int> arr(n, 0);
        vector<int> perm(n, 0);

        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }

        do {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0)
                    arr[i] = perm[i / 2];
                else
                    arr[i] = perm[(n / 2) + (i - 1) / 2];
            }
            copy(arr.begin(), arr.end(), perm.begin());
            cnt++;
        } while (!check(perm));

        return cnt;
    }
};