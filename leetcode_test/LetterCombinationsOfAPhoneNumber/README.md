# 17. Letter Combinations of a Phone Number
## 题⽬
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does
not map to any letters

****Example:****
```
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```
Note:
Although the above answer is in lexicographical order, your answer could be in any order you
want.
## 题⽬⼤意
给定⼀个仅包含数字 2-9 的字符串，返回所有它能表示的字⺟组合。给出数字到字⺟的映射如下（与电
话按键相同）。注意 1 不对应任何字⺟。
解题思路
DFS 递归深搜即可


> Given a digit string, return all possible letter combinations that the number could represent.  
> ![这里写图片描述](https://img-blog.csdn.net/20170605201341140?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvd3lzMjAxMTEwMTE2OQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)  
> A mapping of digit to letters (just like on the telephone buttons) is given below.
> 
> Input:Digit string “23”  
> Output: \[“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”\].
> 
> Note:  
> Although the above answer is in lexicographical order, your answer could be in any order you want.

### 题意

> 给定一个数字字符串，返回所有数字代表的字符组成的字符串

### 注意

> 边界：字符串的合法性  
> 数字1，\*号，#号如何处理 该题不给予考虑。  
> 空数字字符串的输入  
> 多个解的顺序

### 思路

> 典型的树形问题。  
> 数字字符串的个数代表树的高度。e.g digits=”23”  
> ![这里写图片描述](https://img-blog.csdn.net/20170605202406770?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvd3lzMjAxMTEwMTE2OQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
> 
> > digits 是数字字符串  
> > s(digits) 是digits所能代表的字母字符串  
> > s(digits\[0…n-1\])  
> > \= letter(digits\[0\]) + s(digits\[1…n-1\])  
> > \= letter(digits\[0\]) + letter(digits\[1\]) + s(digits\[2…n-1\])  
> > \= ……

- 从2开始有三条路，到3也有三条路，选择a路线，输出为ad，回溯到3，输出为ae，回溯到3，输出为af，继续向上一层回溯2，走b路线。。。
- 提前将数字和字符间的映射关系存储好
- 假设所有的数字代表三个字符那么时间复杂度为O(3^n) =O(2^n)，n为数字字符串的长度，一般计算机处理大概到20。
- 回溯法是暴力解法的一个主要实现手段
- 当数字字符串长度是固定的可以使用多重循环迭代解决。此题n是一个不确定的，只能使用递归

### 结果

![这里写图片描述](https://img-blog.csdn.net/20170605203654759?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvd3lzMjAxMTEwMTE2OQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)