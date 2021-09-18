# Longest Substring Without Repeating Characters
## 题目
Given a string, find the length of the longest substring without repeating characters.

### Example 1:
```
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

### Example 2:
```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

### Example 3:
```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence
and not a substring.
```

## 题⽬⼤意
在⼀个字符串重寻找没有重复字⺟的最⻓⼦串。

## 解题思路
这⼀题和第 438 题，第 3 题，第 76 题，第 567 题类似，⽤的思想都是"滑动窗⼝"。
滑动窗⼝的右边界不断的右移，只要没有重复的字符，就持续向右扩⼤窗⼝边界。⼀旦出现了重复字
符，就需要缩⼩左边界，直到重复的字符移出了左边界，然后继续移动滑动窗⼝的右边界。以此类推，
每次移动需要计算当前⻓度，并判断是否需要更新最⼤⻓度，最终最⼤的值就是题⽬中的所求。

### 本题中使用了两种方法：位图法和滑窗法
#### 位图法
#### 滑窗法