package ds

class Stack<T> : Iterable<T> {
    private var first: Node<T>? = null
    private var n: Int = 0

    constructor()

    constructor(s: Stack<T>) {
        for (i in s) {
            push(i)
        }
    }

    fun isEmpty(): Boolean = first == null

    fun size(): Int = n

    fun push(item: T) {
        val oi = first
        first = Node(
            item,
            oi
        )
        n++
    }

    fun pop(): T {
        if (isEmpty()) {
            throw NoSuchElementException("Stack underflow")
        }
        return first?.item.also {
            first = first?.next
            n--
        }!!
    }

    fun peek(): T {
        if (isEmpty()) {
            throw NoSuchElementException("Stack underflow")
        }
        return first?.item!!
    }

    override fun toString(): String {
        return StringBuilder().also {
            this.forEach { item -> it.append("$item ") }
        }.toString()
    }

    override fun iterator(): Iterator<T> {
        return LinkedIterator(first)
    }

    companion object {
        private data class Node<T>(
            val item: T,
            var next: Node<T>? = null
        )
    }

    private class LinkedIterator<T>(
        private var current: Node<T>?
    ) : Iterator<T> {

        override fun hasNext(): Boolean {
            return current != null
        }

        fun remove() {
            throw UnsupportedOperationException()
        }

        override fun next(): T {
            if (!hasNext()) {
                throw NoSuchElementException()
            }
            val item = current?.item
            current = current?.next
            return item!!
        }
    }
}