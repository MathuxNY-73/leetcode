# Sliding Window Challenges
The repsitory contains the problems related to Sliding Window algorithms I tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Sliding Median Window
The goal of this challenge is to code a function that takes in an array and a
window size and returns the medians obtained when sliding the window over the
array.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/sliding-window-median/)  
As of November 4<sup>th</sup>, 2019:
- [x] Write a solution that works on the sample input. I wrote a solution that works in O(N*log k)
- [x] Submit solution. Got correct in 64 ms with 16.1 MB
- [x] Problem solved

### Minimum Window Substring
The goal of this challeng is to determine the susbtring of minimal length that
contains letters from a given string pattern.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/minimum-window-substring/)  
As of July 6<sup>th</sup>, 2020:
- [X] Find a first working solution. The approach I took is a sliding window
      approach with two pointers marking the start and the end of the window. In
      a first step I advance the right pointer until the string between the left
      and the right pointer contains the characters of the searched string. Then
      I try to reduce that window by moving the left pointer torward the right
      pointer. Then if the difference between right and left pointer is smaller
      than the previous window we update the minimal window. Then we start again
      by moving the right and then the left pointer. The runtime complexity of
      this algorithm is O(2 * S + T) = O(S + T). The extra space needed for the
      algorithm is O(S + T) as we need to store the occurences of each unique
      characters in a hashmap, the worst case is when S and T have all unique
      characters and are the same size.
- [X] Submit solution. Got correct in 60 ms with 7.8 MB
- [X] Optimized the approach. Instead of working with the full string to search
      into, I added a preprocessing step to filter the string and store only the
      letters that are in the pattern along with their indices. This
      optimization is worth it if the filtered string is much smaller that the
      original string. There is also an added memory cost. The runtime
      complexity is now O(2 * FS + S + T) = O(S + T) where FS is the length of
      the filtered string and the space complexity is O(FS + S + 2 * T) = O(S +
      T).
- [X] Submit solution. Got correct in 44 ms with 10.5 MB
- [X] Problem solved
