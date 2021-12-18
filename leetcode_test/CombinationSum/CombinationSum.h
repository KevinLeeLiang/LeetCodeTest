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

  void iter(std::vector<int>&num, int target, int beg, std::vector<int>tmp, std::vector<std::vector<int>>&ret) {
    if (target == 0) {
      ret.push_back(tmp);
      return;
    }
    if (target > 0) {
      for (int i = beg; i < num.size(); ++i) {
        if (i == beg || num[i] != num[i - 1]) {
          tmp.push_back(num[i]);
          iter(num, target - num[i], i + 1, tmp, ret);
          tmp.pop_back();
        }
      }
    }

  }

  std::vector<std::vector<int>>CombinationSum2(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>>ret;
    if (target <= 0)return ret;
    if (nums.size() == 0) return ret;
    std::sort(nums.begin(), nums.end());
    std::vector<int>tmp;
    iter(nums, target, 0, tmp, ret);
    return ret;
  }

}