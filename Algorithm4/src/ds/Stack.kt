package ds

class Stack<T> : Iterable<T> {
    private var first: Node<T>? = null
    private var n: Int = 0

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

    fun pop(): T? {
        if (isEmpty()) {
            throw NoSuchElementException("Stack underflow")
        }
        return first?.item.also {
            first = first?.next
            n--
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
}