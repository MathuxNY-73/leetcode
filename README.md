# leetcode
The repsitory contains all the problems I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Add two numbers
The goal is to sum two numbers given as two linked lists. The digits are ordered in reverse order meaning the least significant digit comes first.  
I solved this problem using the C language. [Problem link](https://leetcode.com/problems/add-two-numbers/description/)  
As of August 26<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit first solution. Got correct
- [X] Submit second, shorter solution. Got correct
- [X] Problem solved

### Next Closest Time
The goal is, given a time passed as a string with format HH:mm, to find the next closest time formed by the digits in the given time.  
I solved this problem using the C++ language. [Problem link](https://leetcode.com/problems/next-closest-time/description/)  
As of September 5<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit first solution. Got correct
- [X] Problem solved

### Minimum Cost to Hire K Workers
The goal is to find K people to hire such that the cost of hiring is minimized. The constraints are that the salary should be propotionate to their quality among other workers and should not be less than expected minimum wage.  
I solved this problem using the C++ and Python languages. [Problem link](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/)  
As of March 10<sup>th</sup>, 2020:
- [X] Find a first working solution on the sample input
- [X] Submit first solution. Got wrong
- [X] Looked at the help. Code a second solution.
- [X] Submit second solution. Got correct
- [X] Solve the problem again in python.
- [X] Submit solution. Got correct in 476 ms with 30.9 MB
- [X] Problem solved

### Pow(x, n)
The goal is to implement a function that compute x raised to the power of n.  
I solved this problem using the C language. [Problem link](https://leetcode.com/problems/powx-n/description/)  
As of September 11<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit first solution. Got timeout on bigger testcases
- [X] Looked at the hints. Code a second solution.
- [X] Submit second solution. Got correct
- [X] Problem solved

### Add Binary
The goal is to implement a function that performs the sum of two binary numbers passed as strings.  
I solved this problem using the C++ language. [Problem link](https://leetcode.com/problems/add-binary/description/)  
As of September 16<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit solution. Got correct
- [X] Problem solved

### Median Of Two Sorted Arrays
The goal is to implement a function that compute the median of sorted set of numbers split between in two sorted arrays. The algorithm should have O(log(m+n)) complexity where n and m are the sizes of the two arrays.  
I tried to solve this problem using the C++, C and Rust languages. [Problem link](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)  
As of October 14<sup>th</sup>, 2019:
- [X] Find a first working solution on the sample input
- [X] Submit solution. Got wrong
- [X] Find a second working solution on the sample input with hints
- [X] Submit solution. Got correct
- [x] Write the solution in Rust
- [x] Submit solution. Got correct in 0 ms with 2.5 MB
- [x] Write a solution in C.
- [x] Submit solution. Got corret in 12 ms with 7.7 MB
- [X] Problem solved

### Merge K Sorted Lists
The goal is to implement a function that merges K sorted single linked lists. The complexity of the solution is a least O(N*log(k)) where N is the total number of nodes.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/merge-k-sorted-lists/description/)  
As of October 2<sup>nd</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit solution. Got correct
- [X] Implement the optimized divide and conquer solution
- [X] Submitted solution. Got correct
- [X] Problem solved

### Regular Expression Matching
The goal is to implement a function that preforms a regular expression matching with a pattern that can contain '.' and '*' characters.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/regular-expression-matching/description/)  
As of October 8<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input with hints
- [X] Submit solution. Got correct
- [X] Implement a Top-Down dynamic programming solution
- [X] Submitted solution. Got correct
- [X] Implement a Bottom-Up dynamic programming solution
- [X] Submitted solution. Got correct
- [X] Problem solved

### First Missing Positive
The goal is to implement a function that finds the first missing positive integers from a given list. As constraints the algorithm should only take O(n) time and take up only a constant extra space.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/first-missing-positive/description/)  
As of October 8<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input. Solution sorts the array thus it takes O(n*log n) time.
- [X] Submit solution. Got correct
- [X] Find a O(n) solution on the sample input. However solution does not take constant extra space.
- [X] Submit solution. Got correct
- [X] Find a O(n) and constant extra space solution on the sample input. With hints
- [X] Problem solved

### Letter Combinations of a Phone Number
The goal is to implement a function that returns all the possible combination of letters from a cellular keyboard given a phone number.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)  
As of October 8<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input.
- [X] Submit solution. Got correct
- [X] Problem solved

### Edit distance
The goal is to implement a function that returns the minimum number of edits to a given string to match it to the example. 3 edition operations are possible:
- Insert a character
- Replace a character
- Remove a character

I tried to solved this problem using the C++ language. [Problem link](https://leetcode.com/problems/edit-distance/)  
As of June 2<sup>nd</sup>, 2019:
- [X] Find a first working solutionn on the sample input. Solution is recursive thus fails on big inputs
- [X] Find a DP solution with a 2D array
- [X] Submit solution. Got correct in 4 ms with 9.6 MB
- [X] Find a DP solution with a 1D array. Is it possible ?
- [X] Submit solution. Got correct in 4ms with 8.5 MB
- [X] Problem solved


### K Inverse Pairs Arrays
Thie goal is to implement a function that returns the number of arraysof N distinct integers that contains exactly K inverse pairs. A pair of integers is inversed if a[i] > a[j] with i < j.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/k-inverse-pairs-array/)  
As of July 11<sup>th</sup>, 2019:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 168 ms with 27.2 MB
- [x] Find a better solution
- [x] Submit solution. Got correct in 112 ms with 17.8 MB
- [X] Find a faster solution.
- [X] Submit solution. Got correct in 12 ms with 17.8 MB. (Got better by using % instead of fmodl and int[] instead of vector\<int\>)
- [X] Problem solved

### Implement Trie
The goal is to implement a Trie (Prefix Tree) data structure. This is a leetcode challenge.  
I tried to solve this problem using the C++ and C languages. [Problem link](https://leetcode.com/problems/implement-trie-prefix-tree/)  
As of July 18<sup>th</sup>, 2019:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 76 ms with 45.4 MB
- [x] Find a better solution
- [x] Submit solution. Got correct in 72 ms with 40.1 MB
- [X] Problem solved

### Merge Intervals
The goal is to implement a function that will, given a list of intervals, merge all the intervals that overlap.  
I tried to solve this problem using the C++ and Python languages. [Problem link](https://leetcode.com/problems/merge-intervals/)  
As of March 29<sup>th</sup>, 2020:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 28 ms with 12.5 MB
- [X] Solve back the problem in python. I chose to separate the start and end
      time in separate arrays, sort them and run through the array to find the
      correct intervals. Thus the solution runs in O(N log N) time with O(2*N)
      extra space needed.
- [X] Submit solution. Got correct in 88 ms with 15.6 MB
- [X] Problem solved

### Insert Interval
The goal is to implement a function that takes in a list of intervals and an interval to be inserted in the list of intervals. Should the new interval overlap others then a merging of overlapping interval is necessary.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/insert-interval/)  
As of July 23<sup>rd</sup>, 2019:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 20 ms with 12.6 MB
- [x] Find a better solution
- [x] Submit solution. Got correct in 12 ms with 13.3 MB
- [x] Find another solution
- [x] Submit solution. Got correct in 16 ms with 12.4 MB
- [x] Find another solution
- [x] Submit solution. Got correct in 16 ms with 12.2 MB
- [X] Problem solved

### Fibonacci Number
The goal is to implement a function that returns the n<sup>th</sup> Fibonacci Number.  
I tried to solve this problem using the C language. [Problem link](https://leetcode.com/problems/fibonacci-number)  
As of July 30<sup>th</sup>, 2019:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 4 ms with 6.9 MB
- [x] Find a faster solution
- [x] Submit solution. Got correct in 0 ms with 6.8 MB
- [x] Find a more economical solution
- [x] Submit solution. Got correct in 0 ms with 6.6 MB
- [X] Problem solved

### Redundant connection II
The goal is to find, in rooted directed tree, the edge that is redundant. If there are several possible solutions return the one that occurs last in the given edge array.  
My approach is to:
 1. Build the tree by storing parents for each node
 2. If there exists a node with two parents then focus on it and find the edge that can be removed.
 3. If not reverse iterate through the list of edges and find the one that create a cycle  
 
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/redundant-connection-ii/)  
As of August 4<sup>th</sup>, 2019:
- [x] Find a first working solutionn on the sample input.
- [X] Submit solution. Got wrong
- [x] Find a second working solution on the sample input
- [x] Submit solution. Got correct in 12 ms with 11.9 MB
- [x] Find a faster solution. I used Union Find structure
- [x] Submit solution. Got correct in 8 ms with 10 MB
- [X] Problem solved

### Binary Tree Maximum Path Sum
The goal is to find, in a rooted binary tree, the path whose node values sum up to the highest value.  
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/binary-tree-maximum-path-sum/)  
As of August 5<sup>th</sup>, 2019:
- [x] Find a first working solutionn on the sample input.
- [x] Submit solution. Got correct in 24 ms with 25.1 MB
- [x] Find a cleaner solution
- [x] Submit solution. Got correct in 24 ms with 25.3 MB
- [x] Problem solved

### Random Pick With Blacklist
The goal is create a Uniformly distributed number generator that takes into account a blacklist of number. The solution should use as less call to rand() as possible.  
I tried to solve this problem using the C++, C, Rust and Python languages. [Problem link](https://leetcode.com/problems/random-pick-with-blacklist/)  
As of January 13<sup>th</sup>, 2020:
- [x] Find a first working solutionn on the sample input. I used a whitelist.
- [x] Submit solution. Got a Memory Limit Exceeded Error
- [x] Find a better solution
- [x] Submit solution. Got correct in 236 ms with 51.4 MB, went down to 216 ms with 52.1MB by using uniform_int_distribution.
- [x] Write a solution in C
- [x] Submit solution. Got correct in 188 ms with 47.4 MB
- [x] Write a solution in C with Heapsort
- [x] Submit solution. Got correct in 196 ms with 46.9 MB
- [x] Write a solution in Rust
- [x] Submit solution. Got correct in 40 ms with 6.6 MB
- [x] Write a solution using Whitelist in Python3. 
- [x] Submit python solution. Got correct in 384 ms with 21.9 MB
- [x] Problem solved

### Random Pick with Weights
The goal is to create a random number generator that taks into account the weight for each number from 0 to len(weights).  
I tried to solve this problem using the C language. [Problem link](https://leetcode.com/problems/random-pick-with-weight)  
As of August 9<sup>th</sup>, 2019:
- [x] Find a first working solutionn on the sample input.
- [x] Submit solution. Got correct in 120 ms with 30 MB
- [x] Rewrite the solution to go faster.
- [x] Submit solution. Got correct in 96 ms with 30.1 MB
- [x] Problem solved

### Sum Root to Leaf Numbers
The goal is to create a function that compute the sum of all the numbers generated by paths going from root to leaves of a binary tree.  
I tried to solve this problem using the C and C++ languages. [Problem link](https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/)  
As of August 12<sup>th</sup>, 2019:
- [x] Find a first working solutionn on the sample input.
- [x] Submit solution. Got correct in 4 ms with 7.7 MB
- [x] Rewrite the solution to go faster.
- [x] Submit solution. Got correct in 0 ms with 7.6 MB
- [x] Write the solution in C++
- [x] Submit the solution. Got correct in 4 ms with 12.4 MB
- [x] Problem solved

### Print in order
The goal of this challenge is to print "firstsecondthird" using print functions outputing "first", "second" and "third". Those functions are called once and only once but by different threads. Thus the goal is to implement a mechanism that insure that the prints are done in the right order.  
I triead to solve this problem using the C and C++ language [Problem link](https://leetcode.com/problems/print-in-order)  
As of August 26<sup>th</sup>, 2019:
- [x] Find a first working solutionn on the sample input.
- [x] Submit solution. Got Time Limit Exceeded error. Suspected Spinlock.
- [x] Use another mechanism to avoid spinlock.
- [x] Submit solution. Got correct in 124 ms with 7.6 MB
- [x] Rewrite solution using pthread_mutex in C
- [x] Submit solution. Got correct in 164 ms with 7.8 MB
- [x] Write a C++ solution using std Mutex.
- [x] Submit solution. Got correct in 136 ms with 9.4 MB
- [x] Problem solved

### Shortest Subarray with sum at least K
The goal of this challenge is to code a function that finds the length of the shortest subarray which element sums up to at least a given K.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)  
As of September 6<sup>th</sup>, 2019:
- [x] I wrote a smart BruteForce solution which in the worst case runs in O(n<sup>2</sup>).
- [x] Submit solution. Got Time Limit Exceeded Error, of course
- [x] Find a cleverer solution
- [x] Submit solution. Got correct in 148 ms with 21.5 MB
- [x] Problem solved


### Coin change
The goal of this challenge is to code a function that computes the minimum amount a coins necessary to cash a certain amount. If no coin combination exists then the function returns -1.  
I tried to solve this problem using the Rust language [Problem link](https://leetcode.com/problems/coin-change/)  
As of September 10 <sup>th</sup>, 2019:
- [x] I wrote a solution to the Coin Change problem but actually not the problem at hand. My solution counts the number of ways to add up the coin to that particular amount.
- [x] Find a first working solution on sample input.
- [x] Submit solution. Got correct in 4 ms with 3 MB
- [x] Problem solved

### Longest Increasing Subsequence
The goal of this challenge is to code a function that returns the length of the longest subsequence with increasing numbers. The subsequence needs not to be formed of contiguous numbers in the array.  
I tried to solve this problem using the C and C++ languages [Problem link](https://leetcode.com/problems/longest-increasing-subsequence/)  
As of January 20<sup>th</sup>, 2019:
- [x] I wrote a solution to the problem that finds the longest increasing subarray (ie: formed of contiguous elements).
- [x] Find a first working solution on sample input.
- [x] Submit solution. Got wrong.
- [x] Find a second working solution using DP on sample input.
- [x] Submit solution. Got correct in 24 ms with 7.1 MB. Complexity is O(n<sup>2</sup>)
- [x] Find a faster solution with Binary Search
- [x] Submit faster solution. Got correct in 4 ms with 7 MB.
- [x] Rewrite solution with DP in C++
- [x] Submit solution. Got correct in 4 ms with 8.3 MB
- [x] Problem solved

### Find Minimum In Rotated Sorted Arrays
The goal of this challenge is to code a function that returns the minimum element of a sorted element that has be rotated at one pivot point.  
The first approach I used is the brute force search through the array in O(N), but I think it is possible to do it in O(log N) since the array is originally sorted.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)  
As of October 9<sup>th</sup>, 2019:
- [x] I wrote a solution brute forcing the problem.
- [x] Submit solution. Got right in 4 ms with 8.9 MB
- [x] Find a first working solution on sample input using Binary Search.
- [x] Submit solution. Got right in 4 ms with 8.8 MB
- [x] Problem solved

### Find Number of LIS (Longest Increasing Subsequence)
The goal of this challenge is to code a function that finds the number of Longest Increasing Subsequence. The subsequence needs not be contiguous.  
The first approach I used is the Dynamic Programming approach to find the length of the LIS and then find the number of LIS in the array.  
I tried to solve this problem using the C++, rust and Python languages [Problem link](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)  
As of February 4<sup>th</sup>, 2020:
- [x] I wrote a solution using Dynamic Programing and thus a O(N<sup>2</sup>) solution.
- [x] Submit solution. Got right in 40 ms with 9.2 MB
- [x] Find a solution based on Segment Tree. Solved in O(N*Log(N))
- [x] Submit solution. Got right in 60 ms with 38.5 MB
- [x] Find a faster working solution on sample with Rust using DP in O(N*Log(N))
- [x] Submit solution. Got right in 0 ms with 2.7 MB
- [x] Retry the problem using the python language using DP
- [x] Submit solution. Got right in 1700 ms with 12.9 MB
- [x] Rewrite solution in python using Segment Tree.
- [x] Submit solution. Got right in 404 ms with 15.5 MB
- [x] Rewrite segment tree solutions in Rust.
- [x] Submit solution. Got right in 8 ms with 3.1 MB
- [x] Resolve the problem using DP in O(N*log(N)) in C++
- [x] Submit solution. Got right in 4 ms with 10.7 MB
- [x] Problem solved

### Pancake Sort
The goal of this challenge is to sort an array of integers using only flips, meaning flipping the n<sup>th</sup> first integers of the array. The output is the sequence of those k, with k meaning that the k<sup>th</sup> first integers of the array will be flipped.  
I tried to solve this problem using the C language [Problem link](https://leetcode.com/problems/pancake-sorting/)  
As of October 9<sup>th</sup>, 2019:
- [x] I wrote a naive solution in O(N<sup>2</sup>).
- [x] Submit solution. Got right in 4 ms with 7.4 MB
- [x] Problem solved

### Remove Nth Node From End of List
The goal of this challenge is to remove the n<sup>th</sup> starting from the end of a linked list.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)  
As of October 14<sup>th</sup>, 2019:
- [x] I wrote a recursive solution.
- [x] Submit solution. Got right in 0 ms with 8.5 MB
- [x] Find a solution that requires only one pass on the linked list
- [x] Submit solution. Got right in 4 ms with 8.4 MB
- [x] Problem solved

### Number of Islands
The goal of this challenge is to code a function that finds the number of islands in a matrix of 0s and 1s where 1 is earth and 0 is water. Is considered an island earth that is not connected vertically nor horizontally to another chunk of earth.  
I tried to solve this problem using the C++ language[Problem link](https://leetcode.com/problems/number-of-islands/submissions/)  
As of October 23<sup>rd</sup>, 2019:
- [x] Write a solution that works on sample input
- [x] Submit solution. Got wrong
- [x] Write a solution that works for edge cases
- [x] Submit solution. Got right in 76 ms with 15.4 MB
- [ ] Find a faster solution for the problem.
- [x] Problem solved

### Minimum Area Rectangle II
The goal of this challenge is to code a function that finds the minimum area that can be formed by a rectangle in a given set of points.  
I tried to solve this problem using the C++, Rust and Python 3 languages [Problem link](https://leetcode.com/problems/minimum-area-rectangle-ii/)  
As of November 2<sup>nd</sup>, 2019:
- [x] Write a solution that works on sample input. The solution I have is O(n<sup>3</sup>) in time.
- [x] Submit solution. Got correct in 256 ms with 77.7 MB
- [x] Find a faster solution. Is it possible to do it in O(n<sup>2</sup>) ? No it is not possible best case is O(N<sup>2</sup>logN)
- [x] Submit new solution. Got right in 108 ms with 14.1 MB
- [x] Write the solution in Rust.
- [x] Submit solution. Got right in 16 ms with 4.5 MB
- [x] Problem solved

### Check if it is a Straight Line
The goal of this challenge is to code a function that determines if a set of given points in the 2D space are all on a straight line.  
I tried to solve this problem using the Python3 language [Problem link](https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/)  
As of November 3<sup>rd</sup>, 2019:
- [x] Write a solution that works on sample input.
- [x] Submit solution. Got correct in 64 ms with 14.1 MB
- [x] Problem solved

### Sliding Median Window
The goal of this challenge is to code a function that takes in an array and a window size and returns the medians obtained when sliding the window over the array.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/sliding-window-median/)  
As of November 4<sup>th</sup>, 2019:
- [x] Write a solution that works on the sample input. I wrote a solution that works in O(N*log k)
- [x] Submit solution. Got correct in 64 ms with 16.1 MB
- [x] Problem solved

### Longest Continuous Increasing Subsequence
The goal of this challenge is to code a function that computes the length of the longest continuously increasing subsequence in a given array.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/longest-continuous-increasing-subsequence)  
As February 3<sup>rd</sup>, 2020:
- [x] Write a solution that works on the sample input. The solution I have is in O(n) time complexity and O(1) memory
- [x] Submit solution. Got correct in 0 ms with 9.4 MB
- [x] Problem solved

### Increasing Triplet Subsequence
The goal of this challenge is to verify that there exists a triplet of numbers in an array such that:
$arr[i] < arr[j] < arr[k] with 0 <= i < j < k <= n-1$  
The solution should run in O(n) time with O(1) memory.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/increasing-triplet-subsequence)  
As of February 5<sup>th</sup>, 2020:
- [x] Write the brute-force solution. Run in O(n<sup>3</sup>) with O(1) memory
- [x] Submit solution. Got correct in 148 ms with 9.1 MB
- [x] Find solution that can run in O(n) time
- [x] Submit solution. Got correct in 0 ms with 9 MB
- [x] Problem solved

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

### Queens that can attack the king
The goal of this challenge is to code a function that output the coordinates of
queens on a chessboard which can directly attack the king. There should not be
any obstacle on the path between the queens and the king.  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/queens-that-can-attack-the-king)  
As of February 20<sup>th</sup>, 2020:
- [X] Write a first solution using the BFS. The solution is O(1) in time
      complexity as at most 7 * 3 squares will be put into the queue. The space
      complexity is also O(1) for the same reasons
- [X] Submit solution. Got correct in 44 ms with 12.8 MB
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

### Word Squares
The goal of this challenge is to implement a function that would form word
squares (ie: a matrix of word where the k<sup>th</sup> row would read the same
word as the k<sup>th</sup> column).  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/word-squares/) 
As of February 25<sup>th</sup>, 2020:
- [X] Write a first solution. I used backtracking to perform the search but I
      brute force the retireval of good words so I ended up with a time
      complexity of O(N<sup>2</sup>K) with N the number of words and K the
      number of letters in the words
- [X] Submit solution. Got Time Limit Exceeded
- [X] Write a new solution that uses Trie in order to reduce the complexity of
      search for candidate words. This time the time complexity is O(N
      26<sup>K</sup> K).
- [X] Submit solution. Got correct in 5196 ms with 16.3 MB
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

### Longest palindromic substring
The goal of this challenge is to implement a function that finds the longest
palindromic substring contained in a given string.  
I tried to solve this problem using the Python, C++, C and Rust languages [Problem
link](https://leetcode.com/problems/longest-palindromic-substring/)  
As of March 3<sup>rd</sup>, 2020:
- [X] Write a first solution. This solution is brute force so the time
      complexity is O(N * N * N/2) = O(N<sup>3</sup>) in time complexity and
      O(1) in space complexity
- [X] Submit solution. Got Time Limit Exceeded
- [X] Write a second solution in C++. This solution runs in O(N<sup>2</sup>) in
      time complexity and O(1) in space complexity. It consists in runing
      through every character in the string and consider this character the
      center of the palindrome and then expand around this center to see if we
      can form a palindrome.
- [X] Submit solution. Got correct in 44 ms with 104.1 MB (Why so high memory
      consumption ?)
- [X] Write a solution with DP in Rust. This solution runs in O(N<sup>2</sup>)
      in time complexity and O(N<sup>2</sup>) in space complexity for we store
      the DP array.
- [X] Submit solution. Got correct in 24 ms with 3 MB
- [X] Implement Manacher's Algorithm in C. The solution runs in O(N) time
      complexity and O(N) space complexity.
- [X] Submit solution. Got correct in 4 ms with 5.6 MB
- [X] Problem solved

### Find the duplicate number
The goal of this challenge is to implement a function that can find the number
that was duplicated in a array of size N + 1 containing only numbers from 1 to
N.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/find-the-duplicate-number/)  
As of February 29<sup>th</sup>, 2020:
- [X] Write a first solution. This solution is using the Floyd's tortoise and
      hare algorithm to find the cycle in the linked list represented by the
      array of number. It runs in O(N) time complexity using O(1) space.
- [X] Submit solution. Got correct in 0 ms with 6.8 MB
- [X] Problem solved

### Diameter of Binary Tree
The goal of this challenge is to implement a function that compute diameter of a
Binary Tree which is the longest path between two nodes of the tree.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/diameter-of-binary-tree/)  
As of March 4<sup>th</sup>, 2020:
- [X] Write a first solution. This solution will simply find the deepest
      children of both the left and right subtrees of the root and, at the root,
      simply add the length of those 2 paths. The time complexity of this
      algorithm is O(N) since all the nodes of the tree are visited. It is O(N)
      extra space complexity considering the recursive call stack.
- [X] Submit solution. Got wrong answer. Should consider the fact that the
      longest path may not go through the root, Dummy !
- [X] Rewrite the solution to take into account the aforementioned problem.
- [X] Submit solution. Got correct in 8 ms with 19 MB
- [X] Problem solved

### Trapping rain water
The goal of the challenge is to find the amount of water that could be trapped
in between walls of a certain height. We are given the array of those heights
and must find the volume of water that could be trapped in between the walls.  
I tried to solve this problem using the Python, C and C++ languages [Problem
link](https://leetcode.com/problems/trapping-rain-water)  
As of March 5<sup>th</sup>, 2020:
- [X] Find a first solution. A smart brute-force that iterates through the
      number in order of height then indices and find surrounding bars. The
      algorithm runs in worst case in O(N<sup>2</sup>) time complexity using
      O(N) extra space.
- [X] Submit solution. Got right in 208 ms with 30.4 MB
- [X] Find a better solution in C. Using stacks it is possible to bring down the
      time complexity to O(N).
- [X] Submit solution. Got correct in 4 ms with 6 MB
- [X] Using two pointers in C++ goes even faster. The time complexity is O(N)
      has each cell is visited only once and the program uses only O(1) extra
      space.
- [X] Submit solution. Got correct in 4 ms with 8 MB
- [X] Problem solved

### Flip Equivalent of Binary Tree
The goal of the challenge is to check is 2 Binary Trees are equivalent up to
some flips. A flip is just a swapping a the right child with the left child of a
node.  
I tried to solve this problem using the C++ and Rust language [Problem
link](https://leetcode.com/problems/flip-equivalent-binary-trees)  
As of March 13<sup>th</sup>, 2020:
- [X] Find a first working solution. A recursive algortihm that will check every
      node a the trees in a dfs manner to see if each node is equivalent. The
      algorithm runs in O(min(N1, N2)) as every node in the smallest tree will
      be visited, it will stop before visiting the rest of the nodes of the
      largest tree should there be one. It runs with O(min(N1, N2)) extra space
      as, again, there will as many recursive calls as there are nodes in the
      smallest tree.
- [X] Submit solution. Got correct in 0 ms with 11 MB
- [X] Write a new solution using canonical representation of a binary tree. In
      this approach I am ordering children of each node before comparing them.
      The run time complexity remains O(min(N1, N2)) as the recursion go as far
      as the smallest tree. Same for the space complexity.
- [X] Submit solution. Got correct in 0 ms with 2.2 MB
- [X] Problem solved

### Minimum flips to make a OR b = c
The goal of this challenge is to determine the minimum amount of bit flips to
make a OR b equal to a given c.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c)  
As of March 7<sup>th</sup>, 2020:
- [X] Find a first solution. A simple bit manipulation and the algo runs in O(1)
      time complexity with O(1) extra space needed
- [X] Submit solution. Got correct in 0 ms with 5.1 MB
- [X] Problem solved

### Meeting Room II
The goal of this problem is to determine the minimum number of meeting rooms
needed to accomodate every meetings given by an interval with a start and an end
date.  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/meeting-rooms-ii/)  
As of March 12<sup>th</sup>, 2020:
- [X] Find a first solution. I used a priority queue to determine the number of
      meeting occuring at the same time. The algo runs in O(N log N)
      time complexity with O(N) extra space needed
- [X] Submit solution. Got correct in 68 ms with 17.2 MB
- [X] Problem solved

### Plus one
The goal of this challenge is to add one to a number represented by an array of
its digits.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/plus-one/)  
As of March 14<sup>th</sup>, 2020:
- [X] Find a first working solution. I simply run through the array storing the
      carry-on one digit to the next. The algo runs in O(N) times as it goes
      through every element in the array. Since a new array is created it needs
      O(N) extra space. This however could be overcome by changing the array in
      place.
- [X] Submit solution. Got correct in 4 ms with 8 MB
- [X] Problem solved

### Peak index in a mountain array
The goal of this challenge is to code a function that would return the index of
the max number in the array formatted as a mountain, which means that, if index
i is the peak of the mountain then A[0] < A[1] < ... < A[i-1] < A[i] > A[i+1] >
... > A[n-2] > A[n-1]  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/peak-index-in-a-mountain-array/)  
As of March 14<sup>th</sup>, 2020:
- [X] Find a first working solution. I brute-forced the problem by simply
      passing over each element and finding the peak. It is O(N) time complexity
      and O(1) extra space.
- [X] Submit solution. Got correct in 88 ms with 14.3 MB
- [X] Find a second more subtle solution using Binary Search. Using binary
      search the algorithm runs in O(log N) and needs O(1) extra space
- [X] Submit solution. Got correct in 72 ms with 14.2 MB
- [X] Problem solved

### Merge sorted arrays
The goal of this challenge is to code a function that merges two sorted arrays
into one of the array.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/merge-sorted-array/)  
As of March 16<sup>th</sup>, 2020:
- [X] Find a first working solution. I just made a copy of the first array and
      use two pointers, one on each array, adding numbers one after the other
      depending on their comparison. This solution runs in O(N+M) time using
      O(M) extra space.
- [X] Submit solution. Got correct in 0 ms with 5.8 MB
- [X] Write a second solution that would go throught the arrays backward so that
      I do not need extra space to store the first array. No the algorithm still
      runs in O(N+M) time complexity but using only O(1) extra space.
- [X] Submit solution. Got correct in 4 ms with 5.9 MB. Why ?
- [X] Problem solved

### Find First and Last Position of Element in Sorted Array
The goal of this challenge is to code a function that can find the index of the
first target element and the index of the last in a sorted array. The target
element is an integer that can be duplicated many times or not exist at all in
the array. The goal is to find an algorithm that can perform the search in O(log
N) time.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)  
As of March 17<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to go with ternary search making
      the search for one of the element run in O(log N) time but then starting
      from the found index I expand outward to find the start and end index of
      the serie of duplicated numbers. Of course, it brings down the complexity
      to O(N). The algo needs O(1) extra space.
- [X] Submit solution. Got correct in 4 ms with 7.2 MB
- [X] Find solution to really run in O(log N) time. This time I used binary
      search to find the first and last index of the element.
- [X] Submit solution. Got correct in 4 ms with 7.2 MB
- [X] Problem solved

### Backspace string compare
The of this challenge is to code a function that compares 2 strings with a
special character '#' is used to represent a backspace. The goal is to implement
this comparison in O(N) time and using O(1) extra space.  
I tried to solve this problem using the C++ and C languages [Problem
link](https://leetcode.com/problems/backspace-string-compare/)  
As of March 23<sup>rd</sup>, 2020:
- [X] Find a first working solution. I decided to use 2 pointers to modify the
      string in place and then do the comparison to the two modified string with
      the backspacing applied. The algorithm does run in O(N) and needs only
      constant extra space O(1).
- [X] Submit solution. Got correct in 0 ms with 6.4 MB
- [X] Find a solution that does not require to modify the string. The trick is
      to start from the end of the string with 2 pointers.
- [X] Problem solved

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
