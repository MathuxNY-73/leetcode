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
I tried to solve this problem using the C and Rust languages [Problem
link](https://leetcode.com/problems/bitwise-and-of-numbers-range/)  
As of April 23<sup>rd</sup>, 2020:
- [X] Find a first working solution. After some tries, it appeared to me that
      what we really want to compute if the common bit prefix that exists
      between the two numbers n and m. I first coded a solution that constructs
      this prefix. The time complexity is at most the size of an interger in
      bits so O(32) = O(1). The algo does not need extra space so O(1)
- [X] Submit solution. Got correct in 12 ms with 5.4 MB
- [X] There exists a simpler solution actually to find the common prefix. The
      idea based on the Brian Kerninghan's algorithm is to iteratively remove
      the rightmost set bit until n is smaller or equal to m and then do a
      bitwise AND between m and the modified n. Again the algorithm is O(1) in
      both time and space complexity.
- [X] Submit solution. Got correct in 4 ms with 2 MB
- [X] Problem solved.

### Number Complement
The goal of this challenge is to compute the complement of a given number
without complementing the leading zeroes of its int 32 representation. For
example, 5 written 101 in binary would complement to 2 written 010 in binary.  
I tried to solve this problem using the Rust language [Problem
link](https://leetcode.com/problems/number-complement/)  
As of May the 4<sup>th</sup> be with you, 2020:
- [X] Find a first working solution. The idea is to run through the bits of the
      number by shifting it to the right and set the corresponding bit of the
      result until it reaches zero. Since we visit at most 32 bits then the run
      time complexity is O(1). No extra space is needed so O(1) complexity.
- [X] Submit solution. Got correct in 0 ms with 2.1 MB
- [X] Problem solved

### Counting Bits
The goal of this challenge is, given a number num, return the array with the set
bit counts for numbers between 0 and num. The function should have runtime
complexity of O(N) and should not use builtin functions.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/counting-bits/)  
As of May 28<sup>th</sup>, 2020:
- [X] Find a first working solution. Since we are constrained on the runtime the
      logical approach is Dynamic Programming. Writing down the number of set
      bit from 0 to 16 we can see a pattern emerging. It appears that the
      numbers for [2<sup>n</sup>, 2<sup>n + 1</sup> - 1] can be computed by
      adding one to the numbers in [0, 2<sup>n</sup> - 1]. This solution indeed
      does run in O(N) and uses O(N) extra space.
- [X] Submit solution. Got correct in 32 ms with 10 MB
- [X] Other interesting approaches are:
       - By using DP[x] = DP[x/2] + (x mod 2), indeed by dividing by 2 we remove
         the LSB and so the result can be retrieved by adding 1 if x is odd
         number
       - Using the well-known x & (x - 1) trick to remove the last set bit and
         add 1 to the result.
- [X] Problem solved

### Power of Two
The goal of this challenge is to determine if a given integer is a power of two
or not. Negative numbers can be passed to the function.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/power-of-two/)  
As of June 8<sup>th</sup>, 2020:
- [X] Find a first working solution. This is a pretty easy problem for which
      simple bit manipulation will do. We just do a bitwise AND between x and
      x - 1 (if it is a power of 2 then the result is 0) and then logical AND
      with x to check x is not zero. That way the runtime complexity of the
      algorithm is O(1) and the extra space needed is O(1).
- [X] Subtmit solution. Got correct in 0 ms with 5 MB
- [X] Problem solved

### Single number II
The goal of this challenge is to find the only number that is not duplicated in
an array where all other numbers are repeated three times. There are constraints
regarding the runtime complexity of the algorithm, it should run in O(N) using
constant space.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/single-number-ii/)  
As of June 23<sup>rd</sup>, 2020:
- [X] Find a first working solution. The constraints for this problem force me
      to use bit manipulation to solve this problem. Taking this problem
      logically we can that we need to store 2 variables. One containing the
      numbers that appeared only once so far and the other containing the
      numbers that appeared twice so far. Then the formulas are pretty
      straightforward and are as follow:
        - once = ~twice & (once ^ x)
        - twice = ~once & (twice ^ x)
- [X] Submit solution. Got correct in 4 ms with 6.6 MB
- [X] Problem solved

### Single Number III
The goal of this challenge is to find the two numbers that are not duplicated in
a given array that contains duplicated numbers. The algorithm should run in O(N)
using constant space.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/single-number-iii/)  
As of June 25<sup>th</sup>, 2020:
- [X] Find a first working solution. The constraints for this problem force me
      to use bit manipulation to solve this problem. The way of doing this is to
      run first through the entire array doing a XOR of every number. Then use
      one set bit of the result which will automatically exist as otherwise it
      would mean that every number is duplicated. Use this set bit to split the
      numbers into two groups, one with numbers with that bit set and the other
      with numbers with that bit unset. The two numbers will therefore be in one
      of the group only. The algorithm therefore runs in O(2 * N) = O(N). The
      extra space needed is O(1)
- [X] Submit solution. Got correct in 8 ms with 6.7 MB
- [X] Problem solved

### Hamming Distance
The goal of this challenge is to compute the Hamming distance between two given
numbers. The Hamming distance is defined as the number of bits that differs
betweent the two numbers.  
I tried to solve this problem using the Rust language [Problem
link](https://leetcode.com/problems/hamming-distance/)  
As of July 5<sup>th</sup>, 2020:
- [X] Find a first working solution. This is a simple XOR problem where we then
      needs to compute the number of set bits. Therefore, the solution is simply
      to XOR the 2 numbers and count the number of set bits in the XOR. This can
      be done in O(32) = O(1) using constant space O(1).
- [X] Submit solution. Got correct in 0 ms with 2 MB
- [X] Problem solved.

### Subsets
The goal of this challenge is to form all the possible subsets of a given array
and return the power set in an array.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/subsets/)  
As of July 11<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to go with the approach of the
      bitmask. For a given set of N objects there are 2<sup>N</sup> possible
      subsets depending of the presence or no of elements of the set in a
      subset. This can easily be computed using the set bits of an unsigned
      integer. Thus I loop from 0 to 2<sup>N</sup> - 1 each time adding the
      elements of the set found at the indices of the set bits of the integer.
      It is easy to see that the runtime complexity of this algorithm is O(N *
      2<sup>N</sup>), O(2<sup>N</sup>) is due to the loop and the N is due to
      the fact that we iterate through all bits of the integer which is at most
      N for our problem. Note that since we are using unsigned int then N cannot
      be higher that 32 so the overall time complexity is O(2<sup>N</sup>). We
      also need O(2<sup>N</sup>) extra space.
- [X] Submit solution. Got correct in 4 ms with 6 MB
- [X] Problem solved

### Reverse bits
The goal of this challenge is to reverse the bits of a given unsigned integer
coded on 32 bits.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/reverse-bits/)  
As of July 12<sup>th</sup>, 2020:
- [X] Find a first working solution. Using a cache to store the already reversed
      bytes and the following formula to reverse a byte: byte * 0x0202020202 *
      0x010884422010 % 1023, I then just reverse every bytes of the number one
      after the other. The algorithm runs in O(1) time complexity using O(1)
      extra space.
- [X] Submit solution. Got correct in 0 ms with 5.1 MB
- [X] Problem solved.
