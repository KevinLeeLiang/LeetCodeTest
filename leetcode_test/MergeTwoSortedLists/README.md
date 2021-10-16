### 21.Merge Two Sorted Lists
#### 题⽬
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing
together the nodes of the first two lists.
****Example:****

	Input: 1->2->4, 1->3->4
	Output: 1->1->2->3->4->4
#### 题⽬⼤意
合并 2 个有序链表

## Problem Statement

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

### [](https://redquark.org/leetcode/0021-merge-two-sorted-lists/#constraints)Constraints:

- The number of nodes in both lists is in the range `[0, 50]`.
- \-100 ≤ `Node.val` ≤ 100
- Both `l1` and `l2` are sorted in non-decreasing order.

### [](https://redquark.org/leetcode/0021-merge-two-sorted-lists/#examples)Examples

Example 1:

```text
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

 ![https://redquark.org/static/2b038dbe54fad2913610d24cf6831806/7bfef/leetcode-21-list-1.jpg](https://redquark.org/static/2b038dbe54fad2913610d24cf6831806/7bfef/leetcode-21-list-1.jpg)
Example 2:

```text
Input: l1 = [], l2 = []
Output: []
```

Example 3:

```text
Input: l1 = [], l2 = [0]
Output: [0]
```

## [](https://redquark.org/leetcode/0021-merge-two-sorted-lists/#analysis)Analysis

We will be given two **_sorted_** linked lists, and we need to merge them in such a way that the resultant list will also be sorted. Lists are sorted in the **_non-decreasing_** order, therefore, the resultant list should also be in non-decreasing order.

## [](https://redquark.org/leetcode/0021-merge-two-sorted-lists/#approach)Approach.

The approach is pretty straight forward. If you have worked with **_Merge Sort_** before, it is similar to that. We will use merge function of the merge sort to solve this problem. The steps are -

1. Check if any of the lists is empty.
2. First we need to determine the head of the resultant list. This head will be smaller of the heads of the given lists.
3. Loop through each node of the lists until one of the lists get traversed completely.
4. While traversing the lists, identify smaller of the nodes of the lists and add it to the resultant list.
5. Once the loop is complete, there may be a case where a list has nodes remaining. We will add those remaining nodes to the resultant list.

### [](https://redquark.org/leetcode/0021-merge-two-sorted-lists/#time-complexity)Time Complexity

If the number of nodes are `m` and `n` in both lists, then the overall time complexity will be **_O(m + n)_** because we are traversing all the nodes of both the lists.

### [](https://redquark.org/leetcode/0021-merge-two-sorted-lists/#space-complexity)Space Complexity

We are creating a list to store our result, but we are not using it as part of our intermediate computations, hence the space complexity according to me will be **_O(1)_**.