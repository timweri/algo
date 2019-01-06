# 41. First Missing Positive
### [Link to problem](https://leetcode.com/problems/first-missing-positive/)

## Problem
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
```
Input: [1,2,0]
Output: 3
```

Example 2:
```
Input: [3,4,-1,1]
Output: 2
```

Example 3:
```
Input: [7,8,9,11,12]
Output: 1
```

**Note:** Your algorithm should run in O(n) time and uses constant extra space.

## Solution
The solution is runtime O(n) and constant space. It scans the array twice and mutates the given array.

First scan: <br>
Since the minimum missing positive has to be from 1 to n (n is the size of the array), we do not need to care about any number below 1 and above n. For the first scan, we use for loop to scan from left to right. For every number `i` in that range, we swap them to the index `i - 1`. So the current position has a new value, which might be in the range and in the wrong positon. We thus have to keep swapping the current value till it can't be swapped anymore. Then move on to the next element.

Second scan: <br>
At this point, every relevant element is in increasing order. We just have to increment from 1 onwards whenever we see the next positive number. If any is missing then we can return the current one.

It starts with 2 pointers pointing to the first and last element of the array. It then move the shorter one to the next element. If both are the same, it moves both. Each time, it computes the volume given by the 2 pointers and update the maximum volume.
