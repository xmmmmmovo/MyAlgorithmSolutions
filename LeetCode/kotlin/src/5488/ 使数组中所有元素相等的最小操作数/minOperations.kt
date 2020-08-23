package `5488`

import kotlin.test.assertEquals

class Solution {
    fun isOdd(number: Int) = number % 2 != 0

    fun minOperations(n: Int): Int {
        // 中位数是n
        return if (isOdd(n)) {
            (n * n - 1) shr 2
        } else {
            (n * n) shr 2
        }
    }
}


fun main() {
    assertEquals(2, Solution().minOperations(3))
    assertEquals(9, Solution().minOperations(6))
}