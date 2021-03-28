/**
 * author: xmmmmmovo
 * generation time: 2021/03/28
 * filename: 5713. 字符串中不同整数的数目.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    int numDifferentIntegers(string word) {
        int                n = word.size();
        unordered_set<string> set;

        for (int i = 0; i < n; i++) {
            char c = word[i];

            if (isdigit(c)) {
                int j = i;
                string tmp;
                while (j < n && isdigit(word[j])){
                    if(tmp.size() == 0 && word[j] == '0'){
                        j++;
                        continue;
                    }
                    tmp += word[j++];
                }
                set.insert(tmp);
                i = j - 1;
            }
        }

        return set.size();
    }
};