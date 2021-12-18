#pragma once
#include<vector>
namespace FirstMissingPositive {
  // segregates non-negative numbers to right side of array
  int segregate(std::vector<int>&A){
    int n = A.size();
    int j = n - 1, i = 0;
    while (i <= j){
      if (A[i] <= 0){
        std::swap(A[i], A[j]); // swap values at A[i] and A[j]
        j = j - 1;
      }
      else
        i = i + 1;
    }
    return i;
  }
	int FirstMissingPositive(std::vector<int>& nums) {
    std::vector<int>A = nums;
    int n = nums.size();
    int N = segregate(A);
    for (int k = 0; k <= N - 1; k++){
      if (abs(A[k]) - 1 < N)
        A[abs(A[k]) - 1] = -abs(A[abs(A[k]) - 1]);
  }
    for (int k = 0; k <= N - 1; k++) {
      if (A[k] > 0)
        return k + 1;
    }
     return N + 1;

	}
}
