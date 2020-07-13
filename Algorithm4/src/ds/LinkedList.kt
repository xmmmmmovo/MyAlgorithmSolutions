package ds

import java.util.LinkedList
import java.util.Stack

class LinkedList<T> : List<T> {
    private var first: Node<T>? = null
    private var last: Node<T>? = null
    private var _size: Int = 0


    override val size: Int
        get() = _size

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

    override fun contains(element: T): Boolean {
        TODO("Not yet implemented")
    }

    override fun containsAll(elements: Collection<T>): Boolean {
        TODO("Not yet implemented")
    }

    override fun get(index: Int): T {
        TODO("Not yet implemented")
    }

    override fun indexOf(element: T): Int {
        TODO("Not yet implemented")
    }

    override fun isEmpty(): Boolean {
        TODO("Not yet implemented")

    }

    override fun lastIndexOf(element: T): Int {
        TODO("Not yet implemented")

    }

    override fun iterator(): Iterator<T> {
        TODO("Not yet implemented")

    }

    override fun listIterator(): ListIterator<T> {
        TODO("Not yet implemented")

    }

    override fun listIterator(index: Int): ListIterator<T> {
        TODO("Not yet implemented")

    }

    override fun subList(fromIndex: Int, toIndex: Int): List<T> {
        TODO("Not yet implemented")

    }

    companion object {
        private data class Node<T>(
            val item: T,
            var next: Node<T>? = null,
            var prev: Node<T>? = null
        )
    }

    private class LinkedListIterator<T>(
        private var current: Node<T>?
    ) : ListIterator<T> {
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
            TODO("Not yet implemented")

        }

        override fun hasPrevious(): Boolean {
            TODO("Not yet implemented")

        }

        override fun nextIndex(): Int {
            TODO("Not yet implemented")

        }

        override fun previous(): T {
            TODO("Not yet implemented")

        }

        override fun previousIndex(): Int {
            TODO("Not yet implemented")

        }
    }
}