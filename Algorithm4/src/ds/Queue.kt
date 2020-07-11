package ds

class Queue<T> : Iterable<T> {
    private var first: Node<T>? = null
    private var last: Node<T>? = null
    private var n: Int = 0

    fun isEmpty(): Boolean = first == null

    fun size(): Int = n

    fun enqueue(item: T) {
        val ol = last
        last = Node(
            item,
            null
        )
        if (isEmpty()) {
            first = last
        } else {
            ol?.next = last
        }
        n++
    }

    fun dequeue(): T? {
        if (isEmpty()) {
            throw NoSuchElementException("Stack underflow")
        }
        return first?.item.also {
            first = first?.next
            n--
            if (isEmpty()) {
                last = null
            }
        }
    }

    fun peek(): T? {
        if (isEmpty()) {
            throw NoSuchElementException("Stack underflow")
        }
        return first?.item
    }

    override fun toString(): String {
        return StringBuilder().also {
            this.forEach { item -> it.append("$item ") }
        }.toString()
    }

    override fun iterator(): Iterator<T> {
        return LinkedIterator(first)
    }

    private data class Node<T>(
        val item: T,
        var next: Node<T>? = null
    )

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