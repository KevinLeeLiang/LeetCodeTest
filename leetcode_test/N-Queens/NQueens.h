#pragma once
#include<string>
#include<vector>
#include<memory>
namespace NQueens {
	// ��ӡ����
	void display(int** queen, int n)
	{
		static int k;  // ��¼�����Ŀ
		printf("\n %d \n", ++k);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf(" %c", (queen[i][j]) ? ('Q') : ('.'));
			printf("\n");
		}
	}
	int Check(int** queen, int x, int y, int n)
	{   //���л�Խ����Ѿ������˷���1, ���򷵻�0
		int i, k, l;
		for (i = 0; i < n; i++) if (queen[i][y] || queen[x][i]) return 1;  //����
		for (k = x, l = y; k < n && l < n; k++, l++) if (queen[k][l]) return 1;
		for (k = x, l = y; k >= 0 && l < n; k--, l++) if (queen[k][l]) return 1;
		for (k = x, l = y; k >= 0 && l >= 0; k--, l--) if (queen[k][l]) return 1;
		for (k = x, l = y; k < n && l >= 0; k++, l--) if (queen[k][l]) return 1;

		return 0;
	}
	// �ݹ����
	void placeQueen(int** queen, int k, int n)
	{
		if (k == n) {  //n����������ɣ���ӡһ�ν��
			display(queen, n);
			return;
		}
		int flag, i;
		for (i = 0; i < n; i++)
		{
			flag = Check(queen, k, i, n);  //��鵱ǰλ���ܷ���ûʺ�
			if (!flag)
			{
				queen[k][i] = 1;  // ռλ
				placeQueen(queen, k + 1, n);    //�ݹ������һ��
				queen[k][i] = 0;  // ռλȡ��
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