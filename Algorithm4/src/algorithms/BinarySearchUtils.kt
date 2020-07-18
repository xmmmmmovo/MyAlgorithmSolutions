package algorithms

fun <T : Comparable<T>> binarySearch(
    list: List<T>, key: T, lo: Int = 0, hi: Int = list.size - 1
): Int {

    var lo = lo
    var hi = hi

    while (lo <= hi) {
        val mid = lo + (hi - lo) / 2
        when {
            key < list[mid] -> {
                hi = mid - 1
            }
            key > list[mid] -> {
                lo = mid + 1
            }
            else -> {
                return mid
            }
        }
    }

    return -1
}

fun <T : Comparable<T>> containsInList(list: List<T>, key: T): Boolean {
    val sorted = list.sorted()
    val res = binarySearch(sorted, key)
    return res != -1
}