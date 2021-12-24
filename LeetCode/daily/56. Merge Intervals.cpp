#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> segs;

        int st = -2e9, ed = -2e9;
        sort(intervals.begin(), intervals.end());

        for (auto const &s : intervals) {
            if (ed < s[1]) {
                if (st != -2e9)
                    segs.emplace_back(vector<int>{st, ed});
                st = s[0], ed = s[1];
            } else {
                ed = max(ed, s[1]);
            }
        }

        return segs;
    }
};