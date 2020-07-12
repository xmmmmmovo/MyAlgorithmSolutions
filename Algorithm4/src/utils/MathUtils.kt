package utils

import ds.Stack
import java.lang.StringBuilder
import java.lang.UnsupportedOperationException
import java.util.*
import kotlin.collections.HashMap
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
 * 优先级
 * 加减优先级最低
 * 然后就是乘除
 * 括号优先级最高
 * */
val priority = HashMap<String, Int>().apply {
    put("+", 0)
    put("-", 0)
    put("*", 1)
    put("/", 1)
    put("(", 2)
    put(")", 2)
}

/**
 * 中缀转后缀
 * */
private fun infixToPostfix(expr: String): String {
    val sb = StringBuilder()
    val s = Stack<Char>()

    expr.forEach { c: Char ->
        when (c) {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' -> sb.append(c)
            '+', '-', '*', '/' -> {
                while (!s.isEmpty()
                    && s.peek() != '('
                    && priority[c.toString()]!! <= priority[s.peek().toString()]!!
                ) {
                    sb.append(s.pop())
                }
                s.push(c)
            }
            '(' -> s.push(c)
            ')' -> {
                while (!s.isEmpty()) {
                    if (s.peek() == '(') {
                        s.pop()
                        break
                    } else {
                        sb.append(s.pop())
                    }
                }
            }
            else -> throw UnsupportedOperationException("未知字符!")
        }
    }
    while (!s.isEmpty()) {
        sb.append(s.pop())
    }
    return sb.toString()
}

/**
 * 计算后缀表达式
 * */
private fun evalPostfix(expr: String): Double {
    val s = Stack<Double>()
    expr.forEach { c: Char ->
        when (c) {
            '+' -> s.pop()?.plus(s.pop()!!)?.let { s.push(it) }
            '-' -> s.pop()?.minus(s.pop()!!)?.let { s.push(it) }
            '*' -> s.pop()?.times(s.pop()!!)?.let { s.push(it) }
            '/' -> s.pop()?.div(s.pop()!!)?.let { s.push(it) }
            else -> s.push(Character.getNumericValue(c).toDouble())
        }
    }
    return if (s.isEmpty()) 0.0 else s.pop()!!
}

/**
 * 四则运算(带括号)
 * */
fun evalIntArithmetic(expr: String): Double =
    evalPostfix(infixToPostfix(expr.trim().replace(" ", "")))

/**
 * 括号是否匹配
 * */
fun isBanlanced(expr: String): Boolean {
    val s = Stack<Char>()

    expr.forEach { c: Char ->
        when (c) {
            '(', '{', '[' -> s.push(c)
            ')' -> if (s.isEmpty() || s.pop() != '(') return false
            ']' -> if (s.isEmpty() || s.pop() != '[') return false
            '}' -> if (s.isEmpty() || s.pop() != '{') return false
        }
    }

    return true
}


