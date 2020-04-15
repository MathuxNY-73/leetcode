# Hash Table Challenges
The repsitory contains the problems related to Hash Table I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Group Anagrams
The goal of this challenge is to group words that are anagrams together in subarrays.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/group-anagrams/)  
As of April 6<sup>th</sup>, 2020: 
- [X] Find a first working solution. I decided to use sort and compare for each
      word in the given array. I sort each word and then use those sorted words
      to group the original words. Anagrams should compare the same when sorted.
      Sorting takes O(K log K) where K is the length of the word. Since I do
      that for every word I get a time complexity of O(NK log K). Then I run
      again over the word to group them, so overall time complexity is O(NK log
      K). Since I need to save the sorted words and their indices I need O(NK)
      extra space.
- [X] Submit solution. Got correct in 112 ms with 15.7 MB
- [X] Second solution. This solution is faster than the previous as what is done
      now is to count the occurences of each character in the string. Using this
      approach the time complexity goes down to O(NK).
- [X] Submit solution. Got correct in 40 ms with 15.4 MB
- [X] Problem solved

### Counting elements
The goal of this challenge is to count the number of elements whose successor
(ie: x+1) is in the given array.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem link]()  
As of April 7<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to use a HashTable to store all
      the distinct numbers that are in the array. That way, during a second pass
      over the array I can check, for each x, if x + 1 is also in the array. The
      overall time complexity is O(N) and I need O(N) extra space to store the
      hash table.
- [X] Submit solution. Got correct in 0 ms with 6.9 MB
- [X] Find another solution more efficient in memory. Using a sort I can order
      the element and then pass through the array and add to the result the
      count of numbers x where x + 1 follows. The time complexity is then O(N
      log N) for sorting but the space needed is thus brought down to O(1) as
      sorting is done in-place.
- [X] Submit solution. Got correct in 4 ms with 6.5 MB
- [X] Problem solved

### Contiguous array
The goal of this challenge is to write a function that outputs the longest
contiguous subarray which contains equal number of 1s and 0s in a binary array.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/contiguous-array/)  
As of April 13<sup>th</sup>, 2020:
- [X] Find a first working solution. I tried the brute-force solution, running
      through all the possible subarrays. This solution runs in
      $\mathcal{O}(N^{2})$. This solution only needs constant space O(1)
- [X] Submit solution. Got Time Limit Exceeded
- [X] Find a second solution. This time I keep track of the prefix sum of the
      array. Assigning value -1 to zero element, I know ones and zeroes are
      balanced whenever the sum is zero. Also if I get the same sum at index i
      and j with $j > i$ then ones and zeros are balanced between those indices,
      so I need to keep track of the prefix sum at each index. I used a hash map
      to store the smallest index where each value of the prefix sum was
      encountered first. This solution then runs in O(N) time and uses O(N)
      extra space.
- [X] Submit solution. Got correct in 104 ms with 17.7 MB
- [X] Problem solved

### Maximum size subarray with sum equal k
The goal of this challenge is to find the largest subarray of integers whose
elements sum up to k.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)  
As of April 13<sup>th</sup>, 2020:
- [X] Find a frist working solution. I computed the prefix sums and then iterate
      through the array of prefix sums to find the start and end indices of the
      largest subarray. This solution runs in O(N<sup>2</sup>) and uses O(N)
      extra space.
- [X] Submit solution. Got Time Limit Exceeded
- [X] Optimize the previous solution. I used a map to store the prefix sum at
      the first index seen. Then the new time complexity is O(N) with O(N) extra
      space needed
- [X] Submit solution. Got correct in 36 ms with 10.9 MB
- [X] Problem solved
