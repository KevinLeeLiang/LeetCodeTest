# 39. Combination Sum
## 题⽬
Given a **set** of candidate numbers ( candidates ) (**without duplicates**) and a target number
( target ), find all unique combinations in candidates where the candidate numbers sums to
target .

The **same** repeated number may be chosen from candidates unlimited number of times.

**Note:**
- All numbers (including target ) will be positive integers.
- The solution set must not contain duplicate combinations.

**Example 1:**
```
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
 [7],
 [2,2,3]
]
```
**Example 2:**
```
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
 [2,2,2,2],
 [2,3,3],
 [3,5]
]
```
## 题⽬⼤意
给定⼀个⽆重复元素的数组 candidates 和⼀个⽬标数 target ，找出 candidates 中所有可以使数字和
为 target 的组合。

candidates 中的数字可以⽆限制重复被选取。

## 解题思路
- 题⽬要求出总和为 sum 的所有组合，组合需要去重。
- 这⼀题和第 47 题类似，只不过元素可以反复使⽤。

#### **Understanding The Problem**

**Problem Description**

Given an array of integers `arr[]` and a target number `k`, write a program to find **all unique combinations** in `arr[]` such that the sum of all integers in the combination is equal to `k`.

**Problem Note:**

- All numbers (including target number `k`) will be positive integers.
- The same number may be chosen from `arr[]` the unlimited number of times.
- Elements in a combination (`a1`, `a2`, … , `ak`) must be in non-descending order. (i.e, `a1` ≤ `a2` ≤ … ≤ `ak`).
- The combinations themselves must be sorted in ascending order, i.e., the combination with the smallest first element should be printed first.
- The solution set must not contain duplicate combinations.

#### Backtracking Solution

First of all, we need to sort the array, to ensure the combination to be unique and also the numbers in the combination to be listed in a non-descending order.

Then, we define a recursive function with the signature as:

```c++
void BackTrack(std::vector<std::vector<int>>&res, std::vector<int>candidate, std::vector<int>& nums, int target, int start)
```

where `"candidate"` is the list that we could take numbers from, `"result"` is the list of combination that we have accumulated so far, `"start"` is the starting point at which we could take numbers from forwards (no backward), and `"target"`is the rest sum that we need to achieve. A recursion tree for the above example might look like this →

![](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/combination-sum-example-9e7b2fd009a8f6a8.png)

As a recursive function, the bottom cases for the `backracking()` are:

1. 1\. The value of the `start` is equal to the `target`, we then find a combination, so just add the `start` to the `result` and output the result.
2. The value of the `start` is greater than the `target`, then it is impossible to find the combination onwards because the `candidates` the list is sorted and all the following elements would be greater than the `target` as well.

Given the above recursive function, we could solve the problem by calling the function for each candidate starting from the start point.  
For each candidate, we first try to add the candidate into the `result`, and then again starting from this candidate, we call the `backtracking()` function to obtain the result for the new `target` afterwards.

**Solution Steps**

- Create a `result` array to store the valid sequences
- Create a `curr` array that will store the current sequence found in the path of the recursion tree.
- A backtrack function that will go into the recursion until the target is achieved, otherwise, it should backtrack to the previous phase as `target` becomes less than 0.
- At any point in time, if `target` becomes `0` then add the `candidate` array to the result as the values in the `candidate` array must be sum up to the given target.
- If those are not the cases then, one by one add the elements in the candidate array and recursively move forward.

**Complexity Analysis**

**_Time Complexity:_** O(l^k)

- Where l is the length of the array, k is the length of the longest possible combination (namely `target / minInArray`).  
    i.e. If the min value in the array is 1, and the target is 9, the longest length of possible combination is 9 (9/1).

**_Space Complexity:_** O(k), for storing the path, which could be k long at most.

**Critical Ideas To Think**

- In the `backtrack` function why did we start the for loop from `start` than `start + 1` ?
- If the question requires that the same number can be chosen only one time, then what change should we have to make in the pseudo code?
- What are the base cases of the recursion?
- Why we are appending the sequence to our result only when the target is equal to zero?
- Give a thought over the time complexity which is O(l^k).
- Find problems where you can apply a similar approach.