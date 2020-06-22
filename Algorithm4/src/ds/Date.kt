package ds

class Date : Comparable<Date> {
    private val year: Int
    private val month: Int
    private val day: Int

    constructor(
        y: Int = 0,
        m: Int = 0,
        d: Int = 0
    ) {
        if (!isDateValid(d, m, y))
            throw IllegalArgumentException("输入日期错误!")
        year = y
        month = m
        day = d
    }

    constructor(
        parseString: String
    ) {
        parseString.split("/").run {
            if (size < 3) {
                throw IllegalArgumentException("输入日期错误！")
            }
            year = get(0).toInt()
            month = get(1).toInt()
            day = get(2).toInt()
            if (!isDateValid(day, month, year))
                throw IllegalArgumentException("输入日期错误！")
        }

    }

    companion object {
        val monthDayList = listOf(0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
    }

    private fun isDateValid(d: Int, m: Int, y: Int): Boolean {
        if (m > 12 || m < 1) {
            return false
        }
        if (d > monthDayList[m] || d < 1) {
            return false
        }
        if (m == 2 && d == 29 && !isLeapYear(y)) {
            return false
        }
        return true
    }

    // is y a leap year?
    fun isLeapYear(y: Int): Boolean {
        if (y % 400 == 0) return true
        if (y % 100 == 0) return false
        return y % 4 == 0
    }

    fun year() = year
    fun month() = month
    fun day() = day

    override fun compareTo(other: Date): Int {
        if (this.year < other.year)
            return -1
        if (this.year > other.year)
            return 1
        if (this.month < other.month)
            return -1
        if (this.month > other.month)
            return 1
        if (this.day < other.day)
            return -1
        if (this.day > other.day)
            return 1
        return 0
    }

    override fun toString(): String {
        return "$year/$month/$day"
    }

    override fun hashCode(): Int {
        return day + 31 * month + 31 * 12 * year
    }
}