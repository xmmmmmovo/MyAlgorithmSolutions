#include <algorithm>
#include <string>

using namespace std;

class Solution {
  public:
    bool oneEditAway(string first, string second) {
        int dp[ first.size() ][ second.size() ];
        memset(dp, 0xFFFFFF, sizeof(dp));

        for (int i = 0; i < first.size(); i++) {
            for (int j = 0; j < second.size(); j++) {

            }
        }

        return true;
    }
};