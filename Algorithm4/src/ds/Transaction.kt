package ds

class Transaction : Comparable<Transaction> {
    private val who: String
    private val time: Date
    private val amount: Double

    constructor(
        w: String,
        t: Date,
        a: Double
    ) {
        if (!isAmountValid(a))
            throw IllegalArgumentException("输入金额格式错误!")
        who = w
        time = t
        amount = a
    }

    constructor(
        parseString: String
    ) {
        parseString.split(" ").run {
            if (size < 3) {
                throw IllegalArgumentException("输入格式错误！")
            }
            who = get(0)
            time = Date(get(1))
            amount = get(2).toDouble()
            if (!isAmountValid(amount))
                throw IllegalArgumentException("输入金额错误！")
        }

    }

    fun who() = who
    fun time() = time
    fun amount() = amount

    private fun isAmountValid(amount: Double): Boolean {
        if (
            Double.NaN == amount ||
            Double.NEGATIVE_INFINITY == amount ||
            Double.POSITIVE_INFINITY == amount
        ) {
            return false
        }
        return true
    }


    override fun compareTo(other: Transaction): Int {
        return compareValues(this.amount, other.amount)
    }

    override fun toString(): String {
        return String.format("%-10s %10s %8.2f", who, time, amount)
    }
}