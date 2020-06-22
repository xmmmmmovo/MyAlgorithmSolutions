package fundamentals

import ds.Point2DMinDistanceCalculator

fun main() {
    val p = Point2DMinDistanceCalculator(10)
    p.showPoints()
    val fd = p.minDistanceForce()
    val dd = p.minDistanceDivide()
    println(fd)
    println(dd)
}