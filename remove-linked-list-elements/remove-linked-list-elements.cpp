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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) head = head->next;
        if (!head) return head;
        
        ListNode* node = head;
        while (node && node->next) {
            ListNode* temp = node->next;
            while (temp && temp->val == val) temp = temp->next;
            node->next = temp;
            node = node->next;
        }
        
        return head;
    }
};