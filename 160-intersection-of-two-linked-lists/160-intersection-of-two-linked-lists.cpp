/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *ans;
    
    void rec(ListNode* headA, ListNode* headB) {
        if (headA) {
            int val = headA->val;
            headA->val = -1;
            rec(headA->next, headB);
            headA->val = val;
        }
        else if (headB) {
            if (headB->val == -1) {
                ans = headB;
                return;
            }
            rec(headA, headB->next);
        }
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        rec(headA, headB);
        return ans;
    }
};