# Linked List Challenges
The repsitory contains the problems related to Linked List I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Merge K Sorted Lists
The goal is to implement a function that merges K sorted single linked lists. The complexity of the solution is a least O(N*log(k)) where N is the total number of nodes.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/merge-k-sorted-lists/description/)  
As of October 2<sup>nd</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit solution. Got correct
- [X] Implement the optimized divide and conquer solution
- [X] Submitted solution. Got correct
- [X] Problem solved

### Remove Nth Node From End of List
The goal of this challenge is to remove the n<sup>th</sup> starting from the end of a linked list.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)  
As of October 14<sup>th</sup>, 2019:
- [x] I wrote a recursive solution.
- [x] Submit solution. Got right in 0 ms with 8.5 MB
- [x] Find a solution that requires only one pass on the linked list
- [x] Submit solution. Got right in 4 ms with 8.4 MB
- [x] Problem solved

### Copy list with random pointers
The goal of this problem is to implement a function that does a deep copy of a
linked list where nodes hold a next node pointer as well as a random node
pointer, that can point to any node in the linked list.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/copy-list-with-random-pointer/)  
As of March 24<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to go with a solution that
      intertwine nodes from the original list with nodes from the new list so
      that for random pointer I only need to do `new_node->random =
      old_node->random->next`. The solution runs in O(3*N) = O(N) because I am
      running 3 times on the list. It uses O(1) extra space, not counting the
      space needed to store the new list.
- [X] Submit solution. Got correct in 8 ms with 11 MB
- [X] Problem solved

### Merge Two Sorted Lists
The goal of this problem is to implemented a function that merges 2 sorted
singly linked list.  
I tried to solve this problem using the C and Python language [Problem
link](https://leetcode.com/problems/merge-two-sorted-lists)  
As of March 25<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to go with function that creates
      a new list instead of just using the node from the previous ones. Thus it
      runs necessarily in O(N+M) but it uses O(N+M) extra space.
- [X] Submit solution. Got correct in 0 ms with 6.1 MB
- [X] Write a second solution in Python this time simply ordering the nodes of
      the two lists and return the merge so it uses only O(1) extra space.
- [X] Submit solution. Got correct in 32 ms with 12.9 MB
- [X] Problem solved

### Middle of the Linked List
The goal of this challenge is find and return the middle node of a given linked
list.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/middle-of-the-linked-list/)  
As of April 8<sup>th</sup>, 2020:
- [X] Find a first working solution. I went with the 2 pointers solution. I have
      one pointer moving through the list twice as fast as the other. When the
      first pointer arrives at the end of the list then the second one is in the
      middle of the list. The time complexity of this algorithm is O(N) since we
      are running through the list just once. We need only O(1) extra space.
- [X] Submit solution. Got correct in 0 ms with 5.3 MB
- [X] Problem solved
