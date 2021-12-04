# 题⽬
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.' .
### Note:
- The given board contain only digits 1-9 and the character '.' .
- You may assume that the given Sudoku puzzle will have a single unique solution.
- The given board size is always 9x9 .
## 题⽬⼤意
编写⼀个程序，通过已填充的空格来解决数独问题。⼀个数独的解法需遵循如下规则：
1. 数字 1-9 在每⼀⾏只能出现⼀次。
2. 数字 1-9 在每⼀列只能出现⼀次。
3. 数字 1-9 在每⼀个以粗实线分隔的 3x3 宫内只能出现⼀次。
空⽩格⽤ '.' 表示。
## 解题思路
- 给出⼀个数独谜题，要求解出这个数独
- 解题思路 DFS 暴⼒回溯枚举。数独要求每横⾏，每竖⾏，每九宫格内， 1-9 的数字不能重复，每
次放下⼀个数字的时候，在这 3 个地⽅都需要判断⼀次。
- 另外找到⼀组解以后就不需要再继续回溯了，直接返回即可。

**What is Sudoku?**

Sudoku is a number-placement puzzle where the objective is to fill a square grid of size ’n’ with numbers between 1 to ’n’. The numbers must be placed so that each column, each row, and each of the sub-grids (if any) contains all of the numbers from 1 to ‘n’.

The most common Sudoku puzzles use a 9x9 grid. The grids are partially filled (with hints) to ensure a solution can be reached.

#### **Understanding the Problem**

**Problem Description:** You are given a **Sudoku puzzle** and you need to fill the empty cells without violating any rules.

A sudoku solution must satisfy all of the following rules:

1. Each of the digits `1-9` must occur exactly once in each row.
2. Each of the digits `1-9` must occur exactly once in each column.
3. Each of the digits `1-9` must occur exactly once in each of the 3x3 sub-boxes of the grid.

**Problem Note:**

The given board contains only digits 1–9 and the character `'.'`.

- You may assume that the given Sudoku puzzle will have a unique solution.
- The given board size is always 9x9.
- Empty cells are indicated by the character ‘ . ‘

**Example Input:** A given sudoku puzzle

![](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/sudoku-solver.png)

**Output:** Solution numbers are marked in red.

![](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/sudoku-solver1.png)

You may first try to solve [the problem here.](https://afteracademy.com/problems/sudoku-solver)


**What is Backtracking?**

Backtracking is an algorithm for finding all (or some) of the solutions to a problem that incrementally builds candidates to the solution(s). As soon as it determines that a candidate cannot possibly lead to a valid solution, it abandons the candidate. Backtracking is all about choices and consequences.

You may further read about [backtracking from here.](https://afteracademy.com/blog/what-is-backtracking)

#### Backtracking Solution

We will now create a Sudoku solver using backtracking by _encoding_ our problem, goal, and constraints in a step-by-step algorithm.

A brute force algorithm visits the empty cells in sequential order, filling in digits sequentially, or backtracking when no digit can be filled without violating any rule.

Initially, the program would solve the puzzle by placing the digit “1” in the first empty cell and checking if it is allowed to be there. If there are no violations (checking row, column and box constraints) then the algorithm advances to the next cell and places a “1” in that cell. When checking for violations, if it is discovered that the “1” is not allowed, the value is changed to “2”. If a cell is discovered where none of the 9 digits is allowed, then the algorithm leaves that cell blank and moves back to the previous cell. The value in that cell is then incremented by one. This is repeated until an allowed value in the last empty cell is discovered.

If we try to draw the recursion tree then each step will branch into 9 branches and at each level, the problem size is reduced by 1.

> **Visualization of the above example using backtracking**

![](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/sudoku-solver-visualization-4bc03fccaaf8ca21.gif)

> **Solution steps**

1. Make a list of all the empty spots.
2. Select a spot and place a number, between 1 and 9, in it and validate the subgrids. Subgrids are the horizontal row, vertical column, and the 3x3 grid associated with that spot.
3. If any of the constraints fail, _abandon that solution by backtracking to the previous state and repeat step 2 with the next number_. Otherwise, check if the goal is reached.
4. If a solution is found, stop searching. Otherwise, repeat steps 2 to 4

However, there are various different techniques to solve this problem that you may [read from here.](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)

> **Complexity Analysis**

**Time Complexity**: O(_n_ ^ _m_) where _n_ is the number of possibilities for each square (i.e., 9 in classic Sudoku) and _m_ is the number of spaces that are blank.

The problem can be designed for a grid size of N\*N where N is a perfect square. For such an N, let M = N\*N, the recurrence equation can be written as

T(M) = 9\*T(M-1) + O(1)

where T(N) is the running time of the solution for a problem size of N. Solving this recurrence will yield, O(9^M).

**Explanation:** This can be seen by working backwards from only a single empty spot. If there is only one empty spot, then you have _n_ possibilities and you must work through all of them in the worst case. If there are two empty spots, then you must work through _n_ possibilities for the first spot and _n_ possibilities for the second spot for each of the possibilities for the first spot. If there are three spots, then you must work through _n_ possibilities for the first spot. Each of those possibilities will yield a puzzle with two empty spots that now have _n_² possibilities.

You may also say that this algorithm performs a depth-first search through the possible solutions. Each level of the graph represents the choices for a single square. The depth of the graph is the number of squares that need to be filled. With a branching factor of _n_ and a depth of _m_, finding a solution in the graph has a worst-case performance of O(_n_ ^ _m_).

**Space complexity:** it’s the recursion stack that is used as an auxiliary space which is N\*N step deep. Remember we need to fill in 81 cells in a 9\*9 sudoku and at each level, only one cell is filled. So, space complexity would be **O(M)**.