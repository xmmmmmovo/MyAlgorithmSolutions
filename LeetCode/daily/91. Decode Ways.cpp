class Solution {
  public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }

        int dp0 = 1, dpi2 = 0, dpi1 = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != '0') {
                dp0 = dpi1;

                if (s[i - 1] == '1' ||
                    (s[i - 1] == '2' && s[i] <= '6')) {
                    dp0 += (i - 2 >= 0) ? dpi2 : 1;
                }
            } else {
                if (s[i - 1] == '0' || s[i - 1] > '2')
                    return 0;
                dp0 = (i - 2 >= 0) ? dpi2 : 1;
            }
            dpi2 = dpi1;
            dpi1 = dp0;
            dp0  = 0;
        }

        return dpi1;
    }
};