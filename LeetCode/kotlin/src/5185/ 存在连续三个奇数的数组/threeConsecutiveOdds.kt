package `5185`

import kotlin.test.assertEquals

class Solution {
    fun isOdd(number: Int) = number % 2 != 0

    fun threeConsecutiveOdds(arr: IntArray): Boolean {
        for (i in 0 until arr.size - 2) {
            if (isOdd(arr[i]) && isOdd(arr[i + 1]) && isOdd(arr[i + 2])) return true
        }
        return false
    }
}

fun main() {
    assertEquals(false, Solution().threeConsecutiveOdds(listOf(2, 6, 4, 1).toIntArray()))
    assertEquals(true, Solution().threeConsecutiveOdds(listOf(1, 2, 34, 3, 4, 5, 7, 23, 12).toIntArray()))
}