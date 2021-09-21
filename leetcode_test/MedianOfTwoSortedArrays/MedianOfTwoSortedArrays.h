#pragma once
/**
 * @brief             - �ݹ�����nums1��nums2�����������λ����
 * @param nums1       - {std::vector<int>&} ��������nums1
 * @param i           - {int} nums1���ַ����������
 * @param nums2       - {std::vector<int>&} ��������nums2
 * @param j           - {int} nums2���ַ����������
 * @param k           - {int} ������������Ķ��ַ�����λ��
 * @return            - {int} ������λ��������num1��num2����Ļ������Ķ�Ӧ��ֵ
*/
int FindKth(std::vector<int>& nums1, int i, std::vector<int>& nums2, int j, int k) {
  if (i >= nums1.size()) return nums2[j + k - 1];
  if (j >= nums2.size()) return nums1[i + k - 1];
  if (k == 1) return std::min(nums1[i], nums2[j]);
  int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
  int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
  if (midVal1 < midVal2) {
    return FindKth(nums1, i + k / 2, nums2, j, k - k / 2);
  }
  else {
    return FindKth(nums1, i, nums2, j + k / 2, k - k / 2);
  }
}
/**
 * @brief           - �������������������λ��
 * @param nums1     - {std::vector<int>}��������1                            
 * @param nums2     - {std::vector<int>}��������2
 * @return          - ����������λ��
*/
float FindMedianSortedArrays(std::vector<int>nums1, std::vector<int>nums2) {
	int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
	return (FindKth(nums1, 0, nums2, 0, left) + FindKth(nums1, 0, nums2, 0, right)) / 2.0;
}