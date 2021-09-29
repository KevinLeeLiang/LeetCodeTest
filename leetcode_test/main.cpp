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

/*
9.Palindrome Number
题⽬
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the
same backward as forward.
Example 1:
Input: 121
Output: true
Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.
Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
#include"PalindromeNumber/PalindromeNumber.h"
void PalindromeNumberTest() {
	int test = -121;
	if (PalindromeNumber1(test)) {
		std::cout << "true" << std::endl;
	}
	else
		std::cout << "false" << std::endl;
	if (PalindromeNumber2(test)) {
		std::cout << "true" << std::endl;
	}
	else
		std::cout << "false" << std::endl;
}

/*
11.Container With Most Water
题⽬
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n
vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of
water (blue section) the container can contain is 49.
Example 1:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
#include "ContainerWithMostWater/ContainerWithMostWater.h"
void ContainerWithMostWaterTest() {
	std::vector<int>test = { 1,8,6,2,5,4,8,3,7 };
	std::cout << ContainerWithMostWater(test) << std::endl;
}

#include "RomanToInteger/RomanToInteger.h"
void RomanToIntegerTest() {
	std::string s = "MCMXCIV";
	std::cout << RomanToInteger(s) << std::endl;
}
/*
15. 3Sum
题⽬
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find
all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
 [-1, 0, 1],
 [-1, -1, 2]
]
*/
#include "3Sum/3Sum.h"
void ThreeSumTest() {
	std::vector<int>test = { -1, 0, 1, 2, -1, -4 };
	std::vector<std::vector<int>>res = ThreeSum(test);
	if (res.size() == 0){
		std::cout << "No Solution" << std::endl;
		return;
	}
	else {
		for (int i = 0; i < res.size(); i++) {
			std::cout << "[";
			for (int j = 0; j < res.at(i).size(); j++) {
				if (j == res.at(i).size() - 1) {
					std::cout << res.at(i).at(j);
				}
				else
					std::cout << res.at(i).at(j) << ",";
			}
			std::cout << "]" << std::endl;
		}
	}
}

/*
16.3Sum Closest
题⽬
Given an array nums of n integers and an integer target, find three integers in nums such that the
sum is closest to target. Return the sum of the three integers. You may assume that each input
would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
题⽬⼤意
给定⼀个数组，要求在这个数组中找出 3 个数之和离 target 最近。
解题思路
这⼀题看似和第 15 题和第 18 题很像，都是求 3 或者 4 个数之和的问题，但是这⼀题的做法和 15，18
题完全不同。
这⼀题的解法是⽤两个指针夹逼的⽅法。先对数组进⾏排序，i 从头开始往后⾯扫。这⾥同样需要注意
数组中存在多个重复数字的问题。具体处理⽅法很多，可以⽤ map 计数去重。这⾥笔者简单的处理，i
在循环的时候和前⼀个数进⾏⽐较，如果相等，i 继续往后移，直到移到下⼀个和前⼀个数字不同的位
置。j，k 两个指针开始⼀前⼀后夹逼。j 为 i 的下⼀个数字，k 为数组最后⼀个数字，由于经过排序，所
以 k 的数字最⼤。j 往后移动，k 往前移动，逐渐夹逼出最接近 target 的值。
*/
#include"3SumClosest/3SumClosest.h"
void ThreeSumClosestTest() {
	std::vector<int>test = { -1, 2, 1, -4 };
	int target = 1;
	std::vector<int>res = ThreeSumClosest(test, target);
	if (res.size() == 0) {
		std::cout << "No Solution" << std::endl;
		return ;
	}
	else {
		std::cout << "[";
		for (int i = 0; i < res.size(); i++) {
			if (i == res.size() - 1) {
				std::cout << res.at(i);
			}
			else
				std::cout << res.at(i) << ",";
		}
		std::cout << "]" << std::endl;	
	}
}

void LetterCombinationsOfAPhoneNumber() {

}

int main() {
	std::cout << "Hello World!" << std::endl;
	//TwoSumTest();
	//AddTwoNumbersTest();
	//LongestSubstringWithoutRepeatingCharactersTest();
	//MedianOfTwoSortedArrays();
	//ReverseIntergerTest();
	//PalindromeNumberTest();
	//ContainerWithMostWaterTest();
	//RomanToIntegerTest();
	//ThreeSumTest();
	ThreeSumClosestTest();
	return 0;			
}