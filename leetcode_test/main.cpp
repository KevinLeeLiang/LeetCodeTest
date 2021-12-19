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

/*
17. Letter Combinations of a Phone Number
题⽬
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does
not map to any letters
Example:
Input: "23"
	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you
want.
题⽬⼤意
给定⼀个仅包含数字 2-9 的字符串，返回所有它能表示的字⺟组合。给出数字到字⺟的映射如下（与电
话按键相同）。注意 1 不对应任何字⺟。
解题思路
DFS 递归深搜即可
*/ 
#include"LetterCombinationsOfAPhoneNumber/LetterCombinationsOfAPhoneNumber.h"
void LetterCombinationsOfAPhoneNumberTest() {
	LetterCombinationOfAPhoneNumber letter_combination;
	std::vector<std::string> result = letter_combination.LetterCombinations("23");
	std::cout << "{";
	for (size_t i = 0; i < result.size(); i++){
		if (i != result.size() - 1)
			std::cout << result.at(i) << ",";
		else
			std::cout << result.at(i);
	}
	std::cout << "}" << std::endl;
}


/*
18.4Sum
题⽬
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums
such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of
target.
Note:
The solution set must not contain duplicate quadruplets.
Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
 [-1, 0, 0, 1],
 [-2, -1, 1, 2],
 [-2, 0, 0, 2]
]
题⽬⼤意
给定⼀个数组，要求在这个数组中找出 4 个数之和为 0 的所有组合。
解题思路
⽤ map 提前计算好任意 3 个数字之和，保存起来，可以将时间复杂度降到 O(n^3)。这⼀题⽐较麻烦的
⼀点在于，最后输出解的时候，要求输出不重复的解。数组中同⼀个数字可能出现多次，同⼀个数字也
可能使⽤多次，但是最后输出解的时候，不能重复。例如 [-1，1，2, -2] 和 [2, -1, -2, 1]、[-2, 2, -1, 1] 这
3 个解是重复的，即使 -1, -2 可能出现 100 次，每次使⽤的 -1, -2 的数组下标都是不同的。
这⼀题是第 15 题的升级版，思路都是完全⼀致的。这⾥就需要去重和排序了。map 记录每个数字出现
的次数，然后对 map 的 key 数组进⾏排序，最后在这个排序以后的数组⾥⾯扫，找到另外 3 个数字能
和⾃⼰组成 0 的组合。
第 15 题和第 18 题的解法⼀致。
*/
#include "4Sum/4Sum.h"
void FourSumTest() {
	std::vector<int>test = { 1, 0, -1, 0, -2, 2 };
	FourSum four_sum;
	std::vector<std::vector<int>>res = four_sum.fourSum(test, 0);
	std::cout << "[ " << std::endl;
	for ( size_t i = 0; i < res.size(); i++){
		std::cout << "[ ";
		for (size_t j = 0; j < res.at(i).size(); j++){
			if (j < res.at(i).size() - 1){
				std::cout << res.at(i).at(j) << ", ";
			}
			else
				std::cout << res.at(i).at(j);
		}
		std::cout << " ]" << std::endl;
	}
	std::cout << "]" << std::endl;
	
}

/*
19. Remove Nth Node From End of List
题⽬
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
题⽬⼤意
删除链表中倒数第 n 个结点。
解题思路
这道题⽐较简单，先循环⼀次拿到链表的总⻓度，然后循环到要删除的结点的前⼀个结点开始删除操
作。需要注意的⼀个特例是，有可能要删除头结点，要单独处理。
这道题有⼀种特别简单的解法。设置 2 个指针，⼀个指针距离前⼀个指针 n 个距离。同时移动 2 个指
针，2 个指针都移动相同的距离。当⼀个指针移动到了终点，那么前⼀个指针就是倒数第 n 个节点了。
*/
#include "RemoveNthNodeFromEndOfListTest/RemoveNthNodeFromEndOfList.h"
void RemoveNthNodeFromEndOfListTest() {
	struct Node* head = NULL;
	head = create(head, 1);
	head = create(head, 2);
	head = create(head, 3);
	head = create(head, 4);
	head = create(head, 5);

	int n = 2;

	std::cout << "Linked list before modification: \n";
	display(head);

	head = removeNthFromEnd(head, 2);
	std::cout << "Linked list after modification: \n";
	display(head);
}
/**
20.Valid Parantheses
题⽬
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
Example 1:
	Input: "()"
	Output: true
Example 2:
	Input: "()[]{}"
	Output: true
Example 3:
	Input: "(]"
	Output: false
Example 4:
	Input: "([)]"
	Output: false
Example 5:
	Input: "{[]}"
	Output: true
题⽬⼤意
括号匹配问题。
解题思路
遇到左括号就进栈push，遇到右括号并且栈顶为与之对应的左括号，就把栈顶元素出栈。最后看栈⾥⾯
还有没有其他元素，如果为空，即匹配。
需要注意，空字符串是满⾜括号匹配的，即输出 true。
*/
#include "ValidParatheses/isValid.h"
void ValidParanthesesTest() {
	std::string s = "{[]}";
	bool res = isValid(s);
	std::string sres = "false";
	if (res)
		sres = "true";
	std::cout << "Input:" << s << std::endl;
	std::cout << "Output:" << sres << std::endl;
}

/*
21.Merge Two Sorted Lists
题⽬
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing
together the nodes of the first two lists.
Example:
	Input: 1->2->4, 1->3->4
	Output: 1->1->2->3->4->4
题⽬⼤意
合并 2 个有序链表
解题思路
按照题意做即可。
*/
#include"MergeTwoSortedLists/MergeTwoSortedLists.h"
void MergeTwoSortedListsTest() {
	MergeTwoSortedLists::ListNode* l1, *l1_input;
	l1 = new MergeTwoSortedLists::ListNode();
	l1->val = 1;
	l1->next = new MergeTwoSortedLists::ListNode();
	l1_input = l1;
	l1 = l1->next;
	l1->val = 2;
	l1->next = new MergeTwoSortedLists::ListNode();
	l1 = l1->next;
	l1->val = 4;
	l1->next = nullptr;
	MergeTwoSortedLists::ListNode* l2, *l2_input;
	l2 = new MergeTwoSortedLists::ListNode();
	l2->val = 1;
	l2->next = new MergeTwoSortedLists::ListNode();
	l2_input = l2;
	l2 = l2->next;
	l2->val = 3;
	l2->next = new MergeTwoSortedLists::ListNode();
	l2 = l2->next;
	l2->val = 4;
	l2->next = nullptr ;

	MergeTwoSortedLists::ListNode* ptr_res = MergeTwoLists(l1_input, l2_input);
	while (ptr_res != nullptr) {
		if (ptr_res->next == nullptr) {
			std::cout << ptr_res->val << std::endl;
			break;
		}
		else {
			std::cout << ptr_res->val << "->";
			ptr_res = ptr_res->next;
		}
	}
}

/*
题⽬
Given n pairs of parentheses, write a function to generate all combinations of well-formed
parentheses.
For example, given n = 3, a solution set is:
[
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
]
题⽬⼤意
给出 n 代表⽣成括号的对数，请你写出⼀个函数，使其能够⽣成所有可能的并且有效的括号组合。
解题思路
这道题乍⼀看需要判断括号是否匹配的问题，如果真的判断了，那时间复杂度就到 O(n * 2^n)了，
虽然也可以 AC，但是时间复杂度巨⾼。
这道题实际上不需要判断括号是否匹配的问题。因为在 DFS 回溯的过程中，会让 ( 和 ) 成对的
匹配上的。
*/
#include "GenerateParantheses/GeneratedParanetheses.h"
void GenerateParaenthesesTest() {
	std::vector<std::string>res = GenerateParanetheses(2);
	std::cout << "[" << std::endl;
	for (size_t i = 0; i < res.size(); i++){
		std::cout << res.at(i);
		if (i == res.size() - 1)
			std::cout << std::endl;
		else
			std::cout << "," << std::endl;
	}
	std::cout << "]" << std::endl;
}
/*
23. Merge k Sorted Lists
题⽬
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
 1->4->5,
 1->3->4,
 2->6
]
Output: 1->1->2->3->4->4->5->6
*/
#include"MergeKSortLists/MergeKSortedLists.h"
void MergeKSortedListsTest() {
	MergeKSortedLists::ListNode* l1, * l1_input;
	l1 = new MergeKSortedLists::ListNode();
	l1->val = 1;
	l1->next = new MergeKSortedLists::ListNode();
	l1_input = l1;
	l1 = l1->next;
	l1->val = 4;
	l1->next = new MergeKSortedLists::ListNode();
	l1 = l1->next;
	l1->val = 5;
	l1->next = nullptr;
	MergeKSortedLists::ListNode* l2, * l2_input;
	l2 = new MergeKSortedLists::ListNode();
	l2->val = 1;
	l2->next = new MergeKSortedLists::ListNode();
	l2_input = l2;
	l2 = l2->next;
	l2->val = 3;
	l2->next = new MergeKSortedLists::ListNode();
	l2 = l2->next;
	l2->val = 4;
	l2->next = nullptr;
	MergeKSortedLists::ListNode* l3, * l3_input;
	l3 = new MergeKSortedLists::ListNode();
	l3->val = 2;
	l3->next = new MergeKSortedLists::ListNode();
	l3_input = l3;
	l3 = l3->next;
	l3->val = 6;
	l3->next = nullptr;

	std::vector<MergeKSortedLists::ListNode*>vec_listnode;
	vec_listnode.push_back(l1_input);
	vec_listnode.push_back(l2_input);
	vec_listnode.push_back(l3_input);
	MergeKSortedLists::ListNode* ptr_res = MergeKSortedListsMethod4::MergeKLists(vec_listnode);
	while (ptr_res != nullptr) {
		if (ptr_res->next == nullptr) {
			std::cout << ptr_res->val << std::endl;
			break;
		}
		else {
			std::cout << ptr_res->val << "->";
			ptr_res = ptr_res->next;
		}
	}
}

/**
24.Swap Nodes in Pairs
题⽬
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.
Example:
 Given 1->2->3->4, you should return the list as 2->1->4->3.
题⽬⼤意
两两相邻的元素，翻转链表
*/
#include "SwapNodesInPairs/SwapNodesInPairs.h"
void SwapNodesInPairsTest() {
	SwapNodesInPairs::ListNode* l1, * l1_input;
	l1 = new SwapNodesInPairs::ListNode();
	l1->val = 1;
	l1->next = new SwapNodesInPairs::ListNode();
	l1_input = l1;
	l1 = l1->next;
	l1->val = 2;
	l1->next = new SwapNodesInPairs::ListNode();
	l1 = l1->next;
	l1->val = 3;
	l1->next = new SwapNodesInPairs::ListNode();
	l1 = l1->next;
	l1->val = 4;
	l1->next = NULL;
	//while (l1_input != nullptr) {
	//	if (l1_input->next == nullptr) {
	//		std::cout << l1_input->val << std::endl;
	//		break;
	//	}
	//	else {
	//		std::cout << l1_input->val << "->";
	//		l1_input = l1_input->next;
	//	}
	//}
	std::cout << "SwapNodesInPairsMethod1 result" << std::endl;
	SwapNodesInPairs::ListNode* ptr_res = SwapNodesInPairsMethod2::SwapInPairs2(l1_input);
	while (ptr_res != nullptr) {
		if (ptr_res->next == nullptr) {
			std::cout << ptr_res->val << std::endl;
			break;
		}
		else {
			std::cout << ptr_res->val << "->";
			ptr_res = ptr_res->next;
		}
	}

}
/*
25. Reverse Nodes in k-Group
题⽬
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of
nodes is not a multiple of k then left-out nodes in the end should remain as it is.
Example:
  Given this linked list: 1->2->3->4->5
  For k = 2, you should return: 2->1->4->3->5
  For k = 3, you should return: 3->2->1->4->5
Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
题⽬⼤意
按照每 K 个元素翻转的⽅式翻转链表。如果不满⾜ K 个元素的就不翻转。
解题思路
这⼀题是 problem 24 的加强版，problem 24 是两两相邻的元素，翻转链表。⽽ problem 25 要求的
是 k 个相邻的元素，翻转链表，problem 相当于是 k = 2 的特殊情况。
*/
#include "ReverseNodesInKGroup/ReverseNodesInKGroup.h"
void ReverseNodesInKGroupTest() {
	ReverseNodesInKGroup::ListNode* l1, * l1_input;
	l1 = new ReverseNodesInKGroup::ListNode();
	l1->val = 1;
	l1->next = new ReverseNodesInKGroup::ListNode();
	l1_input = l1;
	l1 = l1->next;
	l1->val = 2;
	l1->next = new ReverseNodesInKGroup::ListNode();
	l1 = l1->next;
	l1->val = 3;
	l1->next = new ReverseNodesInKGroup::ListNode();
	l1 = l1->next;
	l1->val = 4;
	l1->next = new ReverseNodesInKGroup::ListNode();
	l1 = l1->next;
	l1->val = 5;
	l1->next = NULL;

	ReverseNodesInKGroup::ListNode* ptr_res = ReverseNodesInKGroupMethod3::reverseKGroup(l1_input,3);
	while (ptr_res != nullptr) {
		if (ptr_res->next == nullptr) {
			std::cout << ptr_res->val << std::endl;
			break;
		}
		else {
			std::cout << ptr_res->val << "->";
			ptr_res = ptr_res->next;
		}
	}
}

/*
26. Remove Duplicates from Sorted Array
题⽬
Given a sorted array nums, remove the duplicates in-place such that each element appear only
once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in￾place with O(1) extra memory.
Example 1:
```
	Given nums = [1,1,2],
	Your function should return length = 2, with the first two elements of nums
	being 1 and 2 respectively.
	It doesn't matter what you leave beyond the returned length.
```
Example 2:
```
	Given nums = [0,0,1,1,1,2,2,3,3,4],
	Your function should return length = 5, with the first five elements of nums
	being modified to 0, 1, 2, 3, and 4 respectively.
	It doesn't matter what values are set beyond the returned length.
```
	Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array
will be known to the caller as well.
Internally you can think of this:
```
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);
// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len
elements.
for (int i = 0; i < len; i++) {
 print(nums[i]);
}
```
题⽬⼤意
给定⼀个有序数组 nums，对数组中的元素进⾏去重，使得原数组中的每个元素只有⼀个。最后返回去
重以后数组的⻓度值。
解题思路
这道题和第 27 题很像。这道题和第 283 题，第 27 题基本⼀致，283 题是删除 0，27 题是删除指定元
素，这⼀题是删除重复元素，实质是⼀样的。
这⾥数组的删除并不是真的删除，只是将删除的元素移动到数组后⾯的空间内，然后返回数组实际剩余
的元素个数，OJ 最终判断题⽬的时候会读取数组剩余个数的元素进⾏输出。
*/
#include"RemoveDuplicatesfromSortedArray/RemoveDuplicatedfromSortedArray.h"
void RemoveDuplicatesfromSortedArrayTest() {
	int arr[] = { 1, 2, 2, 3, 4, 4, 4, 5, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// removeDuplicates() returns new size of
	// array.
	n = RemoveDuplicatesfromSortedArray::RemoveDuplicates2(arr, n);

	// Print updated array
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}

/*
27. Remove Element
题⽬
Given an array nums and a value val, remove all instances of that value in-place and return the
new length.
Do not allocate extra space for another array, you must do this by modifying the input array inplace with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example 1:
	Given nums = [3,2,2,3], val = 3,
	Your function should return length = 2, with the first two elements of nums
	being 2.
	It doesn't matter what you leave beyond the returned length.
Example 2:
	Given nums = [0,1,2,2,3,0,4,2], val = 2,
	Your function should return length = 5, with the first five elements of nums
	containing 0, 1, 3, 0, and 4.
	Note that the order of those five elements can be arbitrary.
	It doesn't matter what values are set beyond the returned length.
Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array
will be known to the caller as well.
Internally you can think of this:
	// nums is passed in by reference. (i.e., without making a copy)
	int len = removeElement(nums, val);
	// any modification to nums in your function would be known by the caller.
	// using the length returned by your function, it prints the first len
	elements.
	for (int i = 0; i < len; i++) {
		print(nums[i]);
	}
题⽬⼤意
给定⼀个数组 nums 和⼀个数值 val，将数组中所有等于 val 的元素删除，并返回剩余的元素个数。
解题思路
这道题和第 283 题很像。这道题和第 283 题基本⼀致，283 题是删除 0，这⼀题是给定的⼀个 val，实
质是⼀样的。
这⾥数组的删除并不是真的删除，只是将删除的元素移动到数组后⾯的空间内，然后返回数组实际剩余
的元素个数，OJ 最终判断题⽬的时候会读取数组剩余个数的元素进⾏输出。
*/
#include "RemoveElement/RemoveElement.h"
void RemoveElementTest() {
	int arr[] = { 0,1,2,2,3,0,4,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int val = 2;
	// RemoveElement()return new size of array
	n = RemoveElement::RemoveElement(arr, n, val);
	for (size_t i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

/**
28. Implement strStr()
题⽬
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of
haystack.
Example 1:
	Input: haystack = "hello", needle = "ll"
	Output: 2
Example 2:
	Input: haystack = "aaaaa", needle = "bba"
	Output: -1
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an
interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is
consistent to C's strstr() and Java's indexOf().
题⽬⼤意
实现⼀个查找 substring 的函数。如果在⺟串中找到了⼦串，返回⼦串在⺟串中出现的下标，如果没有
找到，返回 -1，如果⼦串是空串，则返回 0 。
*/
#include"ImplementsStr/ImplementsStr.h"
void ImplementsStrTest() {
	std::string hystack = "hello";
	std::string needle = "ll";
	int res = ImplementsStr::ImplementsStr(hystack, needle);
	std::cout << res << std::endl;
}

/*
29. Divide Two Integers
题⽬
Given two integers dividend and divisor , divide two integers without using multiplication,
division and mod operator.
Return the quotient after dividing dividend by divisor .
The integer division should truncate toward zero.
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-
bit signed integer range: [−2^31, 2^31 − 1]. For the purpose of this problem, assume that
your function returns 2^31 − 1 when the division result overflows.
题⽬⼤意
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使⽤乘法、除法和 mod 运算
符。返回被除数 dividend 除以除数 divisor 得到的商。
说明:
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1]。本题中，如果除
法结果溢出，则返回 2^31 − 1。
解题思路
给出除数和被除数，要求计算除法运算以后的商。注意值的取值范围在 [−2^31, 2^31 − 1] 之中。
超过范围的都按边界计算。
这⼀题可以⽤⼆分搜索来做。要求除法运算之后的商，把商作为要搜索的⽬标。商的取值范围是
[0, dividend]，所以从 0 到被除数之间搜索。利⽤⼆分，找到(商 + 1 ) * 除数 > 被除数并且 商 * 除 数 ≤ 被除数 或者 (商+1)* 除数 ≥ 被除数并且商 * 除数 < 被除数的时候，就算找到了商，其余情况
继续⼆分即可。最后还要注意符号和题⽬规定的 Int32 取值范围。
⼆分的写法常写错的 3 点：
1. low ≤ high (注意⼆分循环退出的条件是⼩于等于)
2. mid = low + (high-low)>>1 (防⽌溢出)
3. low = mid + 1 ; high = mid - 1 (注意更新 low 和 high 的值，如果更新不对就会死循环)
*/
#include"DivideTwoIntegers/DivideTwoIntegers.h"
void DivideTwoIntergersTest()
{
	std::cout << "Method 1" << std::endl;
	int a = 10, b = 3;
	std::cout << DivideTwoIntegers::DivideTwoIntegersMethod2(a, b) << std::endl;
	a = 43, b = -8;
	std::cout << DivideTwoIntegers::DivideTwoIntegersMethod2(a, b) << std::endl;	

	std::cout << "Method 2" << std::endl;
	a = 10, b = 3;
	std::cout << DivideTwoIntegers::DivideTwoIntegersMethod2(a, b) << std::endl;
	a = 43, b = -8;
	std::cout << DivideTwoIntegers::DivideTwoIntegersMethod2(a, b) << std::endl;
}

/*
30. Substring with Concatenation of All Words
题⽬
You are given a string, s, and a list of words, words, that are all of the same length. Find all
starting indices of substring(s) in s that is a concatenation of each word in words exactly once and
without any intervening characters.
Example 1:
```
Input:
 s = "barfoothefoobarman",
 words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
respectively.
The output order does not matter, returning [9,0] is fine too.
```
Example 2:
```
Input:
 s = "wordgoodgoodgoodbestword",
 words = ["word","good","best","word"]
Output: []
```
题⽬⼤意
给定⼀个源字符串 s，再给⼀个字符串数组，要求在源字符串中找到由字符串数组各种组合组成的连续
串的起始下标，如果存在多个，在结果中都需要输出。
解题思路
这⼀题看似很难，但是有 2 个限定条件也导致这题不是特别难。1. 字符串数组里面的字符串⻓度都是⼀
样的。2. 要求字符串数组中的字符串都要连续连在⼀起的，前后顺序可以是任意排列组合。
解题思路，先将字符串数组里面的所有字符串都存到 map 中，并累计出现的次数。然后从源字符串从
头开始扫，每次判断字符串数组里面的字符串时候全部都⽤完了(计数是否为 0)，如果全部都⽤完了，
并且⻓度正好是字符串数组任意排列组合的总⻓度，就记录下这个组合的起始下标。如果不符合，就继
续考察源字符串的下⼀个字符，直到扫完整个源字符串。
*/
#include "SubstringWithConcatenationOfAllWords/SubstringWithConcatenationOfAllWords.h"
void SubstringWithConcatenationOfAllWordsTest() {	 
	std::cout << "test1" << std::endl;
	std::string s = "barfoothefoobarman";
	std::vector<std::string> v = { "foo", "bar" };
	SubstringWithConcatenationOfAllWords::print_vector(SubstringWithConcatenationOfAllWords::SubstringWithConcatenationOfAllWords(s, v));
	std::cout << "test2" << std::endl;
	s = "wordgoodgoodgoodbestword";
	v = { "word","good","best","word" };
	SubstringWithConcatenationOfAllWords::print_vector(SubstringWithConcatenationOfAllWords::SubstringWithConcatenationOfAllWords(s, v));
}

/**
33. Search in Rotated Sorted Array
题⽬
Suppose an array sorted in ascending order is rotated at some pivot unknown to you
beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2] ).
You are given a target value to search. If found in the array return its index, otherwise return -1 .
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
Example 1:
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
Example 2:
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```
题⽬⼤意
假设按照升序排序的数组在预先未知的某个点上进⾏了旋转。( 例如，数组 [0,1,2,4,5,6,7] 可能变为
[4,5,6,7,0,1,2] )。搜索⼀个给定的⽬标值，如果数组中存在这个⽬标值，则返回它的索引，否则返回 -1
。你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
解题思路
给出⼀个数组，数组中本来是从⼩到⼤排列的，并且数组中没有重复数字。但是现在把后⾯随机⼀
段有序的放到数组前⾯，这样形成了前后两端有序的⼦序列。在这样的⼀个数组⾥⾯查找⼀个数，
设计⼀个 O(log n) 的算法。如果找到就输出数组的⼩标，如果没有找到，就输出 -1 。
由于数组基本有序，虽然中间有⼀个“断开点”，还是可以使⽤⼆分搜索的算法来实现。现在数组前
⾯⼀段是数值⽐较⼤的数，后⾯⼀段是数值偏⼩的数。如果 mid 落在了前⼀段数值⽐较⼤的区间
内了，那么⼀定有 nums[mid] > nums[low] ，如果是落在后⾯⼀段数值⽐较⼩的区间内，
nums[mid] ≤ nums[low] 。如果 mid 落在了后⼀段数值⽐较⼩的区间内了，那么⼀定有
nums[mid] < nums[high] ，如果是落在前⾯⼀段数值⽐较⼤的区间内， nums[mid] ≤
nums[high] 。还有 nums[low] == nums[mid] 和 nums[high] == nums[mid] 的情况，单独
处理即可。最后找到则输出 mid，没有找到则输出 -1 。
*/
#include"SearchInRotatoedSortedArray/SearchInRotatoedSortedArray.h" 
void SearchInRotatoedSortedArrayTest() {
	std::vector<int>test = { 4,5,6,7,0,1,2 };
	int target = 0;
	int res = -1;
	res = SearchInRotatoedSortedArray::SearchInRotatoedSortedArrayMethod1(test, 0);
	std::cout << res << std::endl;
	res = SearchInRotatoedSortedArray::SearchInRotatoedSortedArrayMethod2(test, 0);
	std::cout << res << std::endl;

}

/*
34. Find First and Last Position of Element in Sorted Array
题⽬
Given an array of integers nums sorted in ascending order, find the starting and ending position
of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1] .
Example 1:
	Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]
Example 2:
	Input: nums = [5,7,7,8,8,10], target = 6
	Output: [-1,-1]
题⽬⼤意
给定⼀个按照升序排列的整数数组 nums，和⼀个⽬标值 target。找出给定⽬标值在数组中的开始位置
和结束位置。你的算法时间复杂度必须是 O(log n) 级别。如果数组中不存在⽬标值，返回 [-1, -1]。
解题思路
给出⼀个有序数组 nums 和⼀个数 target ，要求在数组中找到第⼀个和这个元素相等的元素下
标，最后⼀个和这个元素相等的元素下标。
这⼀题是经典的⼆分搜索变种题。⼆分搜索有 4 ⼤基础变种题：
1. 查找第⼀个值等于给定值的元素
2. 查找最后⼀个值等于给定值的元素
3. 查找第⼀个⼤于等于给定值的元素
4. 查找最后⼀个⼩于等于给定值的元素
这⼀题的解题思路可以分别利⽤变种 1 和变种 2 的解法就可以做出此题。或者⽤⼀次变种 1 的⽅
法，然后循环往后找到最后⼀个与给定值相等的元素。不过后者这种⽅法可能会使时间复杂度下降
到 O(n)，因为有可能数组中 n 个元素都和给定元素相同。(4 ⼤基础变种的实现⻅代码)
*/
#include"FindFirstandLastPositionofElementinSortedArray/find_first_last_position_in_sorted_array.h"
void FindFirstandLastPositionOfElementinSortedArrayTest() {
	std::vector<int>nums = { 5,7,7,8,8,10 };
	int target = 8;
	std::vector<int> res = FindFirstandLastPositionofElementInSortedArray::FindFirstandLastPositionOfElementInSortedArray(nums, target);
	for (int i = 0; i < res.size(); i++) {
		std::cout << res.at(i) << " ";
	}
}

/*
35. Search Insert Position
题⽬
Given a sorted array and a target value, return the index if the target is found.If not, return the
index where it would be if it were inserted in order.
You may assume no duplicates in the array
Example 1:
  Input: [1,3,5,6], 5
	Output: 2
Example 2:
	Input: [1,3,5,6], 2
	Output: 1
Example 3:
	Input: [1,3,5,6], 7
	Output: 4
Example 4:
	Input: [1,3,5,6], 0
	Output: 0
题⽬⼤意
给定⼀个排序数组和⼀个⽬标值，在数组中找到⽬标值，并返回其索引。如果⽬标值不存在于数组中，
返回它将会被按顺序插⼊的位置。
你可以假设数组中⽆重复元素。
解题思路
给出⼀个已经从⼩到⼤排序后的数组，要求在数组中找到插⼊ target 元素的位置。
这⼀题是经典的⼆分搜索的变种题，在有序数组中找到最后⼀个⽐ target ⼩的元素。
*/
#include "SearchInsertPostion/search_insert_position.h"
void SearchInsertPositionTest() {
	std::vector<int>arr = { 1, 3, 5, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 7;
	std::cout << SearchInsertPosition::SearchInsertPosition(arr, k) << std::endl;
}
/*
36. Valid Sudoku
题⽬
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to
the following rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
A partially filled sudoku which is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character '.' .
Example 1:
```
Input:
[
 ["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]
]
Output: true
```
Example 2:
```
Input:
[
 ["8","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
 modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
invalid.
```
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.' .
The given board size is always 9x9 .
题⽬⼤意
判断⼀个 9x9 的数独是否有效。只需要根据以下规则，验证已经填⼊的数字是否有效即可。
1. 数字 1-9 在每⼀⾏只能出现⼀次。
2. 数字 1-9 在每⼀列只能出现⼀次。
3. 数字 1-9 在每⼀个以粗实线分隔的 3x3 宫内只能出现⼀次。
解题思路
给出⼀个数独的棋盘，要求判断这个棋盘当前是否满⾜数独的要求：即⾏列是否都只包含 1-9，每
个九宫格⾥⾯是否也只包含 1-9 。
注意这题和第 37 题是不同的，这⼀题是判断当前棋盘状态是否满⾜数独的要求，⽽第 37 题是要
求求解数独。本题中的棋盘有些是⽆解的，但是棋盘状态是满⾜题意的。
*/
#include"ValidSudoku/ValidSudoku.h"
void ValidSudokuTest() {
	std::vector<std::vector<char> > sudoku = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	std::vector<std::vector<char> > sudoku2 = {
		{'8','3','.','.','7','.','.','.','.'} ,
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
	};
	bool ans = ValidSudoku::ValidSudoku(sudoku2);
	if (ans) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
}

/*
37. Sudoku Solver
题⽬
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the
grid.
Empty cells are indicated by the character '.' .
Note:
The given board contain only digits 1-9 and the character '.' .
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9 .
题⽬⼤意
编写⼀个程序，通过已填充的空格来解决数独问题。⼀个数独的解法需遵循如下规则：
1. 数字 1-9 在每⼀⾏只能出现⼀次。
2. 数字 1-9 在每⼀列只能出现⼀次。
3. 数字 1-9 在每⼀个以粗实线分隔的 3x3 宫内只能出现⼀次。
空⽩格⽤ '.' 表示。
解题思路
给出⼀个数独谜题，要求解出这个数独
解题思路 DFS 暴⼒回溯枚举。数独要求每横⾏，每竖⾏，每九宫格内， 1-9 的数字不能重复，每
次放下⼀个数字的时候，在这 3 个地⽅都需要判断⼀次。
另外找到⼀组解以后就不需要再继续回溯了，直接返回即可。
*/
#include "SudokuSolver/sudoku_solver.h"
void SudokuSolverTest() {	 

	std::vector<std::vector<int>> grid = {
		{6,5,0,8,7,3,0,9,0},
		{0,0,3,2,5,0,0,0,8},
		{9,8,0,1,0,4,3,5,7},
		{1,0,5,0,0,0,0,0,0},
		{4,0,0,0,0,0,0,0,2},
		{0,0,0,0,0,0,5,0,3},
		{5,7,8,3,0,1,0,2,6},
		{2,0,0,0,4,8,9,0,0},
		{0,9,0,6,2,5,0,8,1}
	};
	std::vector<std::vector<int>> grid1 = {
		{1,0,0,8,7,3,0,9,0},
		{0,0,3,2,5,0,0,0,8},
		{0,0,0,1,0,4,3,5,7},
		{0,0,5,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,2},
		{0,0,0,0,0,0,5,0,3},
		{0,0,8,3,0,1,0,2,6},
		{0,0,0,0,4,8,9,0,0},
		{0,0,0,6,2,5,0,8,1}
	};
	if (SudokuSolver::solveSudoku(grid1)) {
		SudokuSolver::sudokuGrid();
	};
}

/*
# 39. Combination Sum
## 题⽬
Given a **set** of candidate numbers ( candidates ) (**without duplicates**) and a target number
( target ), find all unique combinations in candidates where the candidate numbers sums to
target .

The **same** repeated number may be chosen from candidates unlimited number of times.

**Note:**
- All numbers (including target ) will be positive integers.
- The solution set must not contain duplicate combinations.

**Example 1:**
```
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
 [7],
 [2,2,3]
]
```
**Example 2:**
```
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
 [2,2,2,2],
 [2,3,3],
 [3,5]
]
```
## 题⽬⼤意
给定⼀个⽆重复元素的数组 candidates 和⼀个⽬标数 target ，找出 candidates 中所有可以使数字和
为 target 的组合。

candidates 中的数字可以⽆限制重复被选取。

## 解题思路
- 题⽬要求出总和为 sum 的所有组合，组合需要去重。
- 这⼀题和第 47 题类似，只不过元素可以反复使⽤。
*/
#include"CombinationSum/CombinationSum.h"
void CombinationSumTest() {
	std::vector<int>candidates = { 2,3,6,7 };
	int target = 8;
	std::vector<std::vector<int>>res = CombinationSum::CombinationSum(candidates, target);
	for (int i = 0; i < res.size(); i++) {
		std::cout << "[ ";
		for (int j = 0; j < res.at(i).size(); j++) {
			std::cout << res.at(i).at(j) << " ";
		}
		std::cout << " ]" << std::endl;
	}
}

/*
40. Combination Sum II
题⽬
Given a collection of candidate numbers ( candidates ) and a target number ( target ), find all
unique combinations in candidates where the candidate numbers sums to target .
Each number in candidates may only be used once in the combination.
Note:
All numbers (including target ) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
 [1, 7],
 [1, 2, 5],
 [2, 6],
 [1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
 [1,2,2],
 [5]
]
题目大意
给定⼀个数组 candidates 和⼀个⽬标数 target ，找出 candidates 中所有可以使数字和为 target 的组
合。
candidates 中的每个数字在每个组合中只能使⽤⼀次。
解题思路
题⽬要求出总和为 sum 的所有组合，组合需要去重。这⼀题是第 39 题的加强版，第 39 题中元素
可以重复利⽤(重复元素可⽆限次使⽤)，这⼀题中元素只能有限次数的利⽤，因为存在重复元素，
并且每个元素只能⽤⼀次(重复元素只能使⽤有限次)
这⼀题和第 47 题类似，只不过元素可以反复使⽤。
*/
void CombinationSum2Test() {
	std::vector<int>candidates = { 10,1,2,7,6,1,5 };
	int target = 8;
	std::vector<std::vector<int>>res = CombinationSum::CombinationSum2(candidates, target);
	for (int i = 0; i < res.size(); i++) {
		std::cout << "[ ";
		for (int j = 0; j < res.at(i).size(); j++) {
			std::cout << res.at(i).at(j) << " ";
		}
		std::cout << " ]" << std::endl;
	}
}

/*
# 41.First Missing Possitive
## 题目
Give an unsorted integer array, find the smallest missing positive integer
**Example 1**
```
Input: [1,2,0]
Output: 3
```
**Example 2**
```
Input: [3,4,-1,1]
Output: 2
```
**Example 2**
```
Input: [7,8,9,11,12]
Output:	1
```
**Note:**
You algorithm should run in O(n) time and uses constant extra space
### 题目大意
找到确实的第一个正整数
### 解题思路
为了减少时间复杂度，可以把input数组都装到map中，然后i循环从1开始，一次对比map中是否存在i，只要不存在i就立即返回结果，即为所求
*/
#include"FirstMissingPositive/first_missing_positive.h"
void FirstMissingPositiveTest() {
	std::vector<int>nums = { 2, 3, 1,5,-6 };
	std::cout << FirstMissingPositive::FirstMissingPositive(nums) << std::endl;
}

/*
# Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

**Examples**:  
**Input:** arr\[\]   = {2, 0, 2}
**Output:** 2

We can trap 2 units of water in the middle gap.

**Input:** arr\[\]   = {3, 0, 2, 0, 4}
**Output:** 7

We can trap "3 units" of water between 3 and 2,
"1 unit" on top of bar 2 and "3 units" between 2
and 4.  See below diagram also.

**Input:** arr\[\] = \[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1\]
**Output:** 6

**Explanation:**
The structure is like below
*/
#include"TrappingRainWater/TrappingRainWater.h"
void TrappingRainWaterTest() {
	int arr[] = { 0, 1, 0, 2, 1, 0,
									1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << TrappingRainWater::TrappingRainWaterMethod1(arr, n) << std::endl;
	std::cout << TrappingRainWater::TrappingRainWaterMethod2(arr, n) << std::endl;
	std::cout << TrappingRainWater::TrappingRainWaterMethod3(arr, n) << std::endl;
	std::cout << TrappingRainWater::TrappingRainWaterMethod4(arr, n) << std::endl;
	std::cout << TrappingRainWater::TrappingRainWaterMethod5(arr, n) << std::endl;
}

int main() {
	std::cout << "Hello World!" << std::endl;
	TrappingRainWaterTest();
	//TwoSumTest();
	//AddTwoNumbersTest();
	//LongestSubstringWithoutRepeatingCharactersTest();
	//MedianOfTwoSortedArrays();
	//ReverseIntergerTest();
	//PalindromeNumberTest();
	//ContainerWithMostWaterTest();
	//RomanToIntegerTest();
	//ThreeSumTest();
	//ThreeSumClosestTest();
	//LetterCombinationsOfAPhoneNumberTest();
	//FourSumTest();
	//RemoveNthNodeFromEndOfListTest();
	//ValidParanthesesTest();
	//MergeTwoSortedListsTest();
	//GenerateParaenthesesTest();
	//MergeKSortedListsTest();
	//SwapNodesInPairsTest();
	//ReverseNodesInKGroupTest();
	//RemoveDuplicatesfromSortedArrayTest();
	//RemoveElementTest();
	//ImplementsStrTest();
	//DivideTwoIntergersTest();
	//SubstringWithConcatenationOfAllWordsTest();
	//SearchInRotatoedSortedArrayTest();
	//FindFirstandLastPositionOfElementinSortedArrayTest();
	//SearchInsertPositionTest();
	//ValidSudokuTest();				 
	//SudokuSolverTest();
	//CombinationSumTest();
	//CombinationSum2Test();
	//FirstMissingPositiveTest();
	return 0;			
}