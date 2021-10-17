#pragma once
#include <string>
#include<vector>
void FindGenerateParantheses(int lindex, int rindex, std::string str, std::vector<std::string>& res) {
	if (lindex == 0 && rindex == 0){
		res.push_back(str);
		return;
	}
	else {
		if (lindex > 0)
			FindGenerateParantheses(lindex - 1, rindex, str + "(", res);
		if (rindex > 0 && lindex < rindex) {
			FindGenerateParantheses(lindex, rindex - 1, str + ")", res);
		}
	}
}
std::vector<std::string> GenerateParanetheses(int n) {
	std::vector<std::string> res = {};
	if (n == 0)
		return res;
	else {
		FindGenerateParantheses(n, n, "", res);
		return res;
	}
}
