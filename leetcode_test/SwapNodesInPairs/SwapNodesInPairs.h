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