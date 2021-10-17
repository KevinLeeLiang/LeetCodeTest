# 22.Generate Parentheses

- [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

## [](https://redquark.org/leetcode/0022-generate-parentheses/#problem-statement)Problem Statement

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

### [](https://redquark.org/leetcode/0022-generate-parentheses/#constraints)Constraints:

- 1 ≤ `n` ≤ 8

### [](https://redquark.org/leetcode/0022-generate-parentheses/#examples)Examples

Example 1:

```text
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

Example 2:

```text
Input: n = 1
Output: ["()"]
```

## [](https://redquark.org/leetcode/0022-generate-parentheses/#analysis)Analysis

The problem description is fairly straight forward (however the solution may not be 😛). We will be given a number `n` which represents the pairs of parentheses, and we need to find out all of their valid permutations. A valid permutation is one where every opening parenthesis `(` has its corresponding closing parenthesis `)`.

Also, these parentheses can be arranged in any order as long as they are valid. For `n = 2`, the valid pairs are — `(())` and `()()`. Also, note `n = 2` means two `(`s and two `)`s. The maximum number of pairs can be eight.

## [](https://redquark.org/leetcode/0022-generate-parentheses/#approach)Approach

This problem description and the analysis above scream **_Recursion_** and yes it’s the right way to solve this problem. The naive approach is to generate all the permutations. All sequence of length `n` is `(` plus all sequences of length `n - 1`. The time complexity of this will be **_O(22n)_** which is quite large.

What if we generate only those permutations which we know for sure will be valid? It should reduce the time considerably. We can use **[backtracking](https://www.geeksforgeeks.org/backtracking-introduction/#:~:text=Backtracking%20is%20an%20algorithmic%2Dtechnique,reaching%20any%20level%20of%20the)** for this purpose. There will be three constraints we need to consider here —

- Base case when number of opening and closing parentheses is equal to `n`.
- Number of opening parentheses should be less than `n`.
- A closing parenthesis cannot occur before the open parenthesis.

To solve this problem, we will follow the below steps -

1. Create a list that will store the result.
2. Call our backtracking function with empty string and initial number of opening and closing parentheses.
3. Check the base case. If number of opening and closing parentheses are equal to `n` then we will add the string to the list and return.
4. If the base case does not meet then we will check if number of opening parentheses is less than `n`, If true, then we will add `(` to the current string and increment the count of opening parenthesis.
5. Check if number of closing parentheses is less than open parentheses then we will add `)` to the current string and increment the count of closing parentheses.

### [](https://redquark.org/leetcode/0022-generate-parentheses/#time-complexity)Time Complexity

The time complexity is not easy to understand for this problem. It rests on understanding how many elements are there in the function. This indicates the **nth Catalan** number which is bounded asymptotically by **Cn = 4n/(n(n)\\sqrt(n)(​n))**. Since each valid sequence has maximum `n` steps, therefore, the time complexity will be **_O(4n/(n)\\sqrt(n)(​n))_**.

### [](https://redquark.org/leetcode/0022-generate-parentheses/#space-complexity)Space Complexity

Similar as above logic the total space complexity **_O(4n/(n)\\sqrt(n)(​n))_** for recursive calls and **_O(n)_** for storing the sequence.
$x^4$
