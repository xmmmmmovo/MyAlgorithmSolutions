package ds

class Counter constructor(
    private val tag: String = "",
    private var count: Int = 0
) : Comparable<Counter> {

    /**
     * 计数器+1
     * */
    fun increment() {
        count += 1
    }

    /**
     * 结尾多少count
     * */
    fun tally(): Int = count

    override fun compareTo(other: Counter): Int {
        if (this.count < other.count)
            return -1
        else if (this.count > other.count)
            return 1
        return 0
    }

    override fun toString(): String {
        return "$tag $count times"
    }

}