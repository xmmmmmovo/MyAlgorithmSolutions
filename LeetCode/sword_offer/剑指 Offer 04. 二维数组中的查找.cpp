/**
 * author: xmmmmmovo
 * generation time: 2021/01/16
 * filename: 剑指 Offer 04. 二维数组中的查找.cpp
 * language & build version : C 11 & C++ 17
 */
#include <vector>
using namespace std;

class Solution {
  public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int idxx = matrix[ 0 ].size() - 1, idxy = 0;
        while (idxx >= 0 && idxy < matrix.size()) {
            // cout << idxx << " " << idxy << " " << matrix[idxy][idxx] << endl;
            if (matrix[ idxy ][ idxx ] == target)
                return true;
            else if (matrix[ idxy ][ idxx ] > target)
                idxx--;
            else
                idxy++;
        }
        return false;
    }
};