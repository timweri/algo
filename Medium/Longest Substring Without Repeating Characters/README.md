# 3. Longest Substring Without Repeating Characters
### [Link to problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Problem
Given a string, find the length of the longest substring without repeating characters.

**Example 1:**
```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```

**Example 2:**
```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**
```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
```

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

## Solution
Scan from left to right.
