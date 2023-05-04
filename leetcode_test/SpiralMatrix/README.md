# 54. Spiral Matrix
## 题⽬
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral
order.
### Example 1:
```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```
### Example 2:
```
Input:
[
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```
## 题⽬⼤意
给定⼀个包含 m x n 个元素的矩阵（m ⾏, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
## 解题思路
* 给出⼀个⼆维数组，按照螺旋的⽅式输出
* 解法⼀：需要注意的是特殊情况，⽐如⼆维数组退化成⼀维或者⼀列或者⼀个元素。注意了这些情
况，基本就可以⼀次通过了。
* 解法⼆：提前算出⼀共多少个元素，⼀圈⼀圈地遍历矩阵，停⽌条件就是遍历了所有元素（count
== sum）
## 代码
```c++
#include<vector>
namespace SpiralMatrix {
	std::vector<int> SpiralMatrix(std::vector<std::vector<int>> mat, int m, int n) {
		std::vector<int>res;
		if (m == 0) // 空矩阵
			return {};
		if (m == 1){ // 行向量
			for (int i = 0; i < n; i++){
				res.push_back(mat[0][i]);
			}
			return res;
		}
		if (n == 1) { // 列向量
			for (size_t i = 0; i < m; i++)
			{
				res.push_back(mat[i][0]);
			}
			return res;
		}
		int x = 0, y = 0, round = 0;
		std::vector < std::vector<int> > visit;	 // 已经被访问的元素为1，否则为0
		visit.resize(m);
		std::vector<std::vector<int>> sp_dir = { {0,1}, {1,0}, {0,-1},{-1,0} };
		for (size_t i = 0; i < m; i++) {
			visit.at(i).resize(n);
			for (size_t j = 0; j < n; j++){
				visit.at(i).at(j) = 0;
			}
		}
		visit[x][y] = 1;	 // [0][0] = 1
		res.push_back(mat[x][y]);				// 将[0][0]加入到结果队列
		for (size_t i = 0; i < m*n; i++){
			x += sp_dir[round % 4][0]; // 索引沿着y+,x+,y-,x-方向
			y += sp_dir[round % 4][1];
			if ((x == 0 && y == n - 1) || (x == m - 1 && y == n - 1) || (x == m - 1 && y == 0)) {	// x到m-1或者y到n-1后就会转变向量
				round++;
			}
			if (x > m - 1 || y > n - 1 || x < 0 || y < 0) {
				return res;
			}
			if (visit[x][y] == 0) {
				visit[x][y] = 1;
				res.push_back(mat[x][y]);
			}
			int flag = round % 4;
			switch (flag)
			{
			case 0: {			 // 0向量到了已经被访问的地方后，就要转变方向，一层一层往里缩
				if (y + 1 <= n - 1 && visit[x][y + 1] == 1) {
					round++;
					continue;
				}
				break;
			}
			case 1: {			// 1向量到了已经被访问的地方后，就要转变方向，一层一层往里缩
				if (x + 1 <= m - 1 && visit[x+1][y] == 1) {
					round++;
					continue;
				}
				break;
			}
			case 2: {			// 2向量到了已经被访问的地方后，就要转变方向，一层一层往里缩
				if (y - 1 >= 0 && visit[x][y - 1] == 1) {
					round++;
					continue;
				}
				break;
			}
			case 3: {			// 3向量到了已经被访问的地方后，就要转变方向，一层一层往里缩
				if (x - 1 >= 0 && visit[x - 1][y] == 1) {
					round++;
					continue;
				}
				break;
			}
			}
		}
		return res;
	}
}
```