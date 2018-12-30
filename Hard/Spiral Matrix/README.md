# Spiral Matrix
### [Link to problem](https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/828/)

## Problem
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```

Example 2:
```
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

## Solution
Each time we change direction, a column/row won't be visited again. We keep track of the current min/max possible row/col (which only changes when we change direction). We also keep track of the current direction. Current direction tells us whether we should modify the col or row.
