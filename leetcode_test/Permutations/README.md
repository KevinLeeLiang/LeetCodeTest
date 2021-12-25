# 46. Permutations
## 题⽬
Given a collection of distinct integers, return all possible permutations.

****Example:****
```
Input: [1,2,3]
Output:
[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
]
```
## 题⽬⼤意
给定⼀个没有重复数字的序列，返回其所有可能的全排列。

## 解题思路
求出⼀个数组的排列组合中的所有排列，⽤ DFS 深搜即可。

![https://media.geeksforgeeks.org/wp-content/uploads/permutationString.jpg](https://media.geeksforgeeks.org/wp-content/uploads/permutationString.jpg)

We can use permutate that modifies a string so that it stores lexicographically next permutation. If current string is lexicographically largest, i.e., “3,2,1”, then next\_permutation returns false.

We first sort the string, so that it is converted to lexicographically smallest permutation. Then we one by one call next\_permutation until it returns false.