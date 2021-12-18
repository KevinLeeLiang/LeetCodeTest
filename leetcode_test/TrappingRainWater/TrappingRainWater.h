#pragma once

namespace TrappingRainWater {
	int TrappingRainWaterMethod1(int arr[], int n) {
    // To store the maximum water
    // that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++) {

      // Find the maximum element on its left
      int left = arr[i];
      for (int j = 0; j < i; j++)
        left = std::max(left, arr[j]);

      // Find the maximum element on its right  
      int right = arr[i];
      for (int j = i + 1; j < n; j++)
        right = std::max(right, arr[j]);

      // Update the maximum water   
      res = res + (std::min(left, right) - arr[i]);
    }

    return res;
	}
  int TrappingRainWaterMethod2(int arr[], int n) {
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    std::vector<int>left, right;
    left.resize(n);
    right.resize(n);
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
  

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
      left[i] = std::max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
      right[i] = std::max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
      water += std::min(left[i], right[i]) - arr[i];

    return water;
  }
}