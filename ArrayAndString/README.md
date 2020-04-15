# Array and String Challenges
The repsitory contains the problems related to Array and Strings that I tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

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

### Shortest Subarray with sum at least K
The goal of this challenge is to code a function that finds the length of the shortest subarray which element sums up to at least a given K.  
I tried to solve this problem using the C++ language [Problem link](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)  
As of September 6<sup>th</sup>, 2019:
- [x] I wrote a smart BruteForce solution which in the worst case runs in O(n<sup>2</sup>).
- [x] Submit solution. Got Time Limit Exceeded Error, of course
- [x] Find a cleverer solution
- [x] Submit solution. Got correct in 148 ms with 21.5 MB
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

### Pancake Sort
The goal of this challenge is to sort an array of integers using only flips, meaning flipping the n<sup>th</sup> first integers of the array. The output is the sequence of those k, with k meaning that the k<sup>th</sup> first integers of the array will be flipped.  
I tried to solve this problem using the C language [Problem link](https://leetcode.com/problems/pancake-sorting/)  
As of October 9<sup>th</sup>, 2019:
- [x] I wrote a naive solution in O(N<sup>2</sup>).
- [x] Submit solution. Got right in 4 ms with 7.4 MB
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
This problem is featured of the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++, C and Python languages [Problem
link](https://leetcode.com/problems/backspace-string-compare/)  
As of April 9<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use 2 pointers to modify the
      string in place and then do the comparison to the two modified string with
      the backspacing applied. The algorithm does run in O(N) and needs only
      constant extra space O(1).
- [X] Submit solution. Got correct in 0 ms with 6.4 MB
- [X] Find a solution that does not require to modify the string. The trick is
      to start from the end of the strings.
- [X] Solves the problem again using the starting from the end of the string
      trick.
- [X] Submit solution. Got correct in 32 ms with 14 MB
- [X] Problem solved

### Move zeroes
The goal of this challenge is, given an array of integers, move all the zeroes
of the array to the end of the array. The algorithm should keep the original
ordering of the element, be done in-place and optimize the number of operation
to be done.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem with the C++ language [Problem
link](https://leetcode.com/problems/move-zeroes/)  
As of April 4<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use a 2-pointers solution. One
      moving slower everytime a zero is found and then swap the non-zero
      elements between those 2 pointers. This solution needs O(N) swaps in the
      worst case and is done in-place so it requires O(1) extra space.
- [X] Submit solution. Got correct in 8 ms with 7.2 MB
- [X] Problem solved

### Perform string shifts
The goal of this challenge is to perform a serie of string shifts on a given
string and return the result of the application of those shifts on the string.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem link]()  
As of April 14<sup>th</sup>, 2020:
- [X] Find a first working solution. I just summed up the shifts, considering
      left shifts as moving a cursor to the right, so a positive move, and
      right shifts as negative moves. I just apply the total to the string
      modulo the length of the string. It then requires one pass over the shifts
      array O(N) and one pass over the string to build the result string O(L).
      So a time complexity of O(N+L) and an extra space need of O(L) for the
      result string.
- [X] Submit solution. Got correct in 0 ms with 6.7 MB
- [X] Problem solved.

### Product Of Array Except Self
The goal of this challenge is, given an array of integers, to compute for each
element, the product of all the integers in the array without this element. That
is to say res[i] = product of all nums[j] where j != i.
The problem should be solved in O(N) without using division.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/product-of-array-except-self/)  
As of April 15<sup>th</sup>, 2020:
- [X] Find a first working solution. I used two arrays to store the prefix and
      suffix products of the nums array and then the result res[i] is basically
      the product between the prefix product before ith element and the suffix
      product after ith element. The run time complexity is O(N) and since I
      need two arrays to store the prefix and suffix products the space
      complexity is O(2*N) = O(N).
- [X] Submit solution. Got correct in 48 ms with 14.4 MB
- [ ] Follow up: find a solution that needs constant space.
- [X] Problem solved.
