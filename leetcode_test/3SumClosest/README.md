# 16.3Sum Closest
## 题目
Given an array nums of n integers and an integer target, find three integers in nums such that the
sum is closest to target. Return the sum of the three integers. You may assume that each input
would have exactly one solution.

****Example****
```
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

### 题⽬⼤意
给定⼀个数组，要求在这个数组中找出 3 个数之和离 target 最近。

### 解题思路
这⼀题看似和第 15 题和第 18 题很像，都是求 3 或者 4 个数之和的问题，但是这⼀题的做法和 15，18
题完全不同。
这⼀题的解法是⽤两个指针夹逼的⽅法。先对数组进⾏排序，`i` 从头开始往后⾯扫。这⾥同样需要注意
数组中存在多个重复数字的问题。具体处理⽅法很多，可以⽤ `map` 计数去重。这⾥笔者简单的处理，`i`
在循环的时候和前⼀个数进⾏⽐较，如果相等，`i` 继续往后移，直到移到下⼀个和前⼀个数字不同的位
置。`j`，`k` 两个指针开始⼀前⼀后夹逼。`j` 为 `i` 的下⼀个数字，`k` 为数组最后⼀个数字，由于经过排序，所
以`k` 的数字最⼤。`j` 往后移动，`k` 往前移动，逐渐夹逼出最接近 `target` 的值。

### 代码解析
* 先将数组进行有序排列
* 循环整个排序后的数组，读取第i个值，并设定low和high
  * low = i+1
  * high = size - 1
* 计算第i个值、第low个值和第high个值的和sum
  * sum == target：直接返回{计算第i个值、第low个值和第high个值}  
  * sum < target：代表sum不够大，将low++，第low个值如果不变，继续++
  * sum > target：代表sum太大了，将high--，第high个值如果不变，继续--
* 计算过程中随时将fabs(sum - target)的最小值保存下来，直到整个循环结束