# 36. Valid Sudoku
## 题⽬
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to
the following rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 
<div align=center><img src="https://www.tutorialspoint.com/assets/questions/media/47893/Sudoku.jpg" width="200"></div>


A partially filled sudoku which is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character '.' .
Example 1:
```
Input:
[
 ["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]
]
Output: true
```
Example 2:
```
Input:
[
 ["8","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
 modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
invalid.
```

#### Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.' .
The given board size is always 9x9 .

## 题⽬⼤意
判断⼀个 9x9 的数独是否有效。只需要根据以下规则，验证已经填⼊的数字是否有效即可。
1. 数字 1-9 在每⼀⾏只能出现⼀次。
2. 数字 1-9 在每⼀列只能出现⼀次。
3. 数字 1-9 在每⼀个以粗实线分隔的 3x3 宫内只能出现⼀次。

## 解题思路
给出⼀个数独的棋盘，要求判断这个棋盘当前是否满⾜数独的要求：即⾏列是否都只包含 1-9，每
个九宫格⾥⾯是否也只包含 1-9 。
注意这题和第 37 题是不同的，这⼀题是判断当前棋盘状态是否满⾜数独的要求，⽽第 37 题是要
求求解数独。本题中的棋盘有些是⽆解的，但是棋盘状态是满⾜题意的。