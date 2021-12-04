#pragma once
#include<vector>
namespace SearchInsertPosition {
	int SearchInsertPosition(std::vector<int>& arr, int& tar) {
    // Traverse the array
    // Lower and upper bounds
    int n = arr.size();
    int start = 0;  
    int end = n - 1;

    // Traverse the search space
    while (start <= end) {
      int mid = (start + end) / 2;

      // If K is found
      if (arr[mid] == tar)
        return mid;

      else if (arr[mid] < tar)
        start = mid + 1;

      else
        end = mid - 1;
    }

    // Return insert position
    return end + 1;
	}
}
