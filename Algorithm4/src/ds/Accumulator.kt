package ds

class Accumulator constructor(
    var sums: Double = 0.0
) {
    var times: Int = 0

    fun <T : Number> addDataValue(value: T) {
        sums += value.toDouble()
        times += 1
    }

    fun mean(): Double = sums / times

    override fun toString(): String {
        return "Mean ($times times, ${String.format("%.2f", sums)} values): " +
                "${String.format("%7.5f", mean())}"
    }
}
