package ds

/**
 * 栈类
 * */
class Stack<T> : Iterable<T> {
    private var first: Node<T>? = null
    private var n: Int = 0

    constructor()

    constructor(s: Stack<T>) {
        for (i in s) {
            push(i)
        }
    }

    /**
     * 是否空
     * */
    fun isEmpty(): Boolean = first == null

    /**
     * 栈大小
     * */
    fun size(): Int = n

    /**
     * 入栈
     * */
    fun push(item: T) {
        val oi = first
        first = Node(
            item,
            oi
        )
        n++
    }

    /**
     * 出栈
     * */
    fun pop(): T {
        if (isEmpty()) {
            throw NoSuchElementException("Stack underflow")
        }
        return first?.item.also {
            first = first?.next
            n--
        }!!
    }

    /**
     * 看栈顶
     * */
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