#include <stack>

class MinStack {
  private:
    std::stack<int> s{};
    int             min{0};

  public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {}

    void pop() {}

    int top() {}

    int min() {}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */