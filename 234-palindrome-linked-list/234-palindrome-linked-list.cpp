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
    int getListLen(ListNode* head) {
        int len = 0;
        auto curr = head;
        
        while (curr) {
            len++;
            curr = curr->next;
        }
        
        return len;
    }
    
    bool isPalindrome(ListNode* head, int len) {
        int mid = len / 2;
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* curr = dummyHead;
        ListNode* prev = nullptr;

        while (--mid >= -1) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //cout << curr->val << ' ' << prev->val << endl;
        auto next = curr;
        auto left = prev;
        auto right = curr;
        if (len&1) right = right->next;
        
        mid = len / 2;
        
        while (--mid >= 0) {
            //cout << left->val << ' ' << right->val << endl;
            if (left->val != right->val) return false;
            
            right = right->next;
            
            curr = left;
            left = left->next;
            curr->next = next;
            next = curr;
        }
        
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if (!head or !head->next) return true;
        
        return isPalindrome(head, getListLen(head));
    }
};