csci333-queue
=============

Just a quick note about the performance tests:

I ran 3 different performance tests.  The first performed 20,000,000 enqueues, the second performed 20,000,000 dequeues, and the third did 10,000,000 enqueues followed by 8,000,000 dequeues, followed by another 10,000,000 enqueues and another 8,000,000 dequeues.

The results were as follows:
20,000,000 enqueues
Array based Queue: 1.2 seconds
Linked List based Queue: 2.53 seconds
STL List based Queue: 3.49 seconds

20,000,000 dequeues
Array based Queue: 0.8 seconds
Linked List based Queue: 0.93 seconds
STL List based Queue: 2.24 seconds

Mixed enqueues and dequeues
Array based Queue: 2.04 seconds
Linked List based Queue: 2.09 seconds
STL List based Queue: 3.98 seconds

These results are interesting.  The array based implementation is much faster for enqueues despite the copying of the entire array which happens each time it expands.  For dequeues and the mix of enqueues and dequeues, the array based implementation was only slightly faster than the linked list implementation.  The STL list implemenation lagged significantly in all areas.  That said, I'm sure that when it comes to navigating a list backward, the STL list, a doubly linked list will shine.  And when it comes to inserting and deleting elements from the middle of the list, the linked list will probably outperform the array.  The mix of enqueues and dequeues times are very similar for the array and the linked list and I wonder if the ring buffer has something to do with that.  Looking a little more carefully, it looks like the array mixed performance is similar to the sum of the enqueue and dequeue performance whereas both the STL list and linked list both achieved some kind of efficiency performance gains by switching between enqueues and dequeues.
