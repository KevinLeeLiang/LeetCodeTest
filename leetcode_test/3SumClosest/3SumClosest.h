#pragma once
std::vector<int> ThreeSumClosest(std::vector<int>test, int target) {
	std::vector<int>res;
	std::sort(test.begin(), test.end());
	int count = test.size();
	int max = INT_MAX;
	for (int i = 0; i < count; i++) {
		if (i + 1 < size(test) && test[i] == test[i + 1]) {
			continue;
		}
		if (i == 0 || i > 0 && test[i] != test[i - 1]) {
			int low = i + 1;
			int high = count - 1;
			int sum = test.at(i);
			int low_tmp, high_tmp;
			while (low < high) {
				low_tmp = low;
				high_tmp = high;
				const auto &total = test.at(low) + test.at(high) + sum;
				if (total < target) {
					++low;
				}
				else if (total > target) {
					--high;
				}
				else {
					return res = { test.at(low), test.at(high), sum };
				}
				if (fabs(total - target) < max) {
					max = fabs(total - target);
					res = { test.at(low_tmp), test.at(high_tmp), sum };
				}
			}
		}
	}
	return res;
}