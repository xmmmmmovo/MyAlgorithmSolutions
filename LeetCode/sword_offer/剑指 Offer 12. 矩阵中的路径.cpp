/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 12. 矩阵中的路径.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        // 找开头
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0])
                    if (dfs(board, word, i, j, 0))
                        return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, const string &word, int x,
             int y, int cnt) {
        if (cnt == word.size() - 1)
            return true;
        bool res    = false;
        board[x][y] = '\0';
        for (int k = 0; k < 4; k++) {
            int tx = x + dx[k], ty = y + dy[k];
            if (tx >= 0 && ty >= 0 && tx < board.size() &&
                ty < board[0].size() &&
                board[tx][ty] == word[cnt + 1]) {
                res = res || dfs(board, word, tx, ty, cnt + 1);
            }
        }
        board[x][y] = word[cnt];
        return res;
    }
};