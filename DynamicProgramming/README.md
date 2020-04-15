# Dynamic Programming Challenges
The repsitory contains the problems related to Dynamic Programming I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

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

### Maximum Subarray
The goal of this challenge is to compute the maximum sum that can be formed with
a subarray of contiguous intergers, which can be either positive or negative.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem with the C language [Problem
link](https://leetcode.com/problems/maximum-subarray/)  
As of April 4<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use a form of a dynamic
      programming and run through all elements in the array. Thus the time
      complexity of O(n) and extra space need of O(1)
- [X] Submit solution. Got correct in 4 ms with 5.9 MB
- [X] Implement the divide and conquer solution. Now the solution is slower than
      the Kadane's algorithm since it runs in O(N log N) time complexity and we
      need O(log N) space for the recursive call stack.
- [X] Submit solution. Got correct in 8 ms with 6.3 MB
- [X] Problem solved