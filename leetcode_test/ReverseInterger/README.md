# 7.Reverse Interger
## 题⽬
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
``` 
Input: 123
Output: 321
```
Example 2:

	Input: -123
	Output: -321

Example 3:

	Input: 120
	Output: 21

Note: Assume we are dealing with an environment which could only store integers within the 32-
bit signed integer range: [−2^31, 2\^31 − 1]. For the purpose of this problem, assume that your
function returns 0 when the reversed integer overflows.

## 题⽬⼤意
给出⼀个 32 位的有符号整数，你需要将这个整数中每位上的数字进⾏反转。注意:假设我们的环境只能
存储得下 32 位的有符号整数，则其数值范围为 [−2^31, 2^31 − 1]。请根据这个假设，如果反转后整数
溢出那么就返回 0。
## 解题思路
* 这⼀题是简单题，要求反转 10 进制数。类似的题⽬有第 190 题。
* 这⼀题只需要注意⼀点，反转以后的数字要求在 [−2^31, 2\^31 − 1]范围内，超过这个范围的数字
都要输出 0 。