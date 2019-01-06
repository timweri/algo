# Container With Most Water
### [Link to problem](https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/830/)

## Problem
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**Note:** You may not slant the container and n is at least 2.

![Illustration](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:
```
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
```

## Solution
The solution is runtime O(n) and constant space. It scans the array once.

It starts with 2 pointers pointing to the first and last element of the array. It then move the shorter one to the next element. If both are the same, it moves both. Each time, it computes the volume given by the 2 pointers and update the maximum volume.

This is correct because the current volume is given by `Width x Height`. `Height` is the height of the shorter wall. And `Width` is guaranteed to only decrease as we scan through the array. Thus, the shorter wall will never give us a bigger value of volume.
