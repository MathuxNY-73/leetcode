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
I tried to solve this problem using the C and Python languages [Problem
link](https://leetcode.com/problems/find-the-duplicate-number/)  
As of August 6<sup>th</sup>, 2020:
- [X] Write a first solution. This solution is using the Floyd's tortoise and
      hare algorithm to find the cycle in the linked list represented by the
      array of number. It runs in O(N) time complexity using O(1) space.
- [X] Submit solution. Got correct in 0 ms with 6.8 MB
- [X] Re implement the solution using the python language. I reused the tortoise
      and hare solution for this problem making it run in O(N) with O(1) extra
      space needed.
- [X] Submit solution. Got correct in 48 ms with 15.3 MB
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
- [X] Follow up: find a solution that needs constant space. Since allocating the
      answer array is not considered for space complexity analysis, then the
      modification is fairly straightforward as we just need to store the prefix
      product in the answer array and keep a variable to compute the suffix
      product whilst going down the answer array to modify it. The run time
      complexity is still O(N) but now, as we do not need any intermediate
      arrays the space complexity is O(1).
- [X] Submit solution. Got correct in 40 ms with 13.5 MB
- [X] Problem solved.

### Valid Parenthesis String
The goal of this challenge is to determine if a given string containing only the
characters '(', ')' and '*', where '*' can either be '(', ')' or the empty
string, can be made valid (ie: every '(' has a corresponding ')' further down in
the string)  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/valid-parenthesis-string/)  
As of April 17<sup>th</sup>, 2020:
- [X] Find a first working solution. I used two stacks holding the indices of
      opening parenthesis and stars and went through the string pop the stacks
      at every closing parenthesis. If at the end there are still open
      parenthesis, I check if they can be matched to a star positionned after
      them in the string. The time complexity of this solution is O(N) since I
      run once through the string. It uses O(2*N) = O(N) extra space.
- [X] Submit solution. Got correct in 20 ms with 14 MB
- [X] Implemented a new solution based this time on the interval of the values
      that the balance between opening and closing parenthesis can take. At each
      character we will compute the bounds of the interval. This solution runs
      in O(N) and needs O(1) extra space.
- [X] Submit solution. Got correct in 28 ms with 13.8 MB
- [X] Problem solved

### Search in rotated sorted array
The goal of this challenge is to search for a given element in a rotated sorted
array. It means that the array was sorted and then rotated at a given index. The
algorithm should run in O(log N).  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/search-in-rotated-sorted-array/)  
As of April 19<sup>th</sup>, 2020:
- [X] Find a first working solution. The run time complexity constraint forces
      me to use binary search on the array. In the algorithm I then consider the
      cases where the array rotated either at the right or left of the pivot
      index. The run time complexity is therefore O(log N) and the space
      complexity is O(1).
- [X] Submit solution. Got correct in 0 ms with 6.5 MB
- [X] Problem solve

### Leftmost column with at least a one
The goal of this challenge is to code a function that uses the given API of a
binary matrix to find the leftmost column that contains at least a one. It is an
interactive problem and the function should less than 1000 requests with
matrices that can be as big as 100x100.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem link]()  
As of April 21<sup>st</sup>, 2020:
- [X] Find a first working solution. My idea was to do binary search on each row
      and return the minimum column index found when running over all the
      matrix' rows. On each row the binary search takes O(log M) time thus the
      overall time complexity is O(N log M). There is constant extra space
      needed so O(1)
- [X] Submit solution. Got correct in 8 ms with 8.3 MB
- [X] Previous solution can be optimized. When a best index column is found then
      there is no need to consider rows where element at `best column index - 1`
      is zero. Doing that we will only binary search columns that can be better.
      In the worst case, we will only visit O(N+M) elements in the matrix.
      Indeed at each row, in the worst case we would skip 1 more element on the
      right of the matrix.
- [X] Submit solution. Got correct in 4 ms with 8.3 MB
- [X] Problem solved

### First Bad Version
The goal of this challenge is to code a function that returns the first bad
version of a software by using a simple `isBadVersion` API.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/first-bad-version/)  
As of May 1<sup>st</sup>, 2020:
- [X] Find a first working solution. This is a simple binary search problem. The
      runtime of my algorithm is therefore O(log N). No extra space is needed,
      so O(1) in space complexity.
- [X] Submit solution. Got correct in 0 ms with 5.1 MB
- [X] Problem solved

### Ransom Note
The goal of this challenge is to determine if it is possible to build a ransom
note from a given set of magazine's lowercase letters.  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/ransom-note/)  
As of May 3<sup>rd</sup>, 2020:
- [X] Find a first working solution. I simply used a hash map to count the
      frequencies of letters in the magazine's letters and then ran through the
      letters in the ransom note decreasing the number of avaiblable letters
      everytime. Whenever the letter count would become negative then the ransom
      note cannot be constructed with those magazine's letters. The function
      runs through the magazines letters as well as the ransom note letters,
      thus the time complexity of the algorithm is O(N + M). I need a hash map
      of size 26 to store the frequencies of each letters thus the space
      complexity is O(26) = O(1).
- [X] Submit solution. Got correct in 48 ms with 13.8 MB
- [X] Problem solved

### First Unique Character in a string
The goal of this challenge is to retrieve the first non-repeating character in a
given string.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/first-unique-character-in-a-string/)  
As of May 5<sup>th</sup>, 2020:
- [X] Find a first working solution. I used a hash table approach to store the
      frequencies of each character in the string. In a second pass over the
      string I then return the index of the first character which frequency is
      equal to 1. I need to make to passes over the string thus the run time
      complexity of this algorithm is O(2 * N) = O(N). I need to store the
      frequencies of the character in the string which are all lowercase thus I
      need O(26) = O(1) extra space.
- [X] Submit solution. Got correct in 36 ms with 10.7 MB
- [X] Problem solved

### Majority Element
The goal of this challenge is to retrieve, in a given array, the element that
appears more than floor(n/2). This element is guaranteed to exist.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/majority-element/)  
As of May 6<sup>th</sup>, 2020:
- [X] Find a first working solution. I first used a hash table approach to count
      the number of occurences of each element in the array. After, I would run
      ove the hash table to find the element whose number occurences is higher
      than floor(n/2). Since I am running once over the array and once over the
      hash table then the space complexity is O(2 * N) = O(N). I need a hash
      table to store the number of occurences thus the space complexity is O(N)
      as well.
- [X] Submit solution. Got correct in 40 ms with 21.1 MB
- [X] Optimize the solution using Boyer-Moore algorithm. This time the space
      needed is constant O(1) but the runtime complexity remains at O(N).
- [X] Submit solution. Got correct in 32 ms with 19.8 MB
- [X] Problem solved

### Flood fill
The goal of this challenge is to apply a transformation to an image by flood
filling with a new color, pixels of the same original color starting from a
point specified by coordinates.  
I tried to solve this problem using the Rust language [Problem
link](https://leetcode.com/problems/flood-fill/)  
As of May 12<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use a BFS to find all
      neighboring pixels that needs to be changed around the start position. At
      worst, the whole image needs to be changed and in that case we will go
      through N x M pixels. Thus the runtime complexity of the algorithm is
      O(N * M). The space needed for storing pixels to be visited can be bounded
      by O(max(N,M)) ?
- [X] Submit solution. Got correct in 0 ms with 2.2 MB
- [X] Problem solved

### Single element in a sorted array
The goal of this challenge is to find the only non-duplicated element in a
sorted array where every elements are duplicated except one. The algorithm
should run in O(log N) using O(1) space.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/single-element-in-a-sorted-array/)  
As of May 12<sup>th</sup>, 2020:
- [X] Find a first working solution. Since we have a constraint on the running
      time of the algorithm at O(log N) we cannot use the usual XOR trick. We
      should use binary search instead. That is what I did changing checks
      whether the mid index is even or odd. The algorithm then runs in O(log N)
      using O(1) space.
- [X] Submit solution. Got correct in 8 ms with 6.5 MB
- [X] We can further optimize the solution by just checking the even indices
      thus simplifying the code. The runtime complexity is still O(log N) using
      O(1) extra space
- [X] Submit solution. Got correct in 8 ms with 6.1 MB
- [X] Problem solved

### Permutation in String
The goal of this challenge is to check if a given string contains or not a
permutation of another given string.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/permutation-in-string/)  
As of May 19<sup>th</sup>, 2020:
- [X] Find a first working solution. I used an array to keep the number of
      occurences of each letter in the first string and then ran through the
      second string checking if each character is a start of a permutation of
      the first string. This takes actually a lot of time as the time complexity
      is O(N * M). However, the space complexity is kept at O(1).
- [X] Submit solution. Got correct in 1712 ms with 7.1 MB. It is very long.
- [X] Find a faster solution. Using a sliding window, it possible to bring down
      the runtime complexity down to O(26 * M) and the extra space needed to O(1).
- [X] Submit solution. Got correct in 12 ms with 7.2 MB
- [X] Problem solved

### Interval list intersections
The goal of this challenge is to build the intersection between two list of
intervals given in argument.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/interval-list-intersections/)  
As of May 25<sup>th</sup>, 2020:
- [X] Find a first working solution. I used two pointers, one on each list, to
      run through the two lists and merge the interval together taking the max
      of the starts and the min of the ends of the interval. If the formed pair
      of integer is a valid interval then we add the interval to the result.
      Since I run through all the intervals then the runtime complexity is
      O(N+M) and the extra space is O(N+M) in the worst case as well for the new
      list of intervals.
- [X] Submit solution. Got correct in 48 ms with 19.4 MB
- [X] Problem solved

### Reverse string
The goal of this challenge is to reverse a given string in place. For example,
the string "hello" should become "olleh".  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/reverse-string/)  
As of June 4<sup>th</sup>, 2020:
- [X] Find a first working solution. The algorithm is very simple as we just
      need to run through the string with two pointers, whenever the pointers
      meet then the funtion stops. The algorithm runs actually on only half of
      the word, thus the runtime complexity of the function is O(N) and since
      the reverse in done in place there is no extra space needed so the space
      complexity of this algorithm is O(1).
- [X] Submit solution. Got correct in 48 ms with 12.2 MB
- [X] Problem solved

### Is Subsequnce
The goal of this challenge is to determine if, given two strings, one is a
subsequence of the other. We thus need to check whether one string's characters
are found in the same order, but not necessarily contiguously, in the second
string.  
I tried to solve this challenge using the C language [Problem
link](https://leetcode.com/problems/is-subsequence/)  
As of June 9<sup>th</sup>, 2020:
- [X] Find a first working solution. I just used one pointer on each string
      running through the longest. When the characters of the 2 strings would
      match I would increment the pointer on the other string. If at the end of
      the loop the pointer points to NULL char then it is a subsequence. The
      algorithm therefore runs in O(max(N,M)) using constant extra space so
      O(1).
- [X] Submit solution. Got correct in 4 ms with 5.2 MB
- [X] Problem solved

### Search Insert Position
The goal of this challenge is to find an element in a given sorted array or, if the
element is not in the list, find the position where the element would be
inserted. The element of the given list are supposed to be distinct.  
I tried to solve this challenge using the Python language [Problem
link](https://leetcode.com/problems/search-insert-position/)  
As of June 10<sup>th</sup>, 2020:
- [X] Find a first working solution. The naive solution is very straightforward.
      Since the array is sorted the use of binary search is obvious. However,
      to make the problem a little funnier to implement, I used ternary search
      instead. Thus the runtime complexity of my solution is O(log N) and no
      extra space is needed, thus O(1).
- [X] Submit solution. Got correct in 48 ms with 14.5 MB
- [X] Problem solved

### Sort Colors
The goal of this challenge is to order an array of colors such that every color
is gathered together. The array can contain three colors red, white and blue
which are represented by integers 0, 1 and 2. The sorting should be done
in-place and one pass over the array.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/sort-colors/)  
As of June 12<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use two pointers, one pointing
      at the right most index of the red and the second pointing at the
      leftmost index of blue. That way when I run over the array depending if
      the color is red or blue I can swap the color accordingly. Another
      solution, that I tried, is to hold onto the pointers that point to the
      rightmost red element and the one that points to the rightmost white. In
      that last case in order to swap red elements, one first need to swap white
      element and then red elements. In both cases the algorithm complexity is
      O(N) as we go through the elements only once and the extra space needed is
      O(1).
- [X] Submit solution. Got correct in 0 ms with 8.3 MB
- [X] Problem solved.

### Island Perimeter
The goal of this challenge is to compute the perimeter of an island represent by
adjacent ones in a matrix of 0s.  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/island-perimeter/)  
As of July 7<sup>th</sup>, 2020:
- [X] Find a first working solution. The trick is simply to go through every
      cell of the matrix and add 4 for every land we find, then if looking to
      the right and to the top, if we find land we need to substract the falsely
      doubly counted edge. The runtime complexity of this algorithm is O(N * M)
      and no extra space is needed for this problem so O(1)
- [X] Submit solution. Got correct in 508 ms with 14.1 MB
- [X] Problem solved

### 3 Sum
The goal of this challenge is to find in a given array all the triplets of
numbers that sum up to 0. That is to say all the triplets of number a, b and c
such that a + b + c = 0. The answer should not contain any duplicated triplets.  
I tried to solve this problem using the Rust language [Problem
link](https://leetcode.com/problems/3sum/)  
As of July 8<sup>th</sup>, 2020:
- [X] Find a first working solution. I used a two-pointers approach to solve
      this problem. This approach requires a sorting of the array which takes
      O(N log N) time, then I run through the array fixing the first number of
      the triplet a. If this a is greater than 0 then we do not need to go
      further as any subsequent number in the sorted array is also positive and
      thus cannot sum up to zero. If it negative then we use 2 pointers to go
      through the rest of the array to find triplets. This overall process takes
      at most O(N<sup>2</sup>) time. No extra-space is required in this
      approach, so O(1) space complexity.
- [X] Submit solution. Got correct in 40 ms with 3.3 MB
- [X] Problem solved.

### Two Sum
The goal of this challenge is to find a pair of numbers in a given array that
sum up to a given target integer. That is to say we want to find (i, j) so that
i != j and A[i] + A[j] = target.  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/two-sum/)  
As of July 9<sup>th</sup>, 2020:
- [X] Find a first working solution. I used a hashtable to store the numbers and
      their index. If during the loop over the array we are able to find the
      complement of the current number (ie: target - current value) in the
      hashtable then we find a pair that satisfies the constraint of the
      problem. The runtime complexity of this approach i O(N) as I need to go only once over the array. I need O(N) extra space to store the numbers and
      their index.
- [X] Submit solution. Got correct in 44 ms with 15.5 MB
- [X] Problem solved.

### Reverse words in a string
The goal of this challenge is to reverse the order of the words in a given
string. Doing so we should also erase any trailing spaces and spaces that were
duplicated. C programs should perform the operation using constant space.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/reverse-words-in-a-string/)  
As of July 15<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to approach the problem in 2
      steps. First I would reverse the all string and then reverse again the
      order of the letters in each word. During the second step I would shift
      all unecessary spaces to the end of the string and then I would trim the
      trailing spaces. The algo runs in O(N) using no extra space so O(1) space
      complexity.
- [X] Submit solution. Got correct in 0 ms with 5.7 MB
- [X] Problem solved.

### Top K Frequent Element
The goal of this challenge is to find the top K most frequent numbers in a given
list that can therefore contain duplicates. The solution must be at most O(N
log N) complexity.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/top-k-frequent-elements/)  
As of July 17<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use hash map and then a queue
      to solve this problem. First I go over every number in the list adding the
      frequency of the number in a hash map and adding the number to a pool of
      unique numbers. Then I build a heap with this pool sorting the heap by
      numbers frequency. Then I pop the first K numbers to have the answer. This
      algorithm runs in O(N log N) as it is bounded by the head making part and
      it uses O(N) extra space.
- [X] Submit solution. Got correct in 36 ms with 13.9 MB
- [ ] Find another solution (eg: bucket, quickselect)
- [X] Problem solved

### Valid Palindrome
The goal of this challenge is to determine if a given sentence is palindromic,
taking into account the alphanumeric characters of the sentence.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/valid-palindrome/)  
As of August 3<sup>rd</sup>, 2020:
- [X] Find a first working solution. The problem is a pretty simple one to
      solve. Just use 2 pointers, one starting at the beginning, the other
      starting at the end and move them torward the middle, for each skipping
      non-alphanumeric characters. The algorithm needs to run over all
      characters of the string so the runtime complexity is O(N) and the only
      space needed is for the two pointers, so the space complexity is O(1).
- [X] Submit solution. Got correct in 4 ms with 5.9 MB
- [X] Problem solved
