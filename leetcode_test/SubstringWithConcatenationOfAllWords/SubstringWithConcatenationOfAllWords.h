#pragma once
#include<vector>
#include<iostream>
namespace SubstringWithConcatenationOfAllWords {
	void print_vector(std::vector<int> v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
      if (v.size() > 1) {
        if (i != v.size() - 1)
          std::cout << v[i] << ", ";
        else
          std::cout << v[i];
      }
      else
        std::cout << v[i];
    }
    std::cout << "]" << std::endl;
	}
  bool ok(std::string s, std::unordered_map <std::string, int> wordCnt, int n) {
    std::string temp = "";
    for (int i = 0; i < n; i++) {
      temp += s[i];
    }
    for (int i = n; i < s.size(); i++) {
      if (temp.size() % n == 0) {
        if (wordCnt.find(temp) == wordCnt.end())return false;
        else {
          if (wordCnt[temp] == 1) {
            wordCnt.erase(temp);
            temp = "";
          }
          else {
            wordCnt[temp]--;
            temp = "";
          }
        }
      }
      temp += s[i];
    }
    if (wordCnt.find(temp) == wordCnt.end())return false;
    else {
      if (wordCnt[temp] == 1) {
        wordCnt.erase(temp);
        temp = "";
      }
      else {
        wordCnt[temp]--;
        temp = "";
      }
    }
    return wordCnt.size() == 0;
  }
  std::vector<int> SubstringWithConcatenationOfAllWords(std::string a, std::vector<std::string>& b) {
    if (a.size() == 0 || b.size() == 0)return {};
    std::unordered_map <std::string, int> wordCnt;
    for (int i = 0; i < b.size(); i++)wordCnt[b[i]]++;
    std::vector <int> ans;
    int window = b.size() * b[0].size();
    std::string temp = "";
    for (int i = 0; i < window; i++)temp += a[i];
    for (int i = window; i < a.size(); i++) {
      if (temp.size() % window == 0 && ok(temp, wordCnt, b[0].size())) {
        ans.push_back(i - window);
      }
      temp += a[i];
      if (temp.size() > window)
        temp.erase(0, 1);
    }
    if (temp.size() % window == 0 && ok(temp, wordCnt, b[0].size()))
      ans.push_back(a.size() - window);
    return ans;
  }
}
