# 18.4Sum
### 题⽬
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums
such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of
target.

****Note:****

The solution set must not contain duplicate quadruplets.
****Example:****
```
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
 [-1, 0, 0, 1],
 [-2, -1, 1, 2],
 [-2, 0, 0, 2]
]
```
### 题⽬⼤意
给定⼀个数组，要求在这个数组中找出 4 个数之和为 0 的所有组合。
### 解题思路
⽤ map 提前计算好任意 3 个数字之和，保存起来，可以将时间复杂度降到 O(n^3)。这⼀题⽐较麻烦的
⼀点在于，最后输出解的时候，要求输出不重复的解。数组中同⼀个数字可能出现多次，同⼀个数字也
可能使⽤多次，但是最后输出解的时候，不能重复。例如 [-1，1，2, -2] 和 [2, -1, -2, 1]、[-2, 2, -1, 1] 这
3 个解是重复的，即使 -1, -2 可能出现 100 次，每次使⽤的 -1, -2 的数组下标都是不同的。
这⼀题是第 15 题的升级版，思路都是完全⼀致的。这⾥就需要去重和排序了。map 记录每个数字出现
的次数，然后对 map 的 key 数组进⾏排序，最后在这个排序以后的数组⾥⾯扫，找到另外 3 个数字能
和⾃⼰组成 0 的组合。
第 15 题和第 18 题的解法⼀致。

Suppose we have an array of numbers. It stores n integers, there are four elements a, b, c and d in the array. We have another target value, such that a + b + c + d = target. Find all unique quadruplets in the array which satisfies the situation. So if the array is like \[-1,0,1,2,0,-2\] and target is 0, then the result will be \[\[-1, 0, 0, 1\],\[-2, -1, 1, 2\], \[-2, 0, 0, 2\]\]

To solve this, we will follow these steps −

- The actual sum is being done using a function called kSum(). This takes array, start, k and target. Initially function will be called with k value 4. The function will be as follows
- define an array res
- if k = 2, then
    - left := start and right := array size – 1
    - define another array temp of size 2
    - while left < right
        - if arr\[left\] + arr\[right\] = target, then
            - temp\[0\] := arr\[left\], temp\[1\] := arr\[right\], and insert temp into res
            - while left < right and arr\[left\] = arr\[left + 1\]
                - increase l by 1
            - while left < right and arr\[right\] = arr\[right – 1\]
                - decrease r by 1
            - increase l by 1 and decrease r by 1
        - else if arr\[left\] + arr\[right\] > target, then decrease right by 1
        - otherwise increase left by 1
- else
    - for i in range start to arr size – k,
        - if i > start and arr\[i\] = arr\[i - 1\], then skip next steps and continue
        - define one 2d array temp := kSum(arr, i + 1, k – 1, target – arr\[i\])
        - for j in range 0 to temp
            - insert arr\[i\] after temp\[j\]
        - copy all elements of temp to res
- return res