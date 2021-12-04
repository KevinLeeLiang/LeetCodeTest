#pragma once
#include<vector>
namespace ValidSudoku {
	bool ValidSudoku(std::vector<std::vector<char> > sudoku) {
    int row = 0, col = 0, i = 0, block = 0;
    int count[9];
    for (row = 0; row < 9; ++row) {
      memset(count, 0, 9 * sizeof(int));
      for (col = 0; col < 9; ++col) {
        if (sudoku[row][col] != '.')
          ++count[sudoku[row][col] - '1'];
      }
      for (i = 0; i < 9; ++i)
        if (count[i] > 1)
          return false;
    }
    for (col = 0; col < 9; ++col) {
      memset(count, 0, 9 * sizeof(int));
      for (row = 0; row < 9; ++row) {
        if (sudoku[row][col] != '.')
          ++count[sudoku[row][col] - '1'];
      }
      for (i = 0; i < 9; ++i)
        if (count[i] > 1)
          return false;
    }
    int block_row = 0, block_col = 0;
    for (block = 0; block < 9; ++block) {
      block_row = (block / 3) * 3, block_col = (block % 3) * 3;
      memset(count, 0, 9 * sizeof(int));
      for (row = block_row; row < (block_row + 3); ++row)
        for (col = block_col; col < (block_col + 3); ++col)
          if (sudoku[row][col] != '.')
            ++count[sudoku[row][col] - '1'];
      for (i = 0; i < 9; ++i)
        if (count[i] > 1)
          return false;
    }
    return true;
	}
}
