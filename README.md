# leetcode
The repository contains all the problems I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

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
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)  
As of October 1<sup>st</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit solution. Got wrong
- [X] Find a second working solution on the sample input with hints
- [X] Submit solution. Got correct
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
I tried to solve this problem using the C++ language. [Problem link](https://leetcode.com/problems/random-pick-with-blacklist/)  
As of August 6<sup>th</sup>, 2019:
- [x] Find a first working solutionn on the sample input. I used a whitelist.
- [x] Submit solution. Got a Memory Limit Exceeded Error
- [x] Find a better solution
- [x] Submit solution. Got correct in 236 ms with 51.4 MB, went down to 216 ms with 52.1MB by using uniform_int_distribution.
- [x] Problem solved
