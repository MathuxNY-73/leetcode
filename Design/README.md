# Design Challenged
The repsitory contains problems related to Design I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Implement Trie
The goal is to implement a Trie (Prefix Tree) data structure. This is a leetcode challenge.  
I tried to solve this problem using the C++ and C languages. [Problem link](https://leetcode.com/problems/implement-trie-prefix-tree/)  
As of July 18<sup>th</sup>, 2019:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 76 ms with 45.4 MB
- [x] Find a better solution
- [x] Submit solution. Got correct in 72 ms with 40.1 MB
- [X] Problem solved

### Find median from a data stream
The goal of this challenge is to code a class that computes the median of a
serie of number that are added one by one, like a stream of numbers. At any
given point the median can be computed.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/find-median-from-data-stream)  
As of February 20<sup>th</sup>, 2020:
- [X] Write a first solution using priority queues which in C++ are implemented
      using heaps. Time complexity of one step is O(log n) in that case,
      overall space complexity is O(n)
- [X] Submit solution. Got correct in 160 ms with 42.4 MB
- [X] Problem solved

### Moving Window Average from Data Stream
The goal of this challenge is to code a function that compute a window average
of numbers in a data stream.  
I tried to solve this problem using the Python and C languages [Problem
link](https://leetcode.com/problems/moving-average-from-data-stream)  
As February 21<sup>st</sup>, 2020:
- [X] Write a first solution using Queue. The solution is O(1) in time
      complexity as we keep a sum and count always up to date. It is O(W) in
      space complexity with W being the window size.
- [X] Submit solution. Got correct in 108 ms with 15.4 MB
- [X] Rewrite the solution in C this time using a cycling array. As the size of
      the array is fixed in my solution then memory complexity is O(1)
- [X] Submit solution. Got correct in 32 ms with 12.3 MB
- [X] Problem solved

### Product of the last k numbers
The goal of this challenge is to code a class that can compute the product of
the last K numbers in a serie of N numbers added 1 by 1. In my first solution I
used an vector to store the prefix product. It is also possible to answer the
problem using a Segment Tree maybe even a BIT (aka Fenwick Tree).  
I tried to solve this problem using the C++, C and Rust languages [Problem
link](https://leetcode.com/problems/product-of-the-last-k-numbers)  
As February 24<sup>th</sup>, 2020:
- [X] Write a first solution using an array. The solution is O(1) in time
      complexity as we compute the prefix product each time we add a number. It
      is O(N) in space complexity as at most N prefix products are stored.
- [X] Submit solution. Got correct in 180 ms with 62.4 MB
- [X] Rewrite a solution in C using Segment Tree. The solution is O(log N) in
      time complexity and O(4 * N) in space complexity.
- [X] Submit solution. Got correct in 172 ms with 46.6 MB
- [X] Write a second solution in Rust with Fenwick Tree. The solution is O(log
      N) ins time complexity and O(N) in space complexity.
- [X] Submit solution. Got correct in 48 ms with 15.3 MB
- [X] Problem solved

### Implement stack using queues
The goal of this challenge is to implement the APIs of a stack data structure
using only queues as underlying storage. In my first solution, I used 2 queues
to solve this problem. Then I saw it was possible to implement a stack using
only one queue.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/implement-stack-using-queues)  
As of February 25<sup>th</sup>, 2020:
- [X] Write a first solution. I used 2 queues in that first solution and my push
      operation would take O(1) in time complexity and my pop would take O(N) in
      time complexity. Overall the space complexity is O(N)
- [X] Submit solution. Got correct in 0 ms with 9.1 MB
- [X] Write a second solution. In that solution I used 1 queue. My push would
      then take O(N) in time complexity and my pop O(1). The overall space
      complexity is O(N)
- [X] Submit solution. Got correct in 0 ms with 8.9 MB
- [X] Problem solved

### Implement queue using stacks
The goal of this challenge is to implement the APIs of a queue data structure
using only stacks as underlying storage. In my first solution, I used 1 stack
and 1 temporary stack for push operation. Then it appeared to me that I could
improve the run time a little bit by using 2 stacks.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/implement-queue-using-stacks)  
As of February 26<sup>th</sup>, 2020:
- [X] Write a first solution. I used 1 stack and 1 temporary stack for push
      operations. The time complexity for pushing is O(N) as I destack data into
      temporary stack, add the element and restack the data onto the stack. The
      rest of the operations is O(1) in time complexity. The overall is O(N) in
      space complexity
- [X] Submit solution. Got correct in 0 ms with 8.9 MB
- [X] Write a second solution. This time I used 2 stacks. I push in 1 stack
      making the operation O(1) in time complexity. Now the pop operation
      destack the first stack into the second when this one is empty otherwise
      keep on destacking the second stack. This means that the time complexity
      of the pop operation is an amortized O(1) as we need to transfer the data
      from stack 1 to stack 2 only when stack 2 has been emptied. Other
      operations are O(1). The overall space complexity is O(N).
- [X] Submit solution. Got correct in 0 ms with 8.9 MB
- [X] Problem solved

### Min Stack
The goal is to implement a stack that would also return the minimum value in the
stack. The `getMin` operation should run in O(1) time.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/min-stack/)  
As of April 10<sup>th</sup>, 2020:
- [X] Find a first working solution. I just used an array to store the element
      and use it as a stack. I also have a variable to keeps the minimum in the
      array. It means that every time I pop an element I needed to find again
      the minimum in the remaining array. So it makes the pop operation run in
      O(N) time complexity. The space complexity is O(N).
- [X] Submit solution. Got correct in 40 ms with 14.4 MB
- [X] Implement a solution that keeps track of the minimum for each added
      element. Instead of a single value I store a tuple with the element and
      the minimum value so far. That way the pop operation now takes O(1) time
      complexity.
- [X] Submit solution. Got correct in 40 ms with 14.6 MB
- [X] Problem solved