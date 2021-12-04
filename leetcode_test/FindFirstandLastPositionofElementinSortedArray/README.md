# 34. Find First and Last Position of Element in Sorted Array
## 题⽬
Given an array of integers nums sorted in ascending order, find the starting and ending position
of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1] .

****Example 1:****
```
  Input: nums = [5,7,7,8,8,10], target = 8
  Output: [3,4]
```
****Example 2:****
```
  Input: nums = [5,7,7,8,8,10], target = 6
  Output: [-1,-1]
```
## 题⽬⼤意
给定⼀个按照升序排列的整数数组 nums，和⼀个⽬标值 target。找出给定⽬标值在数组中的开始位置
和结束位置。你的算法时间复杂度必须是 O(log n) 级别。如果数组中不存在⽬标值，返回 [-1, -1]。

### 解题思路
给出⼀个有序数组 nums 和⼀个数 target ，要求在数组中找到第⼀个和这个元素相等的元素下
标，最后⼀个和这个元素相等的元素下标。
这⼀题是经典的⼆分搜索变种题。⼆分搜索有 4 ⼤基础变种题：
>1. 查找第⼀个值等于给定值的元素
>2. 查找最后⼀个值等于给定值的元素
>3. 查找第⼀个⼤于等于给定值的元素
>4. 查找最后⼀个⼩于等于给定值的元素

这⼀题的解题思路可以分别利⽤变种 1 和变种 2 的解法就可以做出此题。或者⽤⼀次变种 1 的⽅
法，然后循环往后找到最后⼀个与给定值相等的元素。不过后者这种⽅法可能会使时间复杂度下降
到 O(n)，因为有可能数组中 n 个元素都和给定元素相同。(4 ⼤基础变种的实现⻅代码)是第一个不满足条件的位置。
所以，当两个相等的时候代表没有找到，如果找到了的话，需要返回的是\[left, right - 1\].

#### 二分查找
本来见到这个题，第一感觉肯定就是二分查找左右区间，并且题目很明显的说了O(logn)的时间复杂度，那么明显就是要求使用二分。
题目要求找到开始的索引和结束索引，所以就是C++的lower_bound和upper_bound。代码我觉得应该是要背下来的，这两个函数只有一点不同，就是nums[mid]与target的判断，lower_bound倾向于找左边的元素，所以只有nums[mid] < target时才移动左指针；而upper_bound倾向于找右边的元素，所以当nums[mid] <= target就向右移动左指针了。
lower_bound返回的是开始的第一个满足条件的位置，而upper_bound返回的是第一个不满足条件的位置。所以，当两个相等的时候代表没有找到，如果找到了的话，需要返回的是[left, right - 1].