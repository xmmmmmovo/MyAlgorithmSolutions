#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int findRepeatNumber(vector<int> &nums) {
        set<int> s;

        for (auto n : nums) {
            if (s.count(n)) {
                return n;
            }
            s.insert(n);
        }

        return 0;
    }
};