# 4Sum II
### [Link to problem](https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/829/)

## Problem
Given four lists A, B, C, D of integer values, compute how many tuples `(i, j, k, l)` there are such that `A[i] + B[j] + C[k] + D[l]` is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of `-2^28` to `2^28 - 1` and the result is guaranteed to be at most `2^31 - 1`.

Example:
```
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
```

## Solution
Create a map. Traverse through A and B, add one to the value in map at the index equals to the sum of the current elements in A and B. Thus, the map holds the number of occurence of its index as the sum of elements from A and B.

Now traverse through C and D, the 4 sum is 0 if the sum of the elements from A and B are the negative of the sum of the current elements from C and D. We can look this up in the map to see how many times we got it from A and B.

This solution is O(N^2).
