#pragma once
#include<vector>
namespace CombinationSum {
  void BackTrack(std::vector<std::vector<int>>&res, std::vector<int>candidate, std::vector<int>& nums, int target, int start) {
    if (target < 0)
      return;
    else {
      if (target == 0)
        res.push_back(candidate);
      else {
        for (int i = start; i < nums.size(); i++) {
          candidate.push_back(nums[i]);
          BackTrack(res, candidate, nums, target - nums[i], i);
          // not i + 1 because we can reuse same element         
          candidate.erase(candidate.begin()+candidate.size() - 1);
        }
      }
    }
  }
	std::vector<std::vector<int>> CombinationSum(std::vector<int>& nums, int target) {
		std::vector<std::vector<int>>res;
    std::vector<int>cur;
		BackTrack(res, cur, nums, target, 0);
		return res;
	}
}