#pragma once
namespace RemoveDuplicatesfromSortedArray {
	int RemoveDuplicates1(int arr[], int n) {
    // Return, if array is empty
    // or contains a single element
    if (n == 0 || n == 1)
      return n;

    int* temp = new int[n];

    // Start traversing elements
    int j = 0;
    for (int i = 0; i < n - 1; i++)

      // If current element is not equal
      // to next element then store that
      // current element
      if (arr[i] != arr[i + 1])
        temp[j++] = arr[i];

    // Store the last element as whether
    // it is unique or repeated, it hasn't
    // stored previously
    temp[j++] = arr[n - 1];

    // Modify original array
    for (int i = 0; i < j; i++)
      arr[i] = temp[i];
    delete temp;
    temp = NULL;
    return j;
	}

  int RemoveDuplicates2(int arr[], int n)
  {
    if (n == 0 || n == 1)
      return n;

    // To store index of next unique element
    int j = 0;

    // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i = 0; i < n - 1; i++)
      if (arr[i] != arr[i + 1])
        arr[j++] = arr[i];

    arr[j++] = arr[n - 1];

    return j;
  }
}