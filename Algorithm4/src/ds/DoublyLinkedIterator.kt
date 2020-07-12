package ds

internal class DoublyLinkedIterator<T>(
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