#
# @lc app=leetcode.cn id=225 lang=python3
#
# [225] 用队列实现栈
#

# @lc code=start

from collections import deque


class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = deque()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.d.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.d.pop()

    def top(self) -> int:
        """
        Get the top element.
        """
        return None if self.empty() else self.d[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not len(self.d)


# @lc code=end

# Your MyStack object will be instantiated and called as such:
obj = MyStack()
obj.push(111)
param_2 = obj.pop()
param_3 = obj.top()
param_4 = obj.empty()

print(param_2)
print(param_3)
print(param_4)
