#pragma once
class Solution {
public:
	ListNode * removeElements(ListNode* head, int val) {
		if (head == nullptr)
			return nullptr;
		head->next = removeElements(head->next, val);
		return head->val == val ? head->next : head;
	}
};