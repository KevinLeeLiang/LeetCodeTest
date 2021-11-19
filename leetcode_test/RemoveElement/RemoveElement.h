#pragma once
namespace RemoveElement {
	int RemoveElement(int arr[], int n, int val) {
		int count = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (arr[i] != val) {
				arr[count++] = arr[i];
			}
		}
		return count;
	}
}