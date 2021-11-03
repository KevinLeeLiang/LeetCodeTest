# Swap List Nodes in Pairs
> **Difficulty: Medium**

#### **Understanding the Problem: →**

Given a Linked List, your task is to swap the nodes of the Linked List in pairs. Swapping the Linked List in pairs is equivalent to reversing a Linked List in a group of two.

**Problem Note:** For Linked List with odd number of elements, the one node at the last would not be swapped while for the one with even number of nodes, all the nodes will be swapped in pair.

**For example:**
```
Input: 1->2->3->4->5->NULL
Output: 2->1->4->3->5->NULL
Similarly

Input: 5->6->7->8->NULL
Output: 6->5->8->7->NULL
Explanation: The nodes are swapped pairwise that is with its adjacent nodes.
```

**Possible follow-up questions to ask the interviewer: →**

- Do we have to change the link or just swap the data?(**Ans:** You just need to swap the data in pairs.)

#### Solutions

There is very vivid approach of solving this problem that is we have to reverse the nodes in pairs, which is to swap the data of nodes of the Linked List in a group of two. However there are two possible ways to solve this problem based on implementation:

- **Iterative Approach →** Here we will use iteration for swapping of nodes.
- **Recursive Approach** →We will use recursion here to swap nodes in pairs.

## Iterative Approach

> **Solution idea**

The idea here is to start with the head node and the node next to it and swap the data of both the node. After swapping we will move forward to the third node and will swap the data of third node with the fourth one and we will keep doing so until there is no node left or only one node left for swapping. Thus, all the nodes will be swapped in pairs.

> **Solution steps**

- We will take two pointers **first** and **second** and initialise them with head and the next of head.
- We will swap the data of **first** and **second** node.
- We will increment pointer **first** such that it points to the third node(which is to be swapped) and pointer **second** with the next of first(fourth node).
- We will proceed like this until any one of first and second is NULL.

> **Complexity Analysis**

Time Complexity = O(N)**,** where N is the length of the Linked List.  
Space Complexity = O(1)

## Recursive Approach

> **Solution idea**

The idea is to swap the data of the first pair and left the job of pairwise swapping of the remianing n-2 nodes on recursion. Here we are solving the problem of size n with the solution of smaller problems of size n-2.

> **Solution steps**

- We will first check for the base case, that is when there is no node in the Linked List or only one node.
- We will then perform the swap for the first pair.
- We will call the recursion for the pairs ahead.

> **Complexity Analysis**

Recurrence relation: T(N) = T(N-2) + O(1).  
We can simply analyse this recurrence using the recursion tree method or other method.  
Time Complexity = O(N), where N is the length of the Linked List.  
Space Complexity = O(N) for the recursion call stack. **(Think!)**

> **Critical ideas to think!**

- What if there are multiple data in the node? Do you think swapping will work in that case?

#### **Suggested Problems to Solve**

- Reverse a Linked List in a group of K.
- Swap pairs in a Linked List by changing the link.
- Check if elements in Linked List are present in pairs.
- Check is there are consecutive integers in all the pairs possible in the given Linked List.