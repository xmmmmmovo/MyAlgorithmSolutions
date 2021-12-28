#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    int calculate(string s) {
        if (s.size() == 0)
            return 0;
        int        res  = 0;
        int        sign = 1;
        stack<int> num;

        for (int i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (c == ' ')
                continue;

            switch (c) {
            case '+':
                break;
            case '-':
                sign = -1;
                break;
            case '*':
                sign = 2;
                break;
            case '/':
                sign = 3;
                break;
            default:
                long n = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    n = n * 10 + s[i] - '0';
                    i++;
                }
                if (sign == -1 || sign == 1) {
                    num.push(sign * n);
                } else if (sign == 2) {
                    auto t = num.top();
                    num.pop();
                    num.push(t * n);
                } else if (sign == 3) {
                    auto t = num.top();
                    num.pop();
                    num.push(t / n);
                }
                i--;
                sign = 1;
                break;
            }
        }

        while (!num.empty()) {
            res += num.top();
            num.pop();
        }
        return res;
    }
};