# 49. Group Anagrams
## 题⽬
Given an array of strings, group anagrams together.
### Example:
```
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
 ["ate","eat","tea"],
 ["nat","tan"],
 ["bat"]
]
```
### Note:
* All inputs will be in lowercase.
* The order of your output does not matter.

## 题⽬⼤意
给出⼀个字符串数组，要求对字符串数组⾥⾯有 Anagrams 关系的字符串进⾏分组。Anagrams 关系是指两个字符串的字符完全相同，顺序不同，两者是由排列组合组成。
## 解题思路
这道题可以将每个字符串都排序，排序完成以后，相同 Anagrams 的字符串必然排序结果⼀样。把排序以后的字符串当做 key 存⼊到 map 中。遍历数组以后，就能得到⼀个 map，key 是排序以后的字符串，value 对应的是这个排序字符串以后的 Anagrams 字符串集合。最后再将这些 value 对应的字符串数组输出即可。
## 代码
```c++
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
		// 将字符串进行排序
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
```

