"""
5357. 设计一个支持增量操作的栈
请你设计一个支持下述操作的栈。

实现自定义栈类 CustomStack 

CustomStack(int maxSize)：用 maxSize 初始化对象，
maxSize 是栈中最多能容纳的元素数量，栈在增长到 maxSize 之后则不支持 push 操作。
void push(int x)：如果栈还未增长到 maxSize ，就将 x 添加到栈顶。
int pop()：返回栈顶的值，或栈为空时返回 -1 。
void inc(int k, int val)：栈底的 k 个元素的值都增加 val 。
如果栈中元素总数小于 k ，则栈中的所有元素都增加 val 。
"""


class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.maxSize = maxSize

    def push(self, x: int) -> None:
        if len(self.stack) == self.maxSize:
            return
        self.stack.append(x)

    def pop(self) -> int:
        return self.stack.pop() if len(self.stack) != 0 else -1

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, len(self.stack))):
            self.stack[i] += val


# Your CustomStack object will be instantiated and called as such:
obj = CustomStack(10)
for i in range(11):
    obj.push(i)
param_2 = obj.pop()
obj.increment(3, 100)
print(obj.pop())
