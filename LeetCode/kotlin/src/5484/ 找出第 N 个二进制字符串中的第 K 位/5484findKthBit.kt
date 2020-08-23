package `5484`

import kotlin.test.assertEquals

class Solution {
    fun findKthBit(n: Int, k: Int): Char {
        var len = 0
        while (len < k) {
            len = 2 * len + 1
        }

        var res = k
        var times = 0
        while (len > 2) {
            if (res > len shr 2) {
                res = len - res
                times++
            }
            len = len shr 2
        }

        // 这里如果是刚好反转两次并且取第一个的话是不会变化的 就是0
        // 缺一条件 都是反向 就是1
        return if (res == 1) {
            if (times % 2 != 0) '1'
            else '0'
        } else {
            if (times % 2 != 0) '0'
            else '1'
        }
    }
}

fun main() {
    assertEquals('0', Solution().findKthBit(n = 3, k = 1))
    assertEquals('1', Solution().findKthBit(n = 4, k = 11))
    assertEquals('0', Solution().findKthBit(n = 1, k = 1))
    assertEquals('1', Solution().findKthBit(n = 2, k = 3))
    assertEquals('0', Solution().findKthBit(n = 3, k = 5))
    assertEquals('0', Solution().findKthBit(n = 3, k = 2))
}