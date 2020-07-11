package utils

import kotlin.math.abs
import kotlin.math.min

/**
 * 普通gcd模板
 * */
fun <T : Number> gcd(a: T, b: T): Long {
    if (a == 0) return b.toLong()
    if (b == 0) return a.toLong()
    var ta = abs(a.toLong())
    var tb = abs(b.toLong())
    while (tb != 0L) {
        ta = tb.also {
            tb = ta % tb
        }
    }
    return ta
}

/**
 * 快速gcd模板
 * */
private fun qgcd_(a: Long, b: Long): Long {
    if (a == 0L) return b
    if (b == 0L) return a

    if ((a and 1) == 0L && (b and 1) == 0L)
        return qgcd_(a shr 1, b shr 1) shl 1
    else if ((b and 1) == 0L)
        return qgcd_(a, b shr 1)
    else if ((a and 1) == 0L)
        return qgcd_(a shr 1, b)
    else
        return qgcd_(abs(a - b), min(a, b))
}

fun <T : Number> qgcd(a: T, b: T): Long {
    if (a == 0) return b.toLong()
    if (b == 0) return a.toLong()
    var ta = a.toLong()
    var tb = b.toLong()
    return qgcd_(abs(ta), abs(tb))
}

/**
 * 四则运算(带括号)
 * */
fun calcuArithmetic(expr: String): Double {


    return 0.0
}







