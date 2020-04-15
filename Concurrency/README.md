# leetcode
The repsitory contains all the problems I have tried to solve on the leetcode [website](https://leetcode.com/problemset/all/)

### Print in order
The goal of this challenge is to print "firstsecondthird" using print functions outputing "first", "second" and "third". Those functions are called once and only once but by different threads. Thus the goal is to implement a mechanism that insure that the prints are done in the right order.  
I triead to solve this problem using the C and C++ language [Problem link](https://leetcode.com/problems/print-in-order)  
As of August 26<sup>th</sup>, 2019:
- [x] Find a first working solutionn on the sample input.
- [x] Submit solution. Got Time Limit Exceeded error. Suspected Spinlock.
- [x] Use another mechanism to avoid spinlock.
- [x] Submit solution. Got correct in 124 ms with 7.6 MB
- [x] Rewrite solution using pthread_mutex in C
- [x] Submit solution. Got correct in 164 ms with 7.8 MB
- [x] Write a C++ solution using std Mutex.
- [x] Submit solution. Got correct in 136 ms with 9.4 MB
- [x] Problem solved
