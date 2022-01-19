/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) return NULL;
        
        ListNode* one = head->next;
        ListNode* two = head->next->next;
        
        while (true) {
            if (!two->next || !two->next->next) {
                return NULL;
            }
            if (one == two) {
                ListNode* start = head;
                while (true) {
                    if (start == one) return one;
                    start = start->next;
                    one = one->next;
                }
            }
            two = two->next->next;
            one = one->next;
        }
    }
};