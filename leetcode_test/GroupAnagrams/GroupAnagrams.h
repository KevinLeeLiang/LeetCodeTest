#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
namespace GroupAnagrams {
	std::string sort_string(std::string s) {
		std::vector<char> temp;
		for (int i = 0; s[i] != '\0'; ++i) {
			temp.push_back(s[i]);
		}
		std::sort(temp.begin(), temp.end());
		return std::string(temp.data());
	}
	std::map<std::string, std::vector<std::string>> GroupAnagrams(std::vector<std::string> input) {
		std::set<std::string> st;
		std::map<std::string, std::vector<std::string>>res;
		// ½«×Ö·û´®½øÐÐÅÅÐò
		for (size_t i = 0; i < input.size(); i++){
			std::string s = input.at(i);
			std::string s_tmp = sort_string(s);
			if (st.count(s_tmp)) {
				res[s_tmp].push_back(s);
				st.insert(st.end(), s);
			}
			else {
				res.insert(std::map<std::string, std::vector<std::string>>::value_type(s_tmp, { s }));
				st.insert(st.end(), s_tmp);
			}
		}
		return res;
	}
}