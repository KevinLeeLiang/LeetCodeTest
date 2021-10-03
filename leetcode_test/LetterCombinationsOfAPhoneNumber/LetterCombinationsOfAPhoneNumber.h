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
		//cout << index << " : " << p << endl; //����
		//index���Կ������Ĳ���
		if (index == digits.size())   //digits��ǰ������index����digits��ĩβ��ʼ���ݣ���ʾ�Ѿ����ײ�
		{
			//����һ�ֽ���������ص���һ��
			res1.push_back(p);
			return;
		}

		char c = digits[index];
		std::string letters = record[c - '0'];
		for (int i = 0; i < letters.size(); i++)  //��ǰ���ַ��ĸ���
		{
			//cout << "digits[" << index << "] = " << digits[index] << " , use " << record[digits[index] - '0'][i] << endl;
			//ע��:digits�ڴ洢����string���ͣ�ȡ������Ҳ���ַ������磺'2'����ȡvector�±꽫��ASCII�룬����Ӧ��ת��Ϊ����
			AddLetters(digits, index + 1, p + letters[i]);
		}
		return;
	};
};
