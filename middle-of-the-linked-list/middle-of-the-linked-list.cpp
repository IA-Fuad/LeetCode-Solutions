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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr1 = head; 
        ListNode* ptr2 = head;
        while(true) {
            if (!ptr2->next) return ptr1;
            if (!ptr2->next->next) return ptr1->next;
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
        }
        return head;
    }
};