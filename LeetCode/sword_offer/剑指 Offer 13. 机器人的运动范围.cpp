/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 13. 机器人的运动范围.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N     = 110;
int       dx[2] = {0, 1}, dy[2] = {1, 0};

class Solution {
  public:
    int movingCount(int m, int n, int k) {
        if (!k)
            return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        this->vis[0][0] = 1;
        int res         = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 2; d++) {
                int tx = x + dx[d], ty = y + dy[d];
                if (tx >= 0 && ty >= 0 && tx < m && ty < n &&
                    this->vis[tx][ty] == 0 &&
                    ((sum(tx) + sum(ty)) <= k)) {
                    q.push({tx, ty});
                    this->vis[tx][ty] = 1;
                    res++;
                }
            }
        }
        return res;
    }

  private:
    int vis[N][N];
    int sum(int x) {
        int res = 0;
        while (x != 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};