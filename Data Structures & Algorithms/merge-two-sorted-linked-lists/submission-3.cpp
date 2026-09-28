/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr){
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode *result = list1;
        ListNode *base;
        ListNode *merged;
        if (list2->val < list1->val) {
            base = list2;
            merged = list1;
            result = list2;
        } else {
            base = list1;
            merged = list2;
        }

        while (base->next != nullptr && merged != nullptr) {
            if (base->val <= merged->val && base->next->val > merged->val) {
                ListNode *temp = base->next;
                base->next = merged;
                ListNode *temp2 = merged->next;
                merged->next = temp;
                merged = temp2;
                base = base->next;
            } else {
                base = base->next;
            }
        }
        if (merged != nullptr && base != nullptr) {
            base->next = merged;
        }

        return result;
    }
};
