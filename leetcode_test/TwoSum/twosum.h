#pragma once
#include<map>
#include<algorithm>
std::pair<int, int> TwoSum(std::vector<int>nums, int target) {
	std::pair<int, int>result;
	std::map<int, int>map_nums;
	result.first = 10000;
	result.second = 10000;
	map_nums.insert(std::pair<int, int>(nums.at(0),0));
	map_nums.insert(std::pair<int, int>(100000, 999));
	for (int i = 1; i < nums.size(); i++) {
		int temp = nums.at(i);
		int temp2 = target - temp;
		if (map_nums.find(temp2) != map_nums.end()){
			result.first = i;
			result.second = map_nums[temp2];
			return result;
		}
		else
			map_nums.insert(std::pair<int, int>(nums.at(i), i));
	}
	return result;
}