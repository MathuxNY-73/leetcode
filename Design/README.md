# Design Challenged
The repsitory contains problems related to Design I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Implement Trie
The goal is to implement a Trie (Prefix Tree) data structure. This is a leetcode challenge.  
I tried to solve this problem using the C++, C and Rust languages. [Problem
link](https://leetcode.com/problems/implement-trie-prefix-tree/)  
As of May 25<sup>th</sup>, 2020:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 76 ms with 45.4 MB
- [x] Find a better solution
- [x] Submit solution. Got correct in 72 ms with 40.1 MB
- [X] Rewrite a solution in rust for the May 2020 leetcoding challenge. All the
      operation of my Trie requires O(N) where N is the size of the word runtime
      complexity as well as O(N) in space complexity for the recursive call
      stack. This could be improved by using a iterative approach. The Trie
      itself would take up to O(26 * size_of_vocabulary).
- [X] Submit solution. Got correct in 36 ms with 15.5 MB
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

### LRU Cache
The goal of this challenge is to implement an LRUCache cache. The LRUCache will
be specified a capacity and whenever the capacity of the cache is reach then it
will discard the least recently used element to make space for the new one.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/lru-cache/)  
As of April 24<sup>th</sup>, 2020:
- [X] Find a first working solution. I had the idea of using a doubly linked
      list and a hash map to store the nodes of the linked list. Using a double
      linked list allows me to move cache elements around in O(1). Thus using
      this solution, retrieving a node and putting it to the front of the list
      as most recently used element is O(1) in time complexity. Putting an
      element in the cache is also O(1). In one case no other operation is
      needed than to create a new node and adding it the hash map so O(1), in
      the other case we need to discard the LRU element. Since I have a pointer
      on the tail of the linked list then I just need to update the pointer,
      discard the previous tail and add a new element to the front of the list.
      All of those operation can be done in O(1) with the doubly-linked list.
      Since I need to store the linked list and the hash map the space
      complexity is O(2 * capacity) = O(capacity).
- [X] Submit solution. Got correct in 132 ms with 35.2 MB
- [ ] It was not necessary to re implement the doubly linked list myself, I
      could have used the std:list of C++. In python there exist
      OrderedDictionary which suit this problem. Re implement the solution using
      those standard containers
- [X] Problem solved.

### First Unique Number
The goal of this challenge is to implement a queue that can return the first non
duplicated number in the queue.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem link]()  
As of April 29<sup>th</sup>, 2020:
- [X] Find a first working solution. I used hints, the idea here is to use a
      combination of hash map and doubly-linked list to perform the
      `showFirstUnique` and `add` operations in O(1) time. The idea is that, the
      numbers are added to the list one by one and the hash maps stores a
      pointer to the added nodes. Whenever a number which already added before
      is added a second time then, the number is removed from the list. Thus the
      space complexity of this approach is O(2 * N) = O(N). The time complexity
      of building the FirstUnique queue is O(M) where M is the size of the
      original array passed to the ctor.
- [X] Submit solution. Got correct in 504 ms with 136 MB
- [X] Again instead of recoding the doubly-linked list myself it is possible to
      use the std::list container
- [X] Problem solved

### Online Stock Spanner
The goal of this challenge is to implement a class that can compute the span of
stock prices, that is to say the number of consecutive days during which the
stock was lower or equal to the new price.  
I tried to solve this problem using the Rust language [Problem
link](https://leetcode.com/problems/online-stock-span/)  
As of May 20<sup>th</sup>, 2020:
- [X] Find a first working solution. I used a stack to keep track of the span
      for the prices. Whenever I insert a new price I destack all smaller
      numbers and add their span to the new price's span. The push operation
      offers, therefore, an amortized run time complexity of O(1). The space
      complexity is O(Q) with Q the number of query.
- [X] Submit solution. Got correct in 44 ms with 5.3 MB
- [X] Problem solved

### Insert Delete GetRandom O(1)
The goal of this challenge is to implement a structure that can pick random
number from a mutable set. One can thus add, delete and pick at uniform random
a number in this structure in average constant time.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/insert-delete-getrandom-o1/)  
As of June 12<sup>th</sup>, 2020:
- [X] Find a first working solution. The runtime constraints is guiding me
      toward the use of HashMap to keep the index of a number in the underlying
      vector structure that will be used to a number at random. When a number is
      added then it is appended to the end of the array and the index of
      insertion is stored in the hash map where the value is the key. When a
      value is deleted then the last element in the array is then placed at the
      index of the removed element. A random pick can then simply pick an index
      between 1 and the count of elements. All those operations can be done in
      O(1) time in average. In the worst, from time to time when the array and
      the hash map needs to grow in the memory then the runtime of insertion
      becomes O(N). The space complexity of the algorithm is O(N) since we need
      to store the numbers contained in the structure.
- [X] Submit solution. Got correct in 72 ms with 22.9 MB
- [X] Problem solved.

### Insert Delete GetRandom O(1) - With Duplicates
The goal of this challenge is to implement a structure that can pick random
number from a mutable set that can contain duplicates (ie: most added number
will have higher chances of getting picked). All those operation should be
performed in O(1) time complexity on average.  
I tried to solve this problem using the Rust language [Problem
link](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)  
As June 27<sup>th</sup>, 2020:
- [X] Find a first working solution. The solution is very close to the one used
      in the Insert Delete GetRandom O(1) problem except that in order to track
      the indices in the distribution vector, I use a hashset. Hashset is
      necessary here in order to be able to perform those operations in O(1)
      time. As per constraints the runtime complexity of all operations is O(1)
      and the space needed for the structure in O(2 * N) = O(N)
- [X] Submit solution. Got correct in 12 ms with 6.5 MB
- [X] Problem solved

### Add and Search Word
The goal of this challenge is to build a data structure where one can add words
and then search if a pattern has already been added in the past. This pattern
can contain '.' character which can represent any letter.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/add-and-search-word-data-structure-design/)  
As of August 5<sup>th</sup>, 2020:
- [X] Find a first working solution. It is actually very simple as it is a Trie
      data structure. In the add operation, we add the word to the Trie data
      structure and then in the search we do a DFS and whenever we encounter a
      '.' character then we loop over all the letters of the TrieNode. The
      runtime complexity of the add method is O(W) and the search method is O(W)
      when it does not contain '.' character, in the worst case the runtime
      complexity is O(M * W) where M is the number of '.' character. The space
      needed is O(W) for the add method and O(W) for the search method.
- [X] Submit solution. Got correct in 196 ms with 43.4 MB
- [X] Problem solved.
