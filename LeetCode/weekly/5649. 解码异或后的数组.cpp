#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> decode(vector<int> &encoded, int first) {
        vector<int> res(encoded.size() + 1, first);

        for (size_t i = 0; i < encoded.size(); i++) {
            res[ i ] = res[ i ] ^ encoded[ i ];
        }

        return res;
    }
};
