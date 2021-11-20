# 30. Substring with Concatenation of All Words
## 题⽬
You are given a string, s, and a list of words, words, that are all of the same length. Find all
starting indices of substring(s) in s that is a concatenation of each word in words exactly once and
without any intervening characters.
#### Example 1:
```
Input:
 s = "barfoothefoobarman",
 words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
respectively.
The output order does not matter, returning [9,0] is fine too.
```
#### Example 2:
```
Input:
 s = "wordgoodgoodgoodbestword",
 words = ["word","good","best","word"]
Output: []
```
## 题⽬⼤意
给定⼀个源字符串 s，再给⼀个字符串数组，要求在源字符串中找到由字符串数组各种组合组成的连续
串的起始下标，如果存在多个，在结果中都需要输出。
## 解题思路
这⼀题看似很难，但是有 2 个限定条件也导致这题不是特别难。1. 字符串数组里面的字符串⻓度都是⼀
样的。2. 要求字符串数组中的字符串都要连续连在⼀起的，前后顺序可以是任意排列组合。

解题思路，先将字符串数组里面的所有字符串都存到 map 中，并累计出现的次数。然后从源字符串从
头开始扫，每次判断字符串数组里面的字符串时候全部都⽤完了(计数是否为 0)，如果全部都⽤完了，
并且⻓度正好是字符串数组任意排列组合的总⻓度，就记录下这个组合的起始下标。如果不符合，就继
续考察源字符串的下⼀个字符，直到扫完整个源字符串。

Suppose we have a string, s, and we also have a list of words, words present in the array are all of the same length. We have to find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

So if the input is like “barfoothefoobarman” and words are \[“foo”, “bar”\], then the output will be \[0,9\]. This is because the substring starting at index 0 and 9 are “barfoo” and “foobar”.

To solve this, we will follow these steps −

- Define a method called ok(), this will take string s, map wordCnt, and n −
    
- make a copy of s into temp
    
- for i in range n to size of s – 1
    
    - if size of temp is multiple of 0, then
        
        - if when temp is not present in wordCnt, then return false
            
        - otherwise
            
            - if wordCnt\[temp\] is 1, then delete temp from wordCnt, set temp as an empty string
                
            - otherwise decrease the value of wordCnt\[temp\] by 1, set temp as empty string.
                
    - increase temp by s\[i\]
        
- if temp is not in wordCnt, then return false
    
- otherwise
    
    - if wordCnt\[temp\] is 1, then delete temp from wordCnt, set temp as an empty string
        
    - otherwise decrease the value of wordCnt\[temp\] by 1, set temp as empty string.
        
- return true when size of wordCnt is 0
    
- From the main method, do this
    
- if size of a is 0, or size of b is 0, then return empty array
    
- make a map wordCnt, store the frequency of strings present in b into wordCnt
    
- make an array called ans
    
- window := number of words x number of characters in each word
    
- make one copy of string a into temp
    
- for i in range window to size of a – 1
    
    - if temp size is divisible by window and call ok(temp, wordCnt, size of b\[0\]), then
        
        - insert i – window into ans
            
    - insert a\[i\] into temp
        
    - if size of temp > window, then delete substring from 0, 1
        
- if temp size is divisible by window and call ok(temp, wordCnt, size of b\[0\]), then
    
    - insert size of a – window into ans
        
- return ans