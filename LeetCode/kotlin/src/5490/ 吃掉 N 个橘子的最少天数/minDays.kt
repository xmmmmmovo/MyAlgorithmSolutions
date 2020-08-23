package `5490`

import kotlin.collections.HashMap
import kotlin.math.min
import kotlin.test.assertEquals

class Solution {
    val map = HashMap<Int, Int>()

    fun minDays(n: Int): Int {
        if (n <= 2) {
            return n
        }

        if (map.containsKey(n)) {
            return map[n]!!
        }

        val min = min(minDays(n / 3) + n % 3, minDays(n / 2) + n % 2) + 1
        map[n] = min
        return min
    }
}

fun main() {
    assertEquals(4, Solution().minDays(10))
    assertEquals(3, Solution().minDays(6))
    assertEquals(1, Solution().minDays(1))
    assertEquals(6, Solution().minDays(56))
}