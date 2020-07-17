package ds

import kotlin.math.sqrt

/**
 * 累加器 防抖动版本
 * */
class Accumulator constructor(
    private var total: Double = 0.0
) {
    private var times: Int = 0
    private var mean: Double = 0.0
    private var s: Double = 0.0

    fun <T : Number> addDataValue(value: T) {
        times += 1
        val dv = value.toDouble()
        total += dv

        s += 1.0 * (times - 1) / times * (dv - mean) * (dv - mean)
        mean += (dv - mean) / times
    }

    /**
     * 平均数
     * */
    fun mean(): Double = mean

    /**
     * 方差
     * */
    fun variance(): Double = if (times <= 1) Double.NaN else s / (times - 1)

    /**
     * 平均差
     * */
    fun stddev(): Double = sqrt(variance())

    /**
     * 和
     * */
    fun total(): Double = total

    override fun toString(): String {
        return "Mean ($times times, ${String.format("%.2f", total)} values): " +
                "${String.format("%7.5f", mean())}"
    }
}
