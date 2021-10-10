# Remove Nth node from end of the Linked List
[**REFERENCE**](https://www.geeksforgeeks.org/delete-nth-node-from-the-end-of-the-given-linked-list/)

给定一个链表，任务是移除掉链表从结尾往前第**N**个节点

**Examples:**  

> **Input :** 1->2->3->4->5 , N = 2   
> **Output :** 1->2->3->5
> 
> **Input :** 7->8->4->3->2 , N = 1   
> **Output :** 7->8->4->3  

**Prerequisites:**   
1\. [删除链表中的一个节点](https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/)   
2\. [找到链表中从结尾往前第**N**个节点](https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/)  
**Approach:**   
Deleting the Bth node from last is basically the same as deleting (length-B+1) from the start. In our approach, first, we evaluate the length of the linked list, then check 

- If length < B, then we can’t remove the node
- If length = B, then return head->next
- If length > B, then it means we have to delete the intermediate node, we will delete this node and make its prev node point to the next node of the deleted node.