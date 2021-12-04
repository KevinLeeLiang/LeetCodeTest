#pragma once
#include <vector>

namespace FindFirstandLastPositionofElementInSortedArray {
	int lower_bound(std::vector<int>& nums, int target) {
		const int N = nums.size();
		int l = 0, r = N;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target) {
				r = mid;
			}
			else {
				l = mid + 1; 
			}
		}
		return l;
	}
	int upper_bound(std::vector<int>& nums, int target) {
		const int N = nums.size();
		int l = 0, r = N;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] <= target) {
				l = mid + 1;
			}
			else
				r = mid;
		}
		return l;
	}
	std::vector<int> FindFirstandLastPositionOfElementInSortedArray(std::vector<int>& nums, int target) {
		int low = lower_bound(nums, target);
		int high = upper_bound(nums, target);
		if (low == high)
		{
			return { -1, -1 };
		}
		else {
			return { low, high - 1 };
		}

	}
}
