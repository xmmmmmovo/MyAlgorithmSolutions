package fundamentals

import ds.Queue

fun main() {
    val d = Queue<String>()

    for (i in 1..10) {
        d.enqueue(i.toString())
        println(d)
    }

    println(d.peek())

    d.dequeue()

    println(d)

}