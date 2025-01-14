/*
Comparison and Conclusion for Question 1c based on 1a and 1b:

Question 1a: The sorted merge of two lists was performed using single linked lists.
Question 1b: The same operation was repeated using double linked lists.

Single Linked List:

Memory Efficiency: Single linked lists are more memory-efficient since each node holds only one pointer (next).
Traversal Limitation: Traversal is unidirectional, which can make certain operations (such as backward traversal) more difficult.
Conclusion: A lightweight and sufficient structure for sorted merge operations,
especially if memory efficiency is a priority.

Double Linked List:

Memory Usage: Each node holds two pointers (next and prev), which increases memory consumption.
Bidirectional Traversal: Allows both forward and backward traversal, providing more flexibility.
Conclusion: If memory usage is not a concern and flexibility in navigation is desired,
a double linked list is more suitable.

Final Verdict:

Although both data structures have the same time complexity for the merge operation (O(n + m)),
single linked lists are preferable in terms of memory usage,
while double linked lists offer better flexibility at the cost of additional memory.
*/