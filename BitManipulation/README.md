# leetcode
The repsitory contains all the problems I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

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

### Single number
The goal of this problem is to find the only number that is not duplicated in an
array.  
This problem is featured of the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/single-number/)  
As of April 1<sup>st</sup>, 2020:
- [X] Find a first working solution. I decided to go with the bit manipulation
      trick to find the number that was not duplicated. I XOR every number in
      the array and the result of this operation gives the single number. This
      algorithm runs in O(N) in time complexity and uses O(1) extra space
- [X] Submit solution. Got correct in 8 ms with 6.8 MB
- [X] Problem solved

### Bitwise AND of numbers range
The goal of this challenge is to compute the bitwise AND of every integers
between two given numbers m and n with 0 <= m <= n <= INT_MAX.  
This problem is featured of the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/bitwise-and-of-numbers-range/)  
As of April 23<sup>rd</sup>, 2020:
- [X] Find a first working solution. After some tries, it appeared to me that
      what we really want to compute if the common bit prefix that exists
      between the two numbers n and m. I first coded a solution that constructs
      this prefix. The time complexity is at most the size of an interger in
      bits so O(32) = O(1). The algo does not need extra space so O(1)
- [X] Submit solution. Got correct in 12 ms with 5.4 MB
- [X] Problem solved.
