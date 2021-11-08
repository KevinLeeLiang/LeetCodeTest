#pragma once
namespace ReverseNodesInKGroup {
	typedef struct ListNode {
		int val;
		ListNode* next;
	};
}
namespace ReverseNodesInKGroupMethod1 {
  ReverseNodesInKGroup::ListNode* reverseOneGroup(ReverseNodesInKGroup::ListNode* pre, ReverseNodesInKGroup::ListNode* next) {
    ReverseNodesInKGroup::ListNode* last = pre->next, * cur = last->next;
    while (cur != next) {
      last->next = cur->next;
      cur->next = pre->next;
      pre->next = cur;
      cur = last->next;
    }
    return last;
  }
  ReverseNodesInKGroup::ListNode* reverseKGroup(ReverseNodesInKGroup::ListNode* head, int k) {
    if (!head || k == 1) return head;
    ReverseNodesInKGroup::ListNode* dummy = new ReverseNodesInKGroup::ListNode, * pre = dummy, * cur = head;
    dummy->next = head;
    for (int i = 1; cur; ++i) {
      if (i % k == 0) {
        pre = reverseOneGroup(pre, cur->next);
        cur = pre->next;
      }
      else {
        cur = cur->next;
      }
    }
    return dummy->next;
  }
}

namespace ReverseNodesInKGroupMethod2 {
  ReverseNodesInKGroup::ListNode* reverseKGroup(ReverseNodesInKGroup::ListNode* head, int k) {
    ReverseNodesInKGroup::ListNode* dummy = new ReverseNodesInKGroup::ListNode, * pre = dummy, * cur = pre;
    dummy->next = head;
    int num = 0;
    while (cur = cur->next) ++num;
    while (num >= k) {
      cur = pre->next;
      for (int i = 1; i < k; ++i) {
        ReverseNodesInKGroup::ListNode* t = cur->next;
        cur->next = t->next;
        t->next = pre->next;
        pre->next = t;
      }
      pre = cur;
      num -= k;
    }
    return dummy->next;
  }
}

namespace ReverseNodesInKGroupMethod3 {
  ReverseNodesInKGroup::ListNode* reverse(ReverseNodesInKGroup::ListNode* head, ReverseNodesInKGroup::ListNode* tail) {
    ReverseNodesInKGroup::ListNode* pre = tail;
    while (head != tail) {
      ReverseNodesInKGroup::ListNode* t = head->next;
      head->next = pre;
      pre = head;
      head = t;
    }
    return pre;
  }
  ReverseNodesInKGroup::ListNode* reverseKGroup(ReverseNodesInKGroup::ListNode* head, int k) {
    ReverseNodesInKGroup::ListNode* cur = head;
    for (int i = 0; i < k; ++i) {
      if (!cur) return head;
      cur = cur->next;
    }
    ReverseNodesInKGroup::ListNode* new_head = reverse(head, cur);
    head->next = reverseKGroup(cur, k);
    return new_head;
  }
  
}