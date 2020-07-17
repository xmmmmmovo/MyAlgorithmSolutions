package fundamentals

import ds.LinkedList

fun main() {
    val ll = LinkedList<Int>()
    for (i in 1..10)
        ll.add(i)
    println(ll)
    ll.reverse()
    println(ll)
    val it = ll.listIterator()
    while (it.hasNext()) {
        print("${it.next()} ")
    }
    println()
    while (it.hasPrevious()) {
        print("${it.previous()} ")
    }
    println()
    ll.addFirst(111)
    ll.addLast(222)
    println(ll)
    ll.removeFirst()
    ll.removeLast()
    println(ll)
    ll.removeAt(1)
    println(ll)
    ll.add(9, 114514)
    println(ll)
    println(ll.size)
    ll.clear()
    println(ll)
    ll.addAll(listOf(1111, 2222, 3333, 4444))
    println(ll)
    ll.clear()
    ll.addAll(0, listOf(121, 222, 3445))
    println(ll)
    println(ll.getFirst())
    println(ll.getLast())
    ll.set(2, 1000000)
    println(ll)
    ll.remove(121)
    println(ll)
    ll.removeAll(listOf(222, 1000000))
    println(ll)
    ll.addAll(listOf(1123, 1122, 2234))
    ll.retainAll(listOf(1123))
    println(ll)
}
