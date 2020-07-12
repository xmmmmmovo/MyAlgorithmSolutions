package ds

class LinkedList<T> : Iterable<T> {
    private var first: Node<T>? = null

    override fun iterator(): Iterator<T> {
        return DoublyLinkedIterator(first)
    }
}