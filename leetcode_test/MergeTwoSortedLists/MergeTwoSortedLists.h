#pragma once
namespace MergeTwoSortedLists {
	typedef struct ListNode {
		int val;
		ListNode* next;
	};
}


MergeTwoSortedLists::ListNode* MergeTowLists(MergeTwoSortedLists::ListNode* l1, 
	MergeTwoSortedLists::ListNode* l2) {
	if (l1 == nullptr){
		return l2;
	}
	else if (l2 == nullptr) {
		return l1;
	}
	else {
		if (l1->val < l2->val) {
			l1->next = MergeTowLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = MergeTowLists(l1, l2->next);
			return l2;
		}
	}
}