/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 09. 用两个栈实现队列.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class CQueue {
  public:
    CQueue() {}

    void appendTail(int value) { l.push(value); }

    int deleteHead() {
        if (l.empty() && r.empty())
            return -1;
        if (r.size()) {
            auto t = r.top();
            r.pop();
            return t;
        }
        while (l.size()) {
            r.push(l.top());
            l.pop();
        }
        auto t = r.top();
        r.pop();
        return t;
    }

  private:
    stack<int> l;
    stack<int> r;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */