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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* root = head->next;
        ListNode* curr = new ListNode();
        curr->next = head;
        
        while (curr && curr->next && curr->next->next) {
            //cout << curr->val << ' '<< curr->next->val << ' ' << curr->next->next->val << endl;
            ListNode* temp = curr->next;
            ListNode* nextNext = curr->next->next->next; // 3;
            ListNode* next = curr->next->next; // 2
            curr->next->next = nextNext;
            next->next = curr->next;
            curr->next = next;
            curr = temp;
        }
        
        return root;
    }
};