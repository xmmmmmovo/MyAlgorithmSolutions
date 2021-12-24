#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = tmp.find(target - nums[i]);
            if (it != tmp.end()) {
                return {it->second, i};
            }
            tmp[nums[i]] = i;
        }
        return {};
    }
};