#pragma once
namespace SwapNodesInPairs {
	typedef struct ListNode {
		int val;
		ListNode* next;
	};
}

namespace SwapNodesInPairsMethod1 {
  void SwapPairs(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
  }
  SwapNodesInPairs::ListNode* SwapInPairs(SwapNodesInPairs::ListNode* head)
  {
    if (head == NULL || head->next == NULL)
      return head;

    SwapNodesInPairs::ListNode* first = head;
    SwapNodesInPairs::ListNode* second = head->next;
    while (first != nullptr && second != nullptr){
      SwapPairs(first->val, second->val);
      if (second->next == NULL) {
        break;
      }
      first = second->next;
      second = first->next;
    }
    return head;
  }
}

namespace SwapNodesInPairsMethod2 {
  SwapNodesInPairs::ListNode* SwapInPairs(SwapNodesInPairs::ListNode* head) {
    if (head == NULL || head->next == NULL)
      return head;
    SwapNodesInPairsMethod1::SwapPairs(head->val, head->next->val);
    head = SwapInPairs(head->next->next);
  }
  SwapNodesInPairs::ListNode* SwapInPairs2(SwapNodesInPairs::ListNode* head) {
    SwapNodesInPairs::ListNode* ptr = head;
    SwapNodesInPairs::ListNode* temp =SwapInPairs(ptr);
    return head;
  }
}