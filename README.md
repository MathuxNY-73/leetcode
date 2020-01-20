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
I solved this problem using the C++ language. [Problem link](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/)  
As of September 6<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit first solution. Got wrong
- [X] Looked at the help. Code a second solution.
- [X] Submit second solution. Got correct
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
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/merge-intervals/)  
As of July 22<sup>nd</sup>, 2019:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 28 ms with 12.5 MB
- [ ] Find a better solution
- [ ] Submit solution.
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
I tried to solve this problem using the C++ and rust languages [Problem link](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)  
As of October 8<sup>th</sup>, 2019:
- [x] I wrote a solution using Dynamic Programing and thus a O(N<sup>2</sup>) solution.
- [x] Submit solution. Got right in 40 ms with 9.2 MB
- [x] Find a solution based on Segment Tree. Solved in O(N*Log(N))
- [x] Submit solution. Got right in 60 ms with 38.5 MB
- [x] Find a faster working solution on sample with Rust using DP in O(N*Log(N))
- [x] Submit solution. Got right in 0 ms with 2.7 MB
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
