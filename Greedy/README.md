# Greedy Challenges
The repsitory contains the problems related to Greedy algorithm I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Meeting Room II
The goal of this problem is to determine the minimum number of meeting rooms
needed to accomodate every meetings given by an interval with a start and an end
date.  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/meeting-rooms-ii/)  
As of March 12<sup>th</sup>, 2020:
- [X] Find a first solution. I used a priority queue to determine the number of
      meeting occuring at the same time. The algo runs in O(N log N)
      time complexity with O(N) extra space needed
- [X] Submit solution. Got correct in 68 ms with 17.2 MB
- [X] Problem solved

### Best time to buy and sell stock II
The goal of this challenge is, given an array of prices for each day, find the
maximum profit that can be made by buying and selling stocks at those prices.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)  
As of April 5<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to simply use the peak and valley
      approach. When the trend of number starts going down then simply add the
      difference between the peak and the minimum element of the subarray so
      formed. The time complexity of this solution is O(N) and it needs O(1)
      extra space.
- [X] Submit solution. Got correct in 60 ms with 15.2 MB
- [X] Problem solved

### Last Stone Weight
The goal of this challenge is to create a function that returns the weight of
the last remaining stone after applying the following process:
 1. Pick the two heaviest stones $x$ and $y$ in the array with $x \leq y$
 2. Smash the stones together:
  - if $x = y$ then the stones
  - if $x \neq y$ then y becomes a stone of weight $y-x$
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/last-stone-weight/)  
As of April 12<sup>th</sup>, 2020:
- [X] Find a first working solution. I used a priority queue to keep the
      element sorted. The time complexity for building a heap is O(N log N), the
      time complexity of running the algorithm is O((log N)<sup>2</sup>). The
      algorithm needs O(N) extra space.
- [X] Submit solution. Got correct in 4 ms with 6.2 MB
- [X] Rewrite the solution using a Max Heap tools from the algorithm library.
      The time complexity remains O(N log N) but since we are doing every thing
      in place then I brought down the space complexity to O(1)
- [X] Submit solution. Got correct in 0 ms with 6.1 MB
- [X] Problem solved

### Best time to buy and sell stock
The goal of this challenge is, given an array of prices for each day, find the
maximum profit that can be made by buying and selling stocks only once at those prices.  
I tried to solve this problem using the Python language [Problem
link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)  
As of April 15<sup>th</sup>, 2020:
- [X] Find a first working solution. Following on the peak and valley approach I
      run through the array to find the maximum difference between peak and
      valley. The time complexity of this solution is O(N) and it needs O(1)
      extra space.
- [X] Submit solution. Got correct in 68 ms with 15.1 MB
- [X] Problem solved

### Jump Game
The goal of this challenge is to determine if it is possible to jump to the last
element of an array where each integer represent the maximum length of the jump
we can make from this index.  
The problem featured in the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/jump-game/)  
As of April 25<sup>th</sup>, 2020:
- [X] Find a first working solution. In my solution, I maintain a max variable
      which holds the maximum index that we can reach running through every
      element of the array. If maximum is reach and we are not at the end of the
      array then it is not possible to jump to the end. Since I run through
      every element in the array the time complexity of this algorithm is O(n).
      As no extra space is needed, the space complexity of the algo is O(1)
- [X] Submit solution. Got correct in 4 ms with 7.9 MB
- [X] Problem solved

### Remove K digits
The goal of this challenge is to compute the smallest possible integer we can
form by removing exactly k digits from the number.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/remove-k-digits/)  
As of May 15<sup>th</sup>, 2020:
- [X] Find a first working solution. I run through the digits starting from the
      left and I keep track of the digits I want to remove to form a increasing
      subsequence of digits. I run through all the digits so the runtime
      complexity is O(N) and the space complexity is also O(N).
- [X] Submit solution. Got correct in 12 ms with 7 MB
- [X] Problem solved

### Two City Scheduling
The goal of this challenge is to compute the minimum transportation cost for
sending N people to the city A or B. Each person has a cost of transportation to
go to city A and to city B. We must however send the same number of people to
each city.  
I tried to solve this problem using the C++ language [Problem
link](https://leetcode.com/problems/two-city-scheduling/)  
As of June 3<sup>rd</sup>, 2020:
- [X] Find a first working solution. I sorted the element of the array by their
      difference in cost between city A and B. That way people for whom it is
      less expensive to go A are at the beginning of the list. The sorting takes
      O(N log N) and is the most expensive operation as afterward to compute the
      answer we just need to go through every element which takes O(N). Since
      the sorting is done in place there are no extra space needed, so a space
      complexity of O(1).
- [X] Submit solution. Got correct in 14 ms with 7.9 MB
- [X] Problem solved
