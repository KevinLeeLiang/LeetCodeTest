# LeetCode #27 - Remove Element


## [](https://redquark.org/leetcode/0027-remove-element/#problem-statement)Problem Statement

Given an array `nums` and a value `val`, remove all instances of that value in-place and return the new length. Do not allocate extra space for another array, you must do this by modifying the input array in-place with **_O(1)_** extra memory.

The order of elements can be changed. It doesn¡¯t matter what you leave beyond the new length.

**Clarification:**

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

```text
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

### [](https://redquark.org/leetcode/0027-remove-element/#constraints)Constraints:

- 0 ¡Ü `nums.length` ¡Ü 100
- 0 ¡Ü `nums[i]` ¡Ü 50
- 0 ¡Ü `val` ¡Ü 100

### [](https://redquark.org/leetcode/0027-remove-element/#examples)Examples

Example 1:

```text
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length. For example if you return 2 with nums = [2,2,3,3] or nums = [2,3,0,0], your answer will be accepted.
```

Example 2:

```text
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]
Explanation: Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4. Note that the order of those five elements can be arbitrary. It doesn't matter what values are set beyond the returned length.
```

## [](https://redquark.org/leetcode/0027-remove-element/#analysis)Analysis

We will be given an array `nums` and a value `val`. We need to remove all occurrences of `val` from the array. In the end, we need to return the length of remaining elements after deleting all occurrences of `val`.

## [](https://redquark.org/leetcode/0027-remove-element/#approach)Approach

We will follow below steps ¡ª

1. Take a variable `count`. This will count the number of elements except `val`.
2. Scan the array left to right.
3. If the current element is not equal to `val`, we will add that element to the place of `count`.

### [](https://redquark.org/leetcode/0027-remove-element/#time-complexity)Time Complexity

Since there is a single scan of the array, the time complexity will be **_O(n)_**.

### [](https://redquark.org/leetcode/0027-remove-element/#space-complexity)Space Complexity

We are not using any data structure for internal computations, hence the space complexity will be **_O(1)_**.