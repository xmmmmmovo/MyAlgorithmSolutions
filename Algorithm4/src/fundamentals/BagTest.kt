package fundamentals

import ds.Bag

fun main() {
    val b = Bag<String>()
    for (i in 1..10) {
        println(i)
        b.add(i.toString())
    }

    for (it in b) {
        println(it)
    }
}