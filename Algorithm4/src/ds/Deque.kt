package ds

import java.util.Deque

class Deque<T> : Iterable<T> {
    private val list = LinkedList<T>()

    fun isEmpty() = list.size == 0

    fun size() = list.size

    fun pushLeft(element: T) = list.addFirst(element)

    fun pushRight(element: T) = list.addLast(element)

    fun popLeft(): T = list.removeFirst()

    fun popRight(): T = list.removeLast()

    override fun toString(): String {
        return list.toString()
    }

    override fun iterator(): Iterator<T> {
        return list.iterator()
    }
}