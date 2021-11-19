# 26. Remove Duplicates from Sorted Array
## 题⽬
Given a sorted array nums, remove the duplicates in-place such that each element appear only
once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in￾place with O(1) extra memory.
****Example 1:****
```
	Given nums = [1,1,2],
	Your function should return length = 2, with the first two elements of nums
	being 1 and 2 respectively.
	It doesn't matter what you leave beyond the returned length.
```
****Example 2:****
```
	Given nums = [0,0,1,1,1,2,2,3,3,4],
	Your function should return length = 5, with the first five elements of nums
	being modified to 0, 1, 2, 3, and 4 respectively.
	It doesn't matter what values are set beyond the returned length.
```
****Clarification:****

Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array
will be known to the caller as well.
Internally you can think of this:
```
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);
// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len
elements.
for (int i = 0; i < len; i++) {
 print(nums[i]);
}
```
## 题⽬⼤意
给定⼀个有序数组 nums，对数组中的元素进⾏去重，使得原数组中的每个元素只有⼀个。最后返回去
重以后数组的⻓度值。
## 解题思路
这道题和第 27 题很像。这道题和第 283 题，第 27 题基本⼀致，283 题是删除 0，27 题是删除指定元
素，这⼀题是删除重复元素，实质是⼀样的。
这⾥数组的删除并不是真的删除，只是将删除的元素移动到数组后⾯的空间内，然后返回数组实际剩余
的元素个数，OJ 最终判断题⽬的时候会读取数组剩余个数的元素进⾏输出。

**Method1:** (Using extra space)
1. Create an auxiliary array temp\[\] to store unique elements.
2. Traverse input array and one by one copy unique elements of arr\[\] to temp\[\]. Also keep track of count of unique elements. Let this count be **j**.
3. Copy **j** elements from temp\[\] to arr\[\] and return j

Time Complexity : O(n)   
Auxiliary Space : O(n)

**Method 2:** (Constant extra space)   
Just maintain a separate index for same array as maintained for different array in Method 1.

Time Complexity : O(n)   
Auxiliary Space : O(1)