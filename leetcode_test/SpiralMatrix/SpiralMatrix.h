#pragma once
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