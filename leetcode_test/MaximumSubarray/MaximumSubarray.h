#pragma once
#include<vector>
namespace MaximumSubarray {
	int MaximumSubarray(std::vector<int>input, int &index){
		int res;
		if (input.size() == 0){
			return 0;
		}
		if (input.size() == 1){
			return input.at(0);
		}
		std::vector<int>dp;
		dp.resize(input.size());
		res = input.at(index);
		int tmp = index;
		for (size_t i = 1; i < input.size(); i++){
			if (dp[i - 1] > 0) {
				dp.at(i) = input.at(i) + dp.at(i - 1);
			}
			else {
				dp.at(i) = input.at(i);
			}
			res = std::max(res, dp.at(i));
			index = res > dp.at(i) ? tmp: i;
			tmp = index;
		}
		for (size_t i = index; i >=0; i--){
			if (dp[i] > 0){
				std::cout << input.at(i) << " ";
			}
			else {
				std::cout << std::endl;
				break;
			}
		}
		return res;
	}
}