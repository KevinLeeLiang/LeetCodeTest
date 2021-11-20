# 28. Implement strStr()
## 题⽬
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of
haystack.

****Example 1:****
```
Input: haystack = "hello", needle = "ll"
Output: 2
```
****Example 2:****
```
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```
#### Clarification:
What should we return when needle is an empty string? This is a great question to ask during an
interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is
consistent to C's strstr() and Java's indexOf().
## 题⽬⼤意
实现⼀个查找 substring 的函数。如果在⺟串中找到了⼦串，返回⼦串在⺟串中出现的下标，如果没有
找到，返回 -1，如果⼦串是空串，则返回 0 。