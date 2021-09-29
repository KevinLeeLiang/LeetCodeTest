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
新建一个ASCII码表，设置左右索引，移动右索引，判断有索引对应的字符串字符在ASCII码中对应的字符是否已经在字符串中出现，如果没出现过，则该位置由0至1，并继续移动右索引，如果出现过则移动左索引；判断左索引对应的字符串字符在ASCII码表中对应的字符是否在字符串中出现过，如果没出现过，则该位置由0至1，并继续移动右索引，如果出现过，继续移动左索引直到右索引到字符串的结尾，不断更新无重复的子串长度最大值
#### 滑窗法
使用一个列表保存无重复子字符串，如果新字符在子串中，那么已经统计了当前子串的最大值，需要往后进行访问，寻找其它子串，为了防止重复，则把最开头到子串中字符重复位置的都删除，并加入新字符，保证子串中没有重复的字符。

1. 将字符串从前到后按字符进行遍历，并建立无重复子字符串
2. 找到子串中跟新字符相同字符的位置，并删除从前面到该位置所有字符，重新开始寻找新的子串
3. 用c记录每个子串长度，用mx记录最大的长度

- 时间复杂度：O(n)
- 空间复杂度：O(n)