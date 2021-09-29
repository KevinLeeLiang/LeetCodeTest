#pragma once
std::vector<std::vector<int>> ThreeSum(std::vector<int>test) {
	std::vector<std::vector<int>>res;
	std::sort(test.begin(), test.end());
	int count = test.size();
	for (int i = 0; i < count; i++) {
		if (i == 0 || i > 0 && test[i] != test[i - 1]) {
			int low = i + 1;
			int high = count - 1;
			int sum = -test.at(i);
			while (low < high) {
				if (test.at(low) + test.at(high) == sum){
					res.push_back(std::vector<int>({ test.at(i), test.at(low), test.at(high) }));
					while (low < high && test.at(low) == test.at(low + 1)) low++;
					while (low < high && test.at(high) == test.at(high - 1)) high--;
					low++;
					high--;
				}
				else if(test.at(low) + test.at(high) < sum) low++;
				else high--;
			}
		}
	}
	return res;
}