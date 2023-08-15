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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* lastNode = dummyHead;
        ListNode* curr = head;
        ListNode* prev = lastNode;
        
        while (curr) {
            auto currNext = curr->next;
            if (curr->val < x) {
                if (prev == dummyHead) {
                    lastNode = curr;
                }
                else {
                    prev->next = currNext;
                    auto lastNodeNext = lastNode->next;

                    curr->next = lastNodeNext;
                    lastNode->next = curr;
                    lastNode = lastNode->next;
                }
            }
            else {
                prev = curr;
            }
            curr = currNext;
        }
        
        return dummyHead->next;
    }
};

/*

dh = -1, prev = -1, curr = 1
cn = 1, 

*/

