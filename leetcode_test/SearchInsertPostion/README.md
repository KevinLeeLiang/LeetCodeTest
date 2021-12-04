# 35. Search Insert Position
## 题⽬
Given a sorted array and a target value, return the index if the target is found.If not, return the
index where it would be if it were inserted in order.
You may assume no duplicates in the array

****Example 1:****
```
Input: [1,3,5,6], 5
Output: 2
```
****Example 2:****
```
Input: [1,3,5,6], 2
Output: 1
```
****Example 3:****
```
Input: [1,3,5,6], 7
Output: 4
```
****Example 4:****
```
Input: [1,3,5,6], 0
Output: 0
```
### 题⽬⼤意
给定⼀个排序数组和⼀个⽬标值，在数组中找到⽬标值，并返回其索引。如果⽬标值不存在于数组中，
返回它将会被按顺序插⼊的位置。
你可以假设数组中⽆重复元素。
### 解题思路
- 给出⼀个已经从⼩到⼤排序后的数组，要求在数组中找到插⼊ target 元素的位置。
- 这⼀题是经典的⼆分搜索的变种题，在有序数组中找到最后⼀个⽐ target ⼩的元素。

**Efficient Approach:** To optimize the above approach, the idea is to use [Binary Search](https://www.geeksforgeeks.org/binary-search/). Follow the steps below to solve the problem: 

- Set **start** and **end** as **0** and **N – 1**, where the **start** and **end** variables denote the lower and upper bound of the search space respectively.
- Calculate **mid = (start + end) / 2**.
- If **arr\[mid\]** is found to be equal to **tar**, print **mid** as the required answer.
- If **arr\[mid\]** exceeds **tar**, set **low = mid + 1**. Otherwise, set **high = mid – 1**.

_**Time Complexity:** O(log N)_  
_**Auxiliary Space:** O(1)_