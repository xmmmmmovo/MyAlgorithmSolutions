package fundamentals

import algorithms.fourSumForce
import ds.Buffer

data class tt(var string: String = "")

fun test1() {
    var t = tt("11")

    var tmp = tt("22")
    println(t.string.let {
        t = tmp
    })

    println(tmp)

    for (i in 1..10)
        println(i)
}

fun main() {
    fourSumForce(listOf(1, 2, 3, 4, 5), 1)

}