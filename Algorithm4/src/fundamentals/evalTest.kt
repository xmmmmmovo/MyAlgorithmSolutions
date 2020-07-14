package fundamentals

import algorithms.evalIntArithmetic

fun main() {
    println(evalIntArithmetic(""))
    println(evalIntArithmetic(" 1 + 2"))
    println(evalIntArithmetic("1+2*3+(4*5+6)*7"))
}