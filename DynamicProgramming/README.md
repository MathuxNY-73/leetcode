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

I tried to solved this problem using the C++ and Rust languages. [Problem
link](https://leetcode.com/problems/edit-distance/)  
As of May 31<sup>st</sup>, 2020:
- [X] Find a first working solutionn on the sample input. Solution is recursive thus fails on big inputs
- [X] Find a DP solution with a 2D array
- [X] Submit solution. Got correct in 4 ms with 9.6 MB
- [X] Find a DP solution with a 1D array. Is it possible ?
- [X] Submit solution. Got correct in 4ms with 8.5 MB
- [X] Resolve the problem in the course of the may leetcoding challenge. I was
      able to find the correct DP solution. As we need to go through every
      character in both strings we need a 2-D DP array. The runtime complexity
      is therefore O(N * M). Noting that we can store the diagonal element for
      each step we can optimize the space needed to O(N) or O(M) depending on
      which word length is used.
- [X] Submit solution. Got correct in 0 ms with 2.1 MB
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

### Minimum Path Sum
The goal of this challenge is to compute the sum of the minimum path in a given
matrix, to go from the top left corner down to the bottom right corner.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/minimum-path-sum/)  
As of April 18<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use dynamic programming to
      solve this problem by modifying the grid in place. I run through the
      matrix taking the minimum of the two paths leading to the current cell.
      Since the algorithm runs through every elements of the matrix the time
      complexity is O(N*M). I am modifying the grid in place so the algo needs
      constant extra space (1)
- [X] Submit solution. Got correct in 4 ms with 8.3 MB
- [X] Problem solved

### Longest Common Subsequence
The goal of this challenge is to compute the length of the longest common
subsequence between two strings.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/longest-common-subsequence/)  
As of April 26<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to take the dynamic programming
      approach to compute this length. That way the run time complexity of the
      algorithm is O(M*N) and since I use a 2D array for keeping the result of
      subproblems then the space complexity of the solution is O(M*N).
- [X] Submit solution. Got correct in 12 ms with 9.2 MB
- [X] Problem solved

### Maximal Square
The goal of this challenge is to compute the area of the largest square formed
by 1 in a matrix of 0s and 1s.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/maximal-square/)  
As of April 27<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to go for the dynamic programming
      approach, going through all elements in the matrix storing at dp\[i\]\[j\]
      the largest square that can be formed at index i and j. I also update a
      variable to keep the max area found so far. Since the algorithm is going
      through each element in the matrix then the complexity is O(N * M). I need
      also a N * M matrix to keep the results of the subproblems so O(N * M)
      extra space is needed.
- [X] Submit solution. Got correct in 8 ms with 8.8 MB
- [X] Problem solved

### Maximum sum Circular Subarray
The goal of this challenge is to compute the maximum sum feasible in a circular
array. A circular array is an array that starts over once the last index is
reached.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/maximum-sum-circular-subarray/)  
As of May 18<sup>th</sup>, 2020:
- [X] Find a first working solution. I used the Kadane's algorithm in order to
      find the maximum sum in the array A[j], A[j+1],...,A[(j + A.size() - 1 ) %
      A.size()] where j runs through 0,1,...,A.size(). I therefore have 2 nested
      loops thus the runtime complexity of this algorithm is O(N<sup>2</sup>).
      The space complexity is O(1).
- [X] Submit solution. Got Time Limit Exceeded
- [X] Find a better solution. Instead of run N times the Kadane's algorithm,
      this time, I will divide the problem into to cases:
       - The maximum sum in one interval
       - The maximum sum in two intervals
      The second problem arises from the fact that in a circular array,
      intervals of the form A[i], A[i+1], ..., A[A.size() -1], A[0], ..., A[j]
      with j < i and abs(i - j) <= N, can actually be viewed as being separated
      by the interval A[j+1], ..., A[i-1] in the array B = A+A. So in that
      second case we want to find the minimum sum subarray which separates the
      two ends of the maximum sum subarray in the circular array. There is one
      small issue though. Since we always want at least one element in the
      answer then we must circumvent the case where the Kadane's minimum sum
      algo would return the full array. So we actually will do to run of the
      algo, one removing the first element and one removing the last.
- [X] Submit solution. Got correct in 96 ms with 40.1 MB
- [X] Problem solved

### Find all anagrams in a string
The goal of this challenge is to find all starting indices of anagrams of a
certain pattern in a given string.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/find-all-anagrams-in-a-string/)  
As of May 17<sup>th</sup>, 2020:
- [X] Find a first working solution. I basically used the idea of sliding window
      over the string counting the frequencies of characters in that string. At
      first I go over the pattern and decrement the frequency of every letter
      contained in the pattern then increment the frequency of letter of the
      start of the string from 0 to pattern.size(). Then in a loop I move this
      window decrementing when a character leaves the window, incrementing when
      it enters. Whenever all frequencies are zeroes then we found an anagram.
      The runtime complexity of the algorithm is O(26 * N) where N is the size
      of the string. The space complexity is O(26) = O(1).
- [X] Submit solution. Got correct in 12 ms with 8.4 MB
- [X] Problem solved.

### Uncrossed lines
The goal of this challenge is to find the maximum number of lines that can be
draw from one set to another without lines crossing. A line can be drawn between
two equal numbers only.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/uncrossed-lines/)  
As of May 26<sup>th</sup>, 2020:
- [X] Find a first working solution. This problem is actually equivalent to the
      longest common subsequence problem. The goal is then to find the longest
      common subsequence between the two given arrays. This can be done in O(N *
      M) with dynamic programming using O(N * M) space.
- [X] Submit solution. Got correct in 20 ms with 13.1 MB
- [ ] Optimize space to use only O(max(N, M))
- [X] Problem solved

### Coin Change 2
The goal of this challenge does not need to be introduced anymore as it is the
regular coin change problem. We are given a certain amount to match with a given
set of coins. Coins are in infinite number.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/coin-change-2/)  
As of June 7<sup>th</sup>, 2020:
- [X] Find first working solution. Since this is a well-known dynamic
      programming problem the solution came very easily with dynamic
      programming. The runtime complexity of this algorithm is O(N * M) where N
      is the given amount to match and M the number of coins. The extra space
      needed is O(N).
- [X] Submit solution.Got correct in 4 ms with 5.6 MB
- [X] Problem solved

### Largest Divisible Subset
The goal of this challenge is to form the largest possible subset of numbers
from a given array of numbers, such that for any pair of integers s[i] % s[j] ==
0 or s[j] % s[i] == 0.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/largest-divisible-subset/)  
As of June 13<sup>th</sup>, 2020:
- [X] Find a first working solution. I went for a DP solution, I first sort the
      numbers in ascending order and then go through the list. For each integer
      I check if any previous integer divides it. If so, I increse put the size
      of the current subset + 1 to the corresponding dp cell. At the end it
      possible to reconstruct the resulting subset. The solution needs to sort
      the numbers which is done in O(N log N), then there are two nested loops
      than run over the array, which takes O( N<sup>2</sup> ) which is the time
      complexity bound of this algo. The space required is O(N).
- [X] Submit solution. Got correct in 40 ms with 8.7 MB
- [X] Problem solved
