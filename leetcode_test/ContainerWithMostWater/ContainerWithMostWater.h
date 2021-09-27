#pragma once
#include<vector>
int ContainerWithMostWater(std::vector<int>test) {
	int max = 0;
	int start = 0, end = test.size() - 1;
	int maxtemp = max;
	while (start != end) {
		maxtemp = std::min(test.at(start), test.at(end)) * (end - start);
		if (max < maxtemp)
			max = maxtemp;
		if (test.at(start) > test.at(end)) {
			end -= 1;
		}
		else
			start += 1;
	}
	return max;
}