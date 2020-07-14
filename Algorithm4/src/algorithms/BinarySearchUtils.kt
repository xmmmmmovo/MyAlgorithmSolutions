package algorithms

fun <T : Comparable<T>> binarySearch(list: List<T>, key: T): Int {

    var lo = 0
    var hi = list.size - 1

    while (lo <= hi) {
        val mid = lo + (hi - lo) / 2
        if (key < list[mid]) {
            hi = mid - 1
        } else if (key > list[mid]) {
            lo = mid + 1
        } else {
            return mid
        }
    }

    return -1
}

fun <T : Comparable<T>> containsInList(list: List<T>, key: T): Boolean {
    val sorted = list.sorted()
    val res = binarySearch(sorted, key)
    return res != -1
}