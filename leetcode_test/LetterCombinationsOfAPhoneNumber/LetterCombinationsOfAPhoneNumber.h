#pragma once
class LetterCombinationOfAPhoneNumber {
public:
	LetterCombinationOfAPhoneNumber() {
		record = { " ", "", "abc", "def", "ghi",
								 "jkl", "mno", "pqrs", "tuv", "wxyz" };
	};
	std::vector<std::string>LetterCombinations(std::string digits) {
		if (digits == "") {
			return res1;
		}
		else {
			AddLetters(digits, 0, "");
			return res1;
		}
	};
private:
	std::vector<std::string> record;
	std::vector<std::string> res1;
	void AddLetters(std::string digits, int index, std::string p)
	{
		//cout << index << " : " << p << endl; //调试
		//index可以看做树的层数
		if (index == digits.size())   //digits当前的索引index到达digits的末尾开始回溯，表示已经到底部
		{
			//保存一种结果，并返回到上一层
			res1.push_back(p);
			return;
		}

		char c = digits[index];
		std::string letters = record[c - '0'];
		for (int i = 0; i < letters.size(); i++)  //当前层字符的个数
		{
			//cout << "digits[" << index << "] = " << digits[index] << " , use " << record[digits[index] - '0'][i] << endl;
			//注意:digits内存储的是string类型，取出来的也是字符，比如：'2'对其取vector下标将是ASCII码，所以应该转化为数字
			AddLetters(digits, index + 1, p + letters[i]);
		}
		return;
	};
};
