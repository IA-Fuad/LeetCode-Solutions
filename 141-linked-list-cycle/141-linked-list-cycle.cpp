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
    bool hasCycle(ListNode *head) {
        ListNode* oneStep = head;
        ListNode* twoStep = head;
        
        while (twoStep and twoStep->next) {
            twoStep = twoStep->next->next;
            oneStep = oneStep->next;
            if (oneStep == twoStep) return true;
        }
        
        return false;
    }
};