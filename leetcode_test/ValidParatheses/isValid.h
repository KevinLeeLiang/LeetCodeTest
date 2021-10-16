#pragma once
#include <string>
bool isValid(std::string s) {
	bool res = false;
	if (s.size() == 0) {
		res = true;
	}
	std::vector<char>stack;
	for (size_t i = 0; i < s.size(); i++){
		char v = s.at(i);
		if (s.at(i) == '[' || s.at(i) == '{' || s.at(i) == '(') {
			stack.push_back(s.at(i));
		}else if((v == ']' && stack.size() > 0 && stack.at(stack.size()-1) == '[') ||
			(v == '}' && stack.size() > 0 && stack.at(stack.size() - 1) == '{')||
			(v == ')' && stack.size() > 0 && stack.at(stack.size() - 1) == '(')){
			stack.pop_back();
		}
		else {
			res = false;
		}
		
	}
	if (stack.size() == 0) {
		res = true;
	}
	return res;
}