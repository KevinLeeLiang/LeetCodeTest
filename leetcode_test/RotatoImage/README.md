# 48. Rotate Image
## 题⽬
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
### Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix
directly. **DO NOT** allocate another 2D matrix and do the rotation.
### Example 1:
```
Given input matrix =
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]
```
### Example 2:
```
Given input matrix =
[
 [ 5, 1, 9,11],
 [ 2, 4, 8,10],
 [13, 3, 6, 7],
 [15,14,12,16]
],
rotate the input matrix in-place such that it becomes:
[
 [15,13, 2, 5],
 [14, 3, 4, 1],
 [12, 6, 8, 9],
 [16, 7,10,11]
]
```
## 题⽬⼤意
给定⼀个 `n × n` 的⼆维矩阵表示⼀个图像。将图像顺时针旋转 90 度。说明：你必须在原地旋转图像，
这意味着你需要直接修改输⼊的⼆维矩阵。请不要使⽤另⼀个矩阵来旋转图像。
## 解题思路
* 给出⼀个⼆维数组，要求顺时针旋转 90 度。
* 这⼀题⽐较简单，按照题意做就可以。这⾥给出 2 种旋转⽅法的实现，顺时针旋转和逆时针旋转。
```c++
 /*
 * clockwise rotate 顺时针旋转
 * first reverse up to down, then swap the symmetry
 * 1 2 3 7 8 9 7 4 1
 * 4 5 6 => 4 5 6 => 8 5 2
 * 7 8 9 1 2 3 9 6 3
 */
 void rotate(vector<vector<int> > &matrix) {
  reverse(matrix.begin(), matrix.end());
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = i + 1; j < matrix[i].size(); ++j)
      swap(matrix[i][j], matrix[j][i]);
  }
 }
 
 /*
 * anticlockwise rotate 逆时针旋转
 * first reverse left to right, then swap the symmetry
 * 1 2 3 3 2 1 3 6 9
 * 4 5 6 => 6 5 4 => 2 5 8
 * 7 8 9 9 8 7 1 4 7
 */
 void anti_rotate(vector<vector<int> > &matrix) {
  for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i + 1; j < matrix[i].size(); ++j)
        swap(matrix[i][j], matrix[j][i]);
    }
 }
```
### 代码
```c++
#pragma once
#include<vector>
namespace RotatoImage {
	std::vector<std::vector<int>> Rotato(const std::vector<std::vector<int>>& image) {
		std::vector<std::vector<int>>	 res;
		res = image;
		std::reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); ++i) {
			for (int j = i + 1; j < res[i].size(); ++j)
				std::swap(res[i][j], res[j][i]);
		}
		return res;
	}
	std::vector<std::vector<int>> anti_Rotato(const std::vector<std::vector<int>>& image) {
		std::vector<std::vector<int>>	 res;
		res = image;
		for (int i = 0; i < res.size(); i++) {
			std::reverse(res.at(i).begin(), res.at(i).end());
		}
		for (int i = 0; i < res.size(); ++i) {
			for (int j = i + 1; j < res[i].size(); ++j)
				std::swap(res[i][j], res[j][i]);
		}
		return res;
	}
	std::vector<std::vector<int>> RotatoImage(const std::vector<std::vector<int>>& image) {
		std::vector<std::vector<int>>	 res = anti_Rotato(image);
		return res;
	};
}
```