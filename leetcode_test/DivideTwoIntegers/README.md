# 29. Divide Two Integers
## 题⽬
Given two integers dividend and divisor , divide two integers without using multiplication,
division and mod operator.
Return the quotient after dividing dividend by divisor .
The integer division should truncate toward zero.
#### Example 1:
```
Input: dividend = 10, divisor = 3
Output: 3
```
#### Example 2:
```
Input: dividend = 7, divisor = -3
Output: -2
```
#### Note:
- Both dividend and divisor will be 32-bit signed integers.
- The divisor will never be 0.
- Assume we are dealing with an environment which could only store integers within the 32-
bit signed integer range: [−2^31, 2^31 − 1]. For the purpose of this problem, assume that
your function returns 2^31 − 1 when the division result overflows.

## 题⽬⼤意
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使⽤乘法、除法和 mod 运算
符。返回被除数 dividend 除以除数 divisor 得到的商。
说明:
- 被除数和除数均为 32 位有符号整数。
- 除数不为 0。
- 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1]。本题中，如果除
法结果溢出，则返回 2^31 − 1。
## 解题思路
- 给出除数和被除数，要求计算除法运算以后的商。注意值的取值范围在 [−2^31, 2^31 − 1] 之中。
超过范围的都按边界计算。
- 这⼀题可以⽤⼆分搜索来做。要求除法运算之后的商，把商作为要搜索的⽬标。商的取值范围是
[0, dividend]，所以从 0 到被除数之间搜索。利⽤⼆分，找到(商 + 1 ) * 除数 > 被除数并且 商 * 除 数 ≤ 被除数 或者 (商+1)* 除数 ≥ 被除数并且商 * 除数 < 被除数的时候，就算找到了商，其余情况
继续⼆分即可。最后还要注意符号和题⽬规定的 Int32 取值范围。
- ⼆分的写法常写错的 3 点：
  1. low ≤ high (注意⼆分循环退出的条件是⼩于等于)
  2. mid = low + (high-low)>>1 (防⽌溢出)
  3. low = mid + 1 ; high = mid - 1 (注意更新 low 和 high 的值，如果更新不对就会死循环)


**Approach :** Keep subtracting the dividend from the divisor until dividend becomes less than divisor. The dividend becomes the remainder, and the number of times subtraction is done becomes the quotient.

**Time complexity :** O(a)   
**Auxiliary space :** O(1)
  
**Efficient Approach:** Use bit manipulation in order to find the quotient. The divisor and dividend can be written as 

> dividend = quotient \* divisor + remainder

As every number can be represented in base 2(0 or 1), represent the quotient in binary form by using shift operator as given below : 

1. Determine the most significant bit in the quotient. This can easily be calculated by iterating on the bit position _i_ from 31 to 1.
2. Find the first bit for which ![divisor << i                    ](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-f6c61062d86c276c9268c934f1a88ad0_l3.svg "Rendered by QuickLaTeX.com")is less than dividend and keep updating the ith bit position for which it is true.
3. Add the result in _temp_ variable for checking the next position such that **(temp + (divisor << i) )** is less than **dividend**.
4. Return the final answer of quotient after updating with corresponding sign.

**Time complexity :** O(log(a))   
**Auxiliary space :** O(1)