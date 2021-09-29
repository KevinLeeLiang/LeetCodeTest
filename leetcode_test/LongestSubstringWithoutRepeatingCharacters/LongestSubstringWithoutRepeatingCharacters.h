#pragma once
/**
 * @brief				- 位图法求最大互不相同子串的size
 * @param test 	- {string} 待求解字符串
 * @return 			- {int} 最大互不相同子串的size
*/
int LongestSubstringWithoutRepeatingCharactersByBitmapMethod(std::string test) {
	if (test.size() == 0)
		return 0;
	uint8_t size = test.size();
	uint8_t bitmap[256] = {0};
	uint8_t left = 0, right = 0;
	int result = 0;
	const char* ptest = test.c_str();
	while (left < size) {
		int	i = (int)ptest[right];
		int j = (int)ptest[left];
		if (right < size && bitmap[i] == 0) {
			bitmap[i] = 1;
			right++;
		}
		else {
			bitmap[j] = 0;
			left++;
		}
		result = std::max(result, right - left);
	}
	return result;
}

/**
 * @brief				- 滑窗法求最大互不相同子串的size
 * @param test 	- {string} 待求解字符串
 * @return 			- {int} 最大互不相同子串的size
*/
int	LongestSubstringWithoutRepeatingCharactersBySlidingWindowMethod(std::string test) {
	if (test.size() == 0){
		return 0;
	}
	int result = 0;
	int left = 0, right = -1;
	const char* ptest = test.c_str();
	int freq[256] = { 0 };
	while (left < test.size()) {
		if (right + 1 < test.size() && freq[int(ptest[right + 1]) - (int)'a'] == 0) {
			freq[int(ptest[right + 1]) - (int)'a']++;
			right++;
		}
		else {
			freq[int(ptest[left]) - (int)'a']++;
			left++;
		}
		result = std::max(result, right - left + 1);
	}
	return result;
}