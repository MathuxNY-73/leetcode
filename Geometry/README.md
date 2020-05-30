# Geometry challenges
The repsitory contains the problems related to geometry I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Minimum Area Rectangle II
The goal of this challenge is to code a function that finds the minimum area that can be formed by a rectangle in a given set of points.  
I tried to solve this problem using the C++, Rust and Python 3 languages [Problem link](https://leetcode.com/problems/minimum-area-rectangle-ii/)  
As of November 2<sup>nd</sup>, 2019:
- [x] Write a solution that works on sample input. The solution I have is O(n<sup>3</sup>) in time.
- [x] Submit solution. Got correct in 256 ms with 77.7 MB
- [x] Find a faster solution. Is it possible to do it in O(n<sup>2</sup>) ? No it is not possible best case is O(N<sup>2</sup>logN)
- [x] Submit new solution. Got right in 108 ms with 14.1 MB
- [x] Write the solution in Rust.
- [x] Submit solution. Got right in 16 ms with 4.5 MB
- [x] Problem solved

### Check if it is a Straight Line
The goal of this challenge is to code a function that determines if a set of given points in the 2D space are all on a straight line.  
I tried to solve this problem using the Python3 language [Problem link](https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/)  
As of November 3<sup>rd</sup>, 2019:
- [x] Write a solution that works on sample input.
- [x] Submit solution. Got correct in 64 ms with 14.1 MB
- [x] Problem solved

### K Closest Points to Origin
The goal of this challenge is, given a set of points in the plane R<sup>2</sup>,
to find the K points that are closest to the origin (0,0). The order of the
output does not matter.  
I tried to solve this problem using the Python3 language [Problem
link](https://leetcode.com/problems/k-closest-points-to-origin/)  
As of May 30<sup>th</sup>, 2020:
- [X] Find a first working solution. I chose to use a MaxHeap to hold onto the K
      closest points, meaning the points with lower distance. The heap property
      is kept at the cost of O(log K) and since we need to go through all the
      points the worstcase runtime complexity is O(N * log K). The extra space
      needed is the size of the resulting set of points so O(K)
- [X] Submit solution. Got correct in 700 ms with 19.6 MB
- [ ] Implement the solution that takes average runtime of O(N)
- [X] Problem solved
