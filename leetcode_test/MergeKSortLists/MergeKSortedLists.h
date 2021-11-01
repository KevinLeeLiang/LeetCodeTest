#pragma once
namespace MergeKSortedLists {
	typedef struct ListNode {
		int val;
		ListNode* next;
	};
}

MergeKSortedLists::ListNode* MergeTwoLists(MergeKSortedLists::ListNode* l1, MergeKSortedLists::ListNode* l2) {
	if (l1 == nullptr) {
		return l2;
	}
	else if (l2 == nullptr) {
		return l1;
	}
	else {
		if (l1->val < l2->val) {
			l1->next = MergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = MergeTwoLists(l1, l2->next);
			return l2;
		}
	}
}


MergeKSortedLists::ListNode* MergeKLists(std::vector<MergeKSortedLists::ListNode*> vec_listnode) {
	if (vec_listnode.size() == 0) {
		return NULL;
	}
	else if (vec_listnode.size() == 1) {
		return vec_listnode.at(0);
	}
	else {
		int num = vec_listnode.size() / 2;
		std::vector<MergeKSortedLists::ListNode*>vec_left, vec_right;
		vec_left.assign(vec_listnode.begin(), vec_listnode.begin() + num);
		vec_right.assign(vec_listnode.begin() + num, vec_listnode.end());
		MergeKSortedLists::ListNode* ptr_left, * ptr_right;
		ptr_left = MergeKLists(vec_left);
		ptr_right = MergeKLists(vec_right);
		return MergeTwoLists(ptr_left, ptr_right);
	}
}