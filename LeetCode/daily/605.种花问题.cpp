/**
 * author: xmmmmmovo
 * generation time: 2021/01/16
 * filename: 605. 种花问题.cpp
 * language & build version : C 11 & C++ 17
 */
#include <vector>
using namespace std;

class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[ i ] == 0) {
                if (i == flowerbed.size() - 1 || flowerbed[ i + 1 ] == 0) {
                    cnt++;
                    i++;
                }
            } else {
                i++;
            }
        }
        return cnt >= n;
    }
};