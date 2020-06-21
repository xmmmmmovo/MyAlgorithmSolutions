package ds

class Accumulator constructor(
    var total: Double = 0.0
) {
    var times: Int = 0

    fun <T : Number> addDataValue(value: T) {
        total += value.toDouble()
        times += 1
    }

    fun mean(): Double = total / times

    override fun toString(): String {
        return "Mean ($times times, ${String.format("%.2f", total)} values): " +
                "${String.format("%7.5f", mean())}"
    }
}
