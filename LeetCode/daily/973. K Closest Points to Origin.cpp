#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int dis(int x, int y) { return x * x + y * y; }

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        sort(points.begin(), points.end(),
             [&](vector<int> &a, vector<int> &b) {
                 return dis(a[0], a[1]) < dis(b[0], b[1]);
             });
        return vector<vector<int>>(points.begin(),
                                   points.begin() + k);
    }
};