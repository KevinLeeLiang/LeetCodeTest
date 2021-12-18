#pragma once

namespace TrappingRainWater {
	int TrappingRainWaterMethod1(int arr[], int n) {
    // To store the maximum water
    // that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++) {

      // Find the maximum element on its left
      int left = arr[i];
      for (int j = 0; j < i; j++)
        left = std::max(left, arr[j]);

      // Find the maximum element on its right  
      int right = arr[i];
      for (int j = i + 1; j < n; j++)
        right = std::max(right, arr[j]);

      // Update the maximum water   
      res = res + (std::min(left, right) - arr[i]);
    }

    return res;
	}
  int TrappingRainWaterMethod2(int arr[], int n) {
    // initialize output
    int result = 0;

    // maximum element on left and right
    int left_max = 0, right_max = 0;

    // indices to traverse the array
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
      if (arr[lo] < arr[hi]) {
        if (arr[lo] > left_max)
          // update max in left
          left_max = arr[lo];
        else
          // water on curr element = max - curr
          result += left_max - arr[lo];
        lo++;
      }
      else {
        if (arr[hi] > right_max)
          // update right maximum
          right_max = arr[hi];
        else
          result += right_max - arr[hi];
        hi--;
      }
    }

    return result;
  }

  int TrappingRainWaterMethod3(int arr[], int n) {
    int size = n - 1;

    // Let the first element be stored as
    // previous, we shall loop from index 1
    int prev = arr[0];

    // To store previous wall's index
    int prev_index = 0;
    int water = 0;

    // To store the water until a larger wall
    // is found, if there are no larger walls
    // then delete temp value from water
    int temp = 0;
    for (int i = 1; i <= size; i++)
    {

      // If the current wall is taller than
      // the previous wall then make current
      // wall as the previous wall and its
      // index as previous wall's index
      // for the subsequent loops
      if (arr[i] >= prev)
      {
        prev = arr[i];
        prev_index = i;

        // Because larger or same
        // height wall is found
        temp = 0;
      }
      else
      {

        // Since current wall is shorter than
        // the previous, we subtract previous
        // wall's height from the current wall's
        // height and add it to the water
        water += prev - arr[i];

        // Store the same value in temp as well
        // If we dont find any larger wall then
        // we will subtract temp from water
        temp += prev - arr[i];
      }
    }

    // If the last wall was larger than or equal
    // to the previous wall then prev_index would
    // be equal to size of the array (last element)
    // If we didn't find a wall greater than or equal
    // to the previous wall from the left then
    // prev_index must be less than the index
    // of the last element
    if (prev_index < size)
    {

      // Temp would've stored the water collected
      // from previous largest wall till the end
      // of array if no larger wall was found then
      // it has excess water and remove that
      // from water variable
      water -= temp;

      // We start from the end of the array,
      // so previous should be assigned to
      // the last element
      prev = arr[size];

      // Loop from the end of array up to the
      // previous index which would contain
      // the largest wall from the left
      for (int i = size; i >= prev_index; i--)
      {

        // Right end wall will be definitely
        // smaller than the 'previous index' wall
        if (arr[i] >= prev)
        {
          prev = arr[i];
        }
        else
        {
          water += prev - arr[i];
        }
      }
    }

    // Return the maximum water
    return water;
  }    
  //int TrappingRainWaterMethod4(int height[], int n) {
    // Stores the indices of the bars
//    std::vector<int> st;
//
//    // Stores the final result
//    int ans = 0;
//
//    // Loop through the each bar
//    for (int i = 0; i < n; i++)
//    {
//
//      // Remove bars from the stack
//      // until the condition holds
//      while ((!st.empty()) &&
//        (height[st.top()] < height[i]))
//      {
//
//        // Store the height of the top
//        // and pop it.
//        int pop_height = height[st.top()];
//        st.pop();
//
//        // If the stack does not have any
//        // bars or the the popped bar
//        // has no left boundary
//        if (st.empty())
//          break;
//
//        // Get the distance between the
//        // left and right boundary of
//        // popped bar
//        int distance = i - st.top() - 1;
//
//        // Calculate the min. height
//        int min_height = std::min(height[st.top()],
//          height[i]) -
//          pop_height;
//
//        ans += distance * min_height;
//      }
//
//      // If the stack is either empty or
//      // height of the current bar is less than
//      // or equal to the top bar of stack
//      st.push(i);
//    }
//    return ans;
//  }
  int TrappingRainWaterMethod5(int arr[], int n) {
    // indices to traverse the array
    int left = 0;
    int right = n - 1;

    // To store Left max and right max
    // for two pointers left and right
    int l_max = 0;
    int r_max = 0;

    // To store the total amount
    // of rain water trapped
    int result = 0;
    while (left <= right)
    {

      // We need check for minimum of left
      // and right max for each element
      if (r_max <= l_max)
      {

        // Add the difference between
        // current value and right max at index r
        result += std::max(0, r_max - arr[right]);

        // Update right max
        r_max = std::max(r_max, arr[right]);

        // Update right pointer
        right -= 1;
      }
      else
      {

        // Add the difference between
        // current value and left max at index l
        result += std::max(0, l_max - arr[left]);

        // Update left max
        l_max = std::max(l_max, arr[left]);

        // Update left pointer
        left += 1;
      }
    }
    return result;
  }
}