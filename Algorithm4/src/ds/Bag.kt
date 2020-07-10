package ds

import edu.princeton.cs.algs4.StdIn
import edu.princeton.cs.algs4.StdOut
import java.util.*


class Bag<T> : Iterable<T> {
    constructor() {
    }

    override fun iterator(): Iterator<T> {
        return Iterator<T>
    }

    private data class Node<T>(
        val item: T,
        var next: Node<T>
    )

    private class LinkedIterator<T>(
        private var current: Node<T>
    ) : Iterator<T> {

        override fun hasNext(): Boolean {
        }

        override fun next(): T {
        }
    }
}