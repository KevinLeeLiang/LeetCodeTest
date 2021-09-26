#include <iostream>
#include<vector>

// Two Sum
/* Given an array of integers, return indices of the two numbers such that they add up to a specific
target.
You may assume that each input would have exactly one solution, and you may not use the same
element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1]
*/
#include "TwoSum/twosum.h"
void TwoSumTest() {
	std::pair<int, int>result;
	std::vector<int>nums;
	nums.push_back(11);
	nums.push_back(2);
	nums.push_back(15);
	nums.push_back(7);
	int target = 9;
	result = TwoSum(nums, target);
	std::cout << result.first << " " << result.second << " " << nums.at(result.first) + nums.at(result.second) << std::endl;
}

/*Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are
stored in reverse order and each of their nodes contain a single digit. Add the two numbers and
return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807
*/

#include"AddTwoNumbers/addtwonumbers.h"
void AddTwoNumbersTest() {
	int ptr_test1[3] = { 2,4,3 };
	link* p = setElemForLink(3, ptr_test1);

	int ptr_test2[3] = { 5,6,4 };
	link* q = setElemForLink(3, ptr_test2);
	link* result = AddTwoNumbers(p, q);
	while (result) {
		std::cout << result->elem << "->";
		result = result->next;
	}
	std::cout << std::endl;
}
/*
3. Longest Substring Without Repeating Characters
题⽬
Given a string, find the length of the longest substring without repeating characters.

Example 1:
	Input: "abcabcbb"
	Output: 3
	Explanation: The answer is "abc", with the length of 3.

Example 2:
	Input: "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.

Example 3:
	Input: "pwwkew"
	Output: 3
	Explanation: The answer is "wke", with the length of 3.
	Note that the answer must be a substring, "pwke" is a subsequence
	and not a substring
*/
#include"LongestSubstringWithoutRepeatingCharacters/LongestSubstringWithoutRepeatingCharacters.h"
void LongestSubstringWithoutRepeatingCharactersTest() {
	std::string test = "abcabcab";
	std::cout << LongestSubstringWithoutRepeatingCharactersByBitmapMethod(test) << std::endl;
	std::cout << LongestSubstringWithoutRepeatingCharactersBySlidingWindowMethod(test) << std::endl;
}

/*
4. Median of Two Sorted Arrays
题⽬
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
	nums1 = [1, 3]
	nums2 = [2]
	The median is 2.0

Example 2:
	nums1 = [1, 2]
	nums2 = [3, 4]
	The median is (2 + 3)/2 = 2.5
*/
#include "MedianOfTwoSortedArrays/MedianOfTwoSortedArrays.h"
void MedianOfTwoSortedArrays() {
	std::vector<int>nums1 = { 1,3 };
	std::vector<int>nums2 = { 2,4 };
	float result = FindMedianSortedArrays(nums1, nums2);
	std::cout << "nums1: {";
	for (int i = 0; i < nums1.size(); i++) {
		std::cout << nums1.at(i);
		if (i != nums1.size() - 1)
			std::cout << ",";
	}
	std::cout << "}" << std::endl;
	std::cout << "nums2: {";
	for (int i = 0; i < nums2.size(); i++) {
		std::cout << nums2.at(i);
		if (i != nums2.size() - 1)
			std::cout << ",";
	}
	std::cout << "}" << std::endl;
	std::cout << "result:" << result << std::endl;
}

/*
7.Reverse Interger
题⽬
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
	Input: 123
	Output: 321

Example 2:
	Input: -123
	Output: -321

Example 3:
	Input: 120
	Output: 21

Note: Assume we are dealing with an environment which could only store integers within the 32-
bit signed integer range: [−2^31, 2^31 − 1]. For the purpose of this problem, assume that your
function returns 0 when the reversed integer overflows.
*/
#include"ReverseInterger/ReverseInterger.h"
void ReverseIntergerTest() {
	long long test = 520;
	std::cout << ReverseInterger(test) << std::endl;
}

int main() {
	std::cout << "Hello World!" << std::endl;
	//TwoSumTest();
	//AddTwoNumbersTest();
	//LongestSubstringWithoutRepeatingCharactersTest();
	//MedianOfTwoSortedArrays();
	ReverseIntergerTest();
	return 0;			
}