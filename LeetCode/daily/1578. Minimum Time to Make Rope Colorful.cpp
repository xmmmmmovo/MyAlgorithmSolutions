class Solution {
  public:
    int minCost(string colors, vector<int> &neededTime) {
        if (colors.size() < 2) {
            return 0;
        }
        int res = 0;

        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                // remain max value
                int maxv = neededTime[i - 1];
                res += maxv;
                do {
                    if (maxv < neededTime[i]) {
                        maxv = neededTime[i];
                    }
                    res += neededTime[i];
                    i++;
                } while (i < colors.size() &&
                         colors[i - 1] == colors[i]);
                res -= maxv;
            }
        }

        return res;
    }
};