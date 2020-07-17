package ds

import edu.princeton.cs.algs4.StdDraw
import kotlin.math.sqrt

/**
 * 可视化累加器
 * */
class VisualAccumulator constructor(
    private val xMax: Int = 100,
    private val yMax: Double = 100.0
) {
    private var times: Int = 0
    private var total: Double = 0.0
    private var mean: Double = 0.0
    private var s: Double = 0.0

    init {
        StdDraw.setXscale(0.0, xMax.toDouble())
        StdDraw.setYscale(0.0, yMax)
        StdDraw.setPenRadius(.01)
    }

    fun <T : Number> addDataValue(value: T) {
        times += 1
        val dv = value.toDouble()
        total += dv

        mean += (dv - mean) / times
        s += 1.0 * (times - 1) / times * (dv - mean) * (dv - mean)

        StdDraw.setPenColor(StdDraw.DARK_GRAY)
        StdDraw.point(times.toDouble(), value.toDouble())
        StdDraw.setPenColor(StdDraw.RED)
        StdDraw.point(times.toDouble(), mean())
        StdDraw.setPenColor(StdDraw.BLUE)
        StdDraw.point(times.toDouble(), stddev())
    }

    fun mean(): Double = mean

    fun variance(): Double = if (times <= 1) 0.0 else s / (times - 1)

    fun stddev(): Double = sqrt(variance())

    fun total(): Double = total

    override fun toString(): String {
        return "Mean ($times times, ${String.format("%.2f", total)} values): " +
                "${String.format("%7.5f", mean())}"
    }
}