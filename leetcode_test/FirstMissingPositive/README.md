# 41.First Missing Possitive
## 题目
Give an unsorted integer array, find the smallest missing positive integer

**Example 1**
```
Input: [1,2,0]
Output: 3
```
**Example 2**
```
Input: [3,4,-1,1]
Output: 2
```
**Example 2**
```
Input: [7,8,9,11,12]
Output:	1
```
**Note:**

You algorithm should run in O(n) time and uses constant extra space
### 题目大意
找到确实的第一个正整数
### 解题思路
为了减少时间复杂度，可以把input数组都装到map中，然后i循环从1开始，一次对比map中是否存在i，只要不存在i就立即返回结果，即为所求

The idea is to store the occurrences of the numbers itself in the array. Since the range for missing elements for an array of size n is \[1,n+1\], so we can use the value of the index in the array to mark the presence of a number in the array (keeping in mind to retrieve the original elements after updating it).How should we mark the presence of an element? (**Think!**)

When we come across an element k, where 1 ≤ k ≤ N, we will update the value at index (k-1) to its negative value, i.e. A\[k-1\] = -A\[k-1\]. (Why index k-1 and not k?) But this approach can still fail for some types of cases, can you guess which cases?

We need to take care of not accidentally modifying the value at the same index more than once when we encounter duplicates. Also, this approach doesn’t work if there are non-positive numbers. So we first need to segregate positive numbers from negative numbers and then apply the above discussed in-place hashing approach.

> **_Solution Steps_**

- Segregate the positive numbers from others, i.e. to move all negative integers to the right side of the array and return the size of the sub-array containing the positive integers (which is **N** here). We will use a helper function **segregate()** for this purpose. This function will use the two-pointer approach similar to the partition function in the Quick sort.
- Now iterate through this sub-array and mark the presence of an element **A\[i\],** if **abs(A\[i\])-1 < N**.
- To ensure that we don't do so more than once on the same index, we assign A\[abs(A\[i\])-1\] = - **abs(**A[abs(A\[i\])-1\]**)**. 
- Now scan through the array till **N** and find the first positive element and return its index i.e **i+1**. If we didn't find any positive value after the loop then return **N+1.**

