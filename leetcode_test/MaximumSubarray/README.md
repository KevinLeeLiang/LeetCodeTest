# 53. Maximum Subarray
## 题⽬
Given an integer array nums , find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.
### Example:
```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```
### Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and
conquer approach, which is more subtle.
## 题⽬⼤意
给定⼀个整数数组 nums ，找到⼀个具有最⼤和的连续⼦数组（⼦数组最少包含⼀个元素），返回其最
⼤和。
## 解题思路
* 这⼀题可以⽤ DP 求解也可以不⽤ DP。
* 题⽬要求输出数组中某个区间内数字之和最⼤的那个值。 `dp[i]` 表示 `[0,i]` 区间内各个⼦区间
和的最⼤值，状态转移⽅程是 `dp[i] = nums[i] + dp[i-1] (dp[i-1] > 0)` ， `dp[i] =
nums[i] (dp[i-1] ≤ 0)` 。
## 代码
```c++
#include<vector>
namespace MaximumSubarray {
	int MaximumSubarray(std::vector<int>input, int &index){
		int res;
		if (input.size() == 0){ // 数组空，则最大值为0
			return 0;
		}
		if (input.size() == 1){ // 数组长度为1，则最大值为其本身
			return input.at(0);
		}
		std::vector<int>dp;
		dp.resize(input.size());
		res = input.at(index);
		int tmp = index;
    dp.at(0) = input.at(index); // [0, 0]的最大子数组和是0本身
		for (size_t i = 1; i < input.size(); i++){
			if (dp[i - 1] > 0) { // [0, i-1]最大子数组和大于0
				dp.at(i) = input.at(i) + dp.at(i - 1); // [0, i]的最大子数组和为第i个数值+[0, i-1]的最大子数组的和
			}
			else {
				dp.at(i) = input.at(i); // [0, i-1]最大子数组和小于0，[0, i]的最大子数组和为第i个数值本身
			}
			res = std::max(res, dp.at(i));
			index = res > dp.at(i) ? tmp: i;
			tmp = index;
		}
		for (size_t i = index; i >=0; i--){
			if (dp[i] > 0){
				std::cout << input.at(i) << " ";
			}
			else {
				std::cout << std::endl;
				break;
			}
		}
		return res;
	}
}
```