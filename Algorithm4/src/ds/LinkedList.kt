package ds

import java.util.LinkedList

class LinkedList<T> : MutableIterable<T> {
    private var first: Node<T>? = null
    private var last: Node<T>? = null
    private var n: Int = 0

    fun getFirst(): T {
        if (first == null)
            throw NoSuchElementException()
        return first!!.item
    }

    fun getLast(): T {
        if (last == null)
            throw NoSuchElementException()
        return last!!.item
    }

    fun size() = n

    fun a() {
        LinkedList<Int>().remove()
    }

    override fun iterator(): MutableIterator<T> {
        return DoublyLinkedIterator(first)
    }

    private data class Node<T>(
        val item: T,
        var next: Node<T>? = null,
        var prev: Node<T>? = null
    )

    private class DoublyLinkedIterator<T>(
        private var current: Node<T>?
    ) : MutableIterator<T> {
        override fun hasNext(): Boolean {
            return current != null
        }

        override fun next(): T {
            if (!hasNext()) {
                throw NoSuchElementException()
            }
            val item = current?.item
            current = current?.next
            return item!!
        }

        override fun remove() {

        }
    }
}