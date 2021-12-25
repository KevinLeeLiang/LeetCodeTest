#pragma once
namespace Permutations {
  void Permutate(std::vector<int>& nums, int i, int n, std::vector<std::vector<int>>& res) {
    // base condition
    if (i == n - 1){
      res.push_back(nums);
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
      // swap character at index `i` with the current character
      std::swap(nums[i], nums[j]);        // STL `swap()` used

      // recur for substring `str[i+1, n-1]`
      Permutate(nums, i + 1, n, res);

      // backtrack (restore the string to its original state)
      std::swap(nums[i], nums[j]);
    }
  }

	std::vector<std::vector<int>> Permutations(std::vector<int>& nums) {
		std::vector<std::vector<int>>res;
    // One be one move all characters at
    // the beginning of out (or result)
    Permutate(nums, 0, nums.size(), res);
    return res;
	}
}