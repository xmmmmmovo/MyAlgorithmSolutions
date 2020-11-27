package `5488`

import kotlin.test.assertEquals

class Solution {
    fun minOperations(n: Int): Int {
        // 中位数是n
        return (n * n) shr 2
    }
}


fun main() {
    assertEquals(2, Solution().minOperations(3))
    assertEquals(9, Solution().minOperations(6))
}