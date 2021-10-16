## 20.Valid Parantheses
#### 题⽬
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

****Example 1:****

	Input: "()"
	Output: true
****Example 2:****

	Input: "()[]{}"
	Output: true
****Example 3:****

	Input: "(]"
	Output: false
****Example 4:****

	Input: "([)]"
	Output: false
****Example 5:****

	Input: "{[]}"
	Output: true
#### 题⽬⼤意
括号匹配问题。
#### 解题思路
遇到左括号就进栈push，遇到右括号并且栈顶为与之对应的左括号，就把栈顶元素出栈。最后看栈⾥⾯
还有没有其他元素，如果为空，即匹配。
需要注意，空字符串是满⾜括号匹配的，即输出 true。

### [](https://redquark.org/leetcode/0020-valid-parentheses/#Analysis)Analysis

In this question, we need to deal with only 6 symbols — `(`, `)`, `{`, `}`, `[`, `]`. We will be given a string containing only these symbols. A string is valid if all the symbols are present in pairs and left parenthesis comes before the corresponding right.

### [](https://redquark.org/leetcode/0020-valid-parentheses/#Approach)Approach

This is a simple question 😃. We will traverse the string `s` from left to right and see if left and right parentheses are matching with their corresponding counterpart.

1. Traverse the string from left to right.
2. If we encounter the open/left parenthesis, then we will push it to the **_Stack_** data structure due to its `Last In First Out (LIFO)` property.
3. If we encounter any of the close/right parentheses, we will check it with the `top` of the stack. If it is the correct corresponding open/left parenthesis, we will move further, else we will return false.
4. At last, for valid string, the stack should be empty because all the left parentheses should have matched with the right ones.

### [](https://redquark.org/leetcode/0020-valid-parentheses/#time-complexity)Time Complexity

We are traversing the string once, hence the time complexity will be **_O(n)_**.

### [](https://redquark.org/leetcode/0020-valid-parentheses/#space-complexity)Space Complexity

We are using **Stack** to store characters of the string, hence the space complexity will be **_O(n)_**.