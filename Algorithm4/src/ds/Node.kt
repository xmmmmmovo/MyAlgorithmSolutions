package ds

internal data class Node<T>(
    val item: T,
    var next: Node<T>? = null,
    var prev: Node<T>? = null
)