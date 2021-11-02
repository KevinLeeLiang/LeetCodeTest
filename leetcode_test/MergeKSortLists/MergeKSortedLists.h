#pragma once
namespace MergeKSortedLists {
	typedef struct ListNode {
		int val;
		ListNode* next;
	};
}	 

// 1.Brute Force Solution
namespace MergeKSortedListsMethod1 {
	MergeKSortedLists::ListNode* MergeKLists(std::vector<MergeKSortedLists::ListNode*> vec_listnode) {
		std::vector<int>x;
		for (int i = 0; i < vec_listnode.size(); i++) {
			MergeKSortedLists::ListNode* ptr_l1 = vec_listnode.at(i);
			while (ptr_l1 != nullptr) {
				x.push_back(ptr_l1->val);
				ptr_l1 = ptr_l1->next;
			}
		}
		std::sort(x.begin(), x.end());
		MergeKSortedLists::ListNode* temp = new MergeKSortedLists::ListNode();
		temp->val = x.at(0);
		MergeKSortedLists::ListNode* temp2 = new MergeKSortedLists::ListNode();
		temp->next = temp2;
		for (int i = 1; i < x.size(); i++) {
			temp2->val = x.at(i);
			if (i == x.size() - 1)
				temp2->next = nullptr;
			else {
				temp2->next = new MergeKSortedLists::ListNode();
				temp2 = temp2->next;
			}
		}
		return temp;
	}
}

//2. Compare One by One
namespace MergeKSortedListsMethod2 {
	MergeKSortedLists::ListNode* MergeKLists(std::vector<MergeKSortedLists::ListNode*> vec_listnode) {
		int k = vec_listnode.size();
		int min_index = 0;
		MergeKSortedLists::ListNode* head = NULL;
		if (k == 0)
			return head;
		else {
			head = new MergeKSortedLists::ListNode();
			head->val = vec_listnode.at(0)->val;
			head->next = vec_listnode.at(0)->next;
			MergeKSortedLists::ListNode* ref = head;

			while (true) {
				bool is_break = true;
				int min = INT_MAX;
				for (size_t i = 0; i < k; i++){
					if (vec_listnode.at(i) != NULL) {
						if (vec_listnode.at(i)->val < min) {
							min_index = i;
							min = vec_listnode.at(i)->val;
						}
						is_break = false;
					}
				}
				if (is_break) {
					break;
				}
				MergeKSortedLists::ListNode* a = new MergeKSortedLists::ListNode();
				a->val = vec_listnode.at(min_index)->val;
				a->next = nullptr;
				ref->next = a;
				ref = ref->next;
				// TODO: 这里的程序没有起到链表前移的作用
				vec_listnode.at(min_index) = vec_listnode.at(min_index)->next;
			}
			ref->next = NULL;
			return head->next;
		}
	}
}

// 3.Maintaining a Priority Queue 
namespace MergeKSortedListsMethod3 {
	//int cmp(MergeKSortedLists::ListNode* node1, MergeKSortedLists::ListNode* node2) {
	//	return node1->val - node2->val;
	//}
	//MergeKSortedLists::ListNode* MergeKLists(std::vector<MergeKSortedLists::ListNode*> vec_listnode) {
	//	// priority Queue Q of type ListNode and comparator cmp
	//	PriorityQueue Q(cmp);

	//}
	//ListNode mergeKLists(ListNode[] lists, int k) {
	//	// priority Queue Q of type ListNode and comparator cmp
	//	PriorityQueue Q(cmp)
	//		for (int i = 0 to k) {
	//			if (lists[i] is not null) {
	//				Q.add(lists[i])
	//			}
	//		}
	//	ListNode head(0)
	//		ListNode ref = head
	//		while (Q is not empty) {
	//			// fetch first element of queue
	//			ref.next = q.poll()
	//				ref = ref.next
	//				ListNode next = ref.next
	//				if (next is not null) {
	//					q.add(next)
	//				}
	//		}
	//	return head.next
	//}
}

// 4.Merge lists one by one
namespace MergeKSortedListsMethod4 {
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
		int k = vec_listnode.size();
		if (k == 1) {
			return vec_listnode.at(0);
		}
		if (k == 0) {
			return NULL;
		}
		MergeKSortedLists::ListNode* head = MergeTwoLists(vec_listnode.at(0), vec_listnode.at(1));
		for (size_t i = 2; i < k; i++)
			head = MergeTwoLists(head, vec_listnode.at(i));
		
		return head;
	}
}

// 5.Divide and conquer
namespace MergeKSortedListsMethod5 {
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
}
//MergeKSortedLists::ListNode* MergeTwoLists(MergeKSortedLists::ListNode* l1, MergeKSortedLists::ListNode* l2) {
//	if (l1 == nullptr) {
//		return l2;
//	}
//	else if (l2 == nullptr) {
//		return l1;
//	}
//	else {
//		if (l1->val < l2->val) {
//			l1->next = MergeTwoLists(l1->next, l2);
//			return l1;
//		}
//		else {
//			l2->next = MergeTwoLists(l1, l2->next);
//			return l2;
//		}
//	}
//}
//
//
//MergeKSortedLists::ListNode* MergeKLists(std::vector<MergeKSortedLists::ListNode*> vec_listnode) {
//	if (vec_listnode.size() == 0) {
//		return NULL;
//	}
//	else if (vec_listnode.size() == 1) {
//		return vec_listnode.at(0);
//	}
//	else {
//		int num = vec_listnode.size() / 2;
//		std::vector<MergeKSortedLists::ListNode*>vec_left, vec_right;
//		vec_left.assign(vec_listnode.begin(), vec_listnode.begin() + num);
//		vec_right.assign(vec_listnode.begin() + num, vec_listnode.end());
//		MergeKSortedLists::ListNode* ptr_left, * ptr_right;
//		ptr_left = MergeKLists(vec_left);
//		ptr_right = MergeKLists(vec_right);
//		return MergeTwoLists(ptr_left, ptr_right);
//	}
//}