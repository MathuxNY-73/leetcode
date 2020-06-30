# Mathematics Challenges
The repsitory contains the problems related to Mathematics I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Add two numbers
The goal is to sum two numbers given as two linked lists. The digits are ordered in reverse order meaning the least significant digit comes first.  
I solved this problem using the C language. [Problem link](https://leetcode.com/problems/add-two-numbers/description/)  
As of August 26<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit first solution. Got correct
- [X] Submit second, shorter solution. Got correct
- [X] Problem solved

### Pow(x, n)
The goal is to implement a function that compute x raised to the power of n.  
I solved this problem using the C language. [Problem link](https://leetcode.com/problems/powx-n/description/)  
As of September 11<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit first solution. Got timeout on bigger testcases
- [X] Looked at the hints. Code a second solution.
- [X] Submit second solution. Got correct
- [X] Problem solved

### Add Binary
The goal is to implement a function that performs the sum of two binary numbers passed as strings.  
I solved this problem using the C++ language. [Problem link](https://leetcode.com/problems/add-binary/description/)  
As of September 16<sup>th</sup>, 2018:
- [X] Find a first working solution on the sample input
- [X] Submit solution. Got correct
- [X] Problem solved

### Fibonacci Number
The goal is to implement a function that returns the n<sup>th</sup> Fibonacci Number.  
I tried to solve this problem using the C language. [Problem link](https://leetcode.com/problems/fibonacci-number)  
As of July 30<sup>th</sup>, 2019:
- [X] Find a first working solutionn on the sample input.
- [X] Submit solution. Got correct in 4 ms with 6.9 MB
- [x] Find a faster solution
- [x] Submit solution. Got correct in 0 ms with 6.8 MB
- [x] Find a more economical solution
- [x] Submit solution. Got correct in 0 ms with 6.6 MB
- [X] Problem solved

### Happy number
The goal of this problem is to determine if a number is a happy number. A number
is said to be happy if when we iterate the following process:
 - Squares the digits of the number
 - Sum those squares to get a new number
 - Start over with that new number
we land on 1. The other outcome of this process is a cycle that does not
include 1. One could also think that the process could diverge to infinity but
after some mathemtical reasoning we see that it is not possible for numbers of
14 digits.  
This problem featured in the the [30-day leetcoding of April
2020](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/)  
I tried to solve this problem using the C and C++ languages [Problem
link](https://leetcode.com/problems/happy-number/)  
As of April 2<sup>nd</sup>, 2020:
- [X] Find a first working solution. The approach I used is getting the digits
      of the number and squaring them, this step takes O(log N) where N is the
      number itself. After a little study we see that after passing 243 the
      number cannot go up above. Since there are at most 3 digits in the numbers
      then we can say that the remaining time complexity to either arrive to 1
      or fall down in a loop will be O(3 * 243). A loop cannot exists above 243
      as at every iteration a number above 243 will lose a digit. Counting the
      steps to bring down a number that is higher than 243 down to 243 will take
      O(log N) + O(log log N) + O(log log log N) + ... = O(log N). So in
      conclusion the time complexity of this approach is O(243 * 3 + log N + log
      log N + log log log N + ...)= O(log N). The space complexity is O(log N)
- [X] Submit solution. Got correct in 0 ms with 6.4 MB
- [X] Reduce memory consumption by using Floyd's tortoise and hare algorithm.
      Write the solution in C. Still the solution takes O(log N) in time
      complexity but now it does not need extra memory space so O(1)
- [X] Submit solution. Got correct in 0 ms with 5.1 MB
- [X] Problem solved

### Valid Perfect Square
The goal of this challenge is to determine if a given number is a perfect
square, meaning that the number is obtained by squaring an integer.  
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/valid-perfect-square/)  
As of May 10<sup>th</sup>, 2020:
- [X] Find a first solution. I used the Newton's approach. The principle of this
      approach is to start from an origin point, say x*x - num and go down to
      the searched number. Using derivative we can then compute the next point
      we want to test, $x_{k+1} = \frac{1}{2} (x_k + \frac{num}{x_k})$. The algo
      then can finish in O(log N) using O(1) extra space.
- [X] Submit solution. Got correct in 0 ms with 5 MB
- [X] Problem solved

### Perfect squares
The goal of this challenge is to determine the minimum number of squared number
that sum up to a given number. That is to say find the minimum number of a_i's
such that a_1<sup>2</sup> + a_2<sup>2</sup> + ... + a_n<sup>2</sup> = n.
I tried to solve this problem using the C language [Problem
link](https://leetcode.com/problems/perfect-squares/)  
As of June 27<sup>th</sup>, 2020:
- [X] Find a first working solution. I decided to go for a dynamic programming
      approach. This problem is analogous to the coin change problem. For every
      dp[i] we use the following update formula dp[i] = min(dp[i], dp[i - sq] +
      1) for every squared numbers between 1 and i. This approach allows a
      runtime complexity of O(N sqrt N) and uses O(N) space for the dp array.
- [X] Subtmit solution. Got correct in 168 ms with 8.1 MB
- [ ] Optimize the solution (eg: Greedy, BFS+Greedy, Math-based)
- [X] Problem solved

### Unique Paths
The goal of this challenge is to determine how many unique paths there are for a
robot, to go from the top left corner to the bottom right corner of a m x n
matrix. The robot can only perform two moves: go down and go right.  
I tried to solve this problem using the Rust language [Problem
link](https://leetcode.com/problems/unique-paths/)  
As of June 30<sup>th</sup>, 2020:
- [X] Find a first working solution. This problem is a combinatorics problem. It
      is equivalent as counting the number of permutations of the letters DRRDD
      where D is a move down and R is a move right. In this word there should be
      n - 1 Rs and m - 1 Ds. Thus the answer can be found calculating the
      following formula (m + n - 2)! / ((n - 1)! * (m - 1)!) which equals can be
      simplified by ((m + n - 2)(m + n - 3)...(n)) / (m - 1)!. Howvever, this
      computation can still lead to integer overflow. The algorithm has a
      runtime complexity of O((M + N)(log (M + N) log log (M + N)<sup>2</sup>))
      and a space complexity of O(1).
- [X] Submit solution. Got wrong answer due to Integer overflow
- [X] Find another solution. Using Dynamic Programming it is possible to
      avoid the integer overflow problem. The solution is actually just building
      the Pascal Triangle. Thus the time complexity of the algorithm is O(N * M)
      and I managed to keep the space complexity down to O(N).
- [X] Submit solution. Got correct in 0 ms with 2 MB
- [X] Problem solved
