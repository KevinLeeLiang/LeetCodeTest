# Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

**Examples**:  

**Input:** arr\[\]   = {2, 0, 2}
**Output:** 2
**Explanation:**
The structure is like below

![](https://media.geeksforgeeks.org/wp-content/uploads/20200429012104/Untitled-Diagram711.png)

We can trap 2 units of water in the middle gap.

**Input:** arr\[\]   = {3, 0, 2, 0, 4}
**Output:** 7
**Explanation:**
Structure is like below

![](https://media.geeksforgeeks.org/wp-content/uploads/20200429012307/Untitled-Diagram811.png)

We can trap "3 units" of water between 3 and 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.

**Input:** arr\[\] = \[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1\]
**Output:** 6

**Explanation:**
The structure is like below

![](https://media.geeksforgeeks.org/wp-content/uploads/20200429011707/Untitled-Diagram101.png)

Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2

**Basic Insight:**   
An element of the array can store water if there are higher bars on the left and right. The amount of water to be stored in every element can be found out by finding the heights of bars on the left and right sides. The idea is to compute the amount of water that can be stored in every element of the array. 

**Example**   
Consider the array {3, 0, 2, 0, 4}, three units of water can be stored three indexes 1 and 2, and one unit of water at index 3, and three units of water at index 4. 

> For Array\[\] = {3, 0, 2, 0, 4}   
> Water stored = 0 + 3 + 1 + 3 + 0 = 7   
>  
> 
> ![](https://media.geeksforgeeks.org/wp-content/uploads/20200429012756/Untitled-Diagram821.png)

**Method 1 :** This is a simple solution to the above problem.

- **Approach:** The idea is to traverse every array element and find the highest bars on the left and right sides. Take the smaller of two heights. The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element.
- **Algorithm:** 
    1. Traverse the array from start to end.
    2. For every element, traverse the array from start to that index and find the maximum height _(a)_ and traverse the array from the current index to end, and find the maximum height _(b)_.
    3. The amount of water that will be stored in this column is _min(a,b) – array\[i\]_, add this value to the total amount of water stored
    4. Print the total amount of water stored.

- **Complexity Analysis:** 
    - **Time Complexity:** O(n2).   
        There are two nested loops traversing the array, So time Complexity is O(n2).
    - **Space Complexity:** O(1).   
        No extra space is required.

**Method 2:** This is an efficient solution to the above problem.

- **Approach:** In the previous solution, to find the highest bar on the left and right, array traversal is needed which reduces the efficiency of the solution. To make this efficient one must pre-compute the highest bar on the left and right of every bar in linear time. Then use these pre-computed values to find the amount of water in every array element.
- **Algorithm:** 
    1. Create two arrays _left_ and _right_ of size n. create a variable _max\_ = INT\_MIN_.
    2. Run one loop from start to end. In each iteration update max\_ as _max\_ = max(max\_, arr\[i\])_ and also assign _left\[i\] = max\__
    3. Update max\_ = INT\_MIN.
    4. Run another loop from end to start. In each iteration update max\_ as _max\_ = max(max\_, arr\[i\])_ and also assign _right\[i\] = max\__
    5. Traverse the array from start to end.
    6. The amount of water that will be stored in this column is _min(a,b) – array\[i\]_,(where a = left\[i\] and b = right\[i\]) add this value to total amount of water stored
    7. Print the total amount of water stored.

- **Complexity Analysis:** 
    - **Time Complexity:** O(n).   
        Only one traversal of the array is needed, So time Complexity is O(n).
    - **Space Complexity:** O(n).   
        Two extra arrays are needed each of size n.

**Space Optimization for** the **above Solution:** 

Instead of maintaining two arrays of size n for storing the left and a right max of each element, maintain two variables to store the maximum till that point. Since water trapped at any element = _min(max\_left, max\_right) – arr\[i\]_. Calculate water trapped on smaller elements out of A\[lo\] and A\[hi\] first and move the pointers till _lo_ doesn’t cross _hi_.


- **Complexity Analysis:** 
    - **Time Complexity**: O(n).   
        Only one traversal of the array is needed.
    - **Auxiliary Space**: O(1).   
        As no extra space is required.

**Method 3:** Here another efficient solution has been shown.

- **Approach:** The concept here is that if there is a larger wall to the right then the water can be retained with a height equal to the smaller wall on the left. If there are no larger walls to the right then start from the left. There must be a larger wall to the left now. Let’s take an example of the heights are {….,3, 2, 1, 4,….}, So here 3 and 4 are boundaries the heights 2 and 1 are submerged and cannot act as boundaries. So at any point or index knowing the previous boundary is sufficient if there is a higher or equal length boundary in the remaining part of the array. If not then traverse the array backward and now must be a larger wall to the left.   
     
- **Algorithm:** 
    - Loop from index 0 to the end of the given array.
    - If a wall greater than or equal to the previous wall is encountered then make note of the index of that wall in a var called prev\_index.
    - Keep adding the previous wall’s height minus the current (ith) wall to the variable water.
    - Have a temporary variable that stores the same value as water.
    - If no wall greater than or equal to the previous wall is found then quit.
    - If prev\_index < size of the input array then subtract the temp variable from water, and loop from the end of the input array to prev\_index and find a wall greater than or equal to the previous wall (in this case, the last wall from backward).


- **Complexity Analysis:** 
    - **Time Complexity**: O(n).   
        As only one traversal of the array is needed.
    - **Auxiliary Space**: O(1).   
        As no extra space is required.


**Method 4 (Using Stack):**

We can use a Stack to track the bars that are bounded by the longer left and right bars. This can be done using only one iteration using Stacks.

**Approach:**

1\. Loop through the indices of the bar array.

2\. For each bar, we can do the following:

- While the Stack is not empty and the current bar has a height greater than the top bar of the stack,
- Store the index of the top bar in **pop\_height** and pop it from the Stack.
- Find the distance between the left bar(current top) of the popped bar and the current bar.
- Find the minimum height between the top bar and the current bar.
- The maximum water that can be trapped in **distance \* min\_height**.
- The water trapped including the popped bar is **(distance \* min\_height) – height\[pop\_height\]**.
- Add that to the fans**.**

3\. Final answer will the **ans**.

_**Time Complexity:** O(n)_  
_**Auxiliary Space:** O(n)_ 

**Method 5 (Two Pointer Approach)**

- **Approach**: At every index, The amount of rainwater stored is the difference between current index height and a minimum of left max height and right max-height
- **Algorithm** :
    - Take two pointers l and r. Initialize l to the starting index 0 and r to the last index n-1
    - Since l is the first element, left\_max would be 0, and right max for r would be 0
    - While l <= r , iterate the array . We have two possible conditions
    - **Condition1** : **left\_max <= right max**
        - Consider Element at index l
        - Since we have traversed all elements to the left of l, **left\_max is known** 
        - For the right max of l, We can say that the **right max would  always be >= current r\_max here**
        - So, **min(left\_max,right\_max)** would always equal to **left\_max** in this case
        - Increment l
    - **Condition2 : left\_max >  right max**
        - Consider Element at index r
        - Since we have traversed all elements to the right of r, **right\_max is known**
        - For the left max of l, We can say that the **left max would  always be >= current l\_max here**
        - So, **min(left\_max,right\_max)** would always equal to **right\_max** in this case
        - Decrement r

_**Time Complexity:** O(n)_  
_**Auxiliary Space:** O(1_)