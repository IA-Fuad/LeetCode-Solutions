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
    ListNode* reverseList(ListNode* head, int limit) {
        if (limit == 0) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        //cout << curr->val << ' ';
        while (limit-- >= 0) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
           // cout << prev->val << ' ';
        }
        
        head->next = curr;
        return prev;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode = head;
        ListNode* prevNode = nullptr;
        for (int l = 1; l < left; l++) {
            prevNode = leftNode;
            leftNode = leftNode->next;
        }

        auto reversedHead = reverseList(leftNode, right-left);
        //cout << reversedHead->val << ' ';
        if (prevNode) prevNode->next = reversedHead;
        
        return left > 1 ? head : reversedHead;
    }
};