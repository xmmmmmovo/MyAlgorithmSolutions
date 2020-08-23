package `5489`

import kotlin.test.assertEquals

class Solution {
    fun maxDistance(position: IntArray, m: Int): Int {
        position.sort()
        val maxp = position.last() - position.first()
        var minp = Int.MAX_VALUE
        for (i in 0 until position.size - 1) {
            if (minp > position[i + 1] - position[i])
                minp = position[i + 1] - position[i]
        }

        var lo = minp
        var hi = maxp / (m - 1)
        
        val check = fun(inter: Int): Boolean {
            var cnt = 0
            // 因为第一个肯定是在首位，所以直接跳过一个
            var tmp = position[0] + inter
            for (i in position.indices) {
                if (position[i] >= tmp) {
                    cnt++
                    tmp = position[i] + inter
                }
            }
            return cnt >= m - 1
        }

        while (lo <= hi) {
            val mid = lo + ((hi - lo) shr 1)

            if (check(mid))
                lo = mid + 1
            else
                hi = mid - 1
        }

        return lo - 1
    }
}


fun main() {
    assertEquals(3, Solution().maxDistance(position = intArrayOf(1, 2, 3, 4, 7), m = 3))
    assertEquals(999999999, Solution().maxDistance(position = intArrayOf(5, 4, 3, 2, 1, 1000000000), m = 2))
}