#
# @lc app=leetcode.cn id=460 lang=python3
#
# [460] LFU缓存
#

# @lc code=start

from collections import defaultdict


class Data:
    """
    节点数据
    """

    def __init__(self, key, value, freq=0):
        self.key = key
        self.value = value
        self.freq = freq


class DoublyLinkedList:
    """
    双向链表
    """
    class Node:
        """
        节点类
        """

        def __init__(self, val, next=None, prev=None):
            self.val = val
            self.next = next
            self.prev = prev

    def __init__(self):
        self.head = self.Node(None)
        self.tail = self.Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head

    def front_insert(self, data):
        """
        前插数据
        """
        nn = self.Node(data, self.head.next, self.head)
        self.head.next.prev = nn
        self.head.next = nn
        return nn

    def front_node_insert(self, node):
        """
        前插节点
        """
        self.head.next.prev = node
        node.next = self.head.next
        self.head.next = node
        node.prev = self.head

    def empty(self):
        """
        判空
        """
        return True if self.head.next == self.tail else False

    def node_delete(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        node.next, node.prev = None, None

    def pop(self):
        if not self.empty():
            nn = self.tail.prev
            nn.prev.next = self.tail
            self.tail.prev = nn.prev
            return nn
        return None


class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity  # 定义最大容量
        self.min_freq = 1  # 最少使用的tabkey
        self.key_table = {}  # 存放kv
        self.freq_table = defaultdict(DoublyLinkedList)  # 存放频率链表

    def freq_update(self, node):
        self.freq_table[node.val.freq].node_delete(node)
        node.val.freq += 1
        if self.freq_table[node.val.freq - 1].empty():
            self.min_freq = node.val.freq
        self.freq_table[node.val.freq].front_node_insert(node)

    def first_append(self, data):
        nn = self.freq_table[data.freq].front_insert(data)
        self.key_table[data.key] = nn
        self.min_freq = 1

    def get(self, key: int) -> int:
        if key in self.key_table:
            self.freq_update(self.key_table[key])
            return self.key_table[key].val.value
        return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity != 0:
            if key in self.key_table:
                node = self.key_table[key]
                node.val.value = value
                self.freq_update(node)
            else:
                if len(self.key_table) == self.capacity:
                    # 这里删除需要删除的节点
                    nn = self.freq_table[self.min_freq].pop()
                    self.key_table.pop(nn.val.key)
                self.first_append(Data(key, value, 1))

# @lc code=end


cache = LFUCache(2)

cache.put(2, 1)
cache.put(1, 1)
cache.put(2, 3)
cache.put(4, 1)
print(f"1 = {cache.get(1)}")       # 返回 1
print(f"2 = {cache.get(2)}")       # 返回 1
