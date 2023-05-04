#pragma once
#include<string>
#include<vector>
#include<memory>
namespace NQueens {
	// 打印函数
	void display(int** queen, int n)
	{
		static int k;  // 记录结果数目
		printf("\n %d \n", ++k);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf(" %c", (queen[i][j]) ? ('Q') : ('.'));
			printf("\n");
		}
	}
	int Check(int** queen, int x, int y, int n)
	{   //行列或对角线已经有人了返回1, 否则返回0
		int i, k, l;
		for (i = 0; i < n; i++) if (queen[i][y] || queen[x][i]) return 1;  //行列
		for (k = x, l = y; k < n && l < n; k++, l++) if (queen[k][l]) return 1;
		for (k = x, l = y; k >= 0 && l < n; k--, l++) if (queen[k][l]) return 1;
		for (k = x, l = y; k >= 0 && l >= 0; k--, l--) if (queen[k][l]) return 1;
		for (k = x, l = y; k < n && l >= 0; k++, l--) if (queen[k][l]) return 1;

		return 0;
	}
	// 递归遍历
	void placeQueen(int** queen, int k, int n)
	{
		if (k == n) {  //n个都放置完成，打印一次结果
			display(queen, n);
			return;
		}
		int flag, i;
		for (i = 0; i < n; i++)
		{
			flag = Check(queen, k, i, n);  //检查当前位置能否放置皇后
			if (!flag)
			{
				queen[k][i] = 1;  // 占位
				placeQueen(queen, k + 1, n);    //递归进入下一行
				queen[k][i] = 0;  // 占位取消
			}
		}
	}

	void NQueens(int n) {
		int** queen = (int **)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++)
		{
			queen[i] = (int*)malloc(sizeof(int) * n);
			for (int j = 0; j < n; j++) queen[i][j] = 0;
		}
		placeQueen(queen, 0, n);
	}
}