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
    ListNode* getMid(ListNode* node) {
        auto fastPointer = node;
        auto midPrev = node;
        
        while (fastPointer && fastPointer->next && fastPointer->next->next) {
            fastPointer = fastPointer->next->next;
            midPrev = midPrev->next;
        }
        auto mid = midPrev->next;
        midPrev->next = nullptr;
        
        return mid;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        auto midNode = getMid(head);
        auto leftNode = sortList(head);
        auto rightNode = sortList(midNode);

        if (leftNode->val > rightNode->val) {
            swap(leftNode, rightNode);
        }
        
        ListNode* root = leftNode;
        ListNode* curr = leftNode;
        leftNode = leftNode->next;
        
        while (leftNode && rightNode) {
            if (leftNode->val < rightNode->val) {
                curr->next = leftNode;
                leftNode = leftNode->next;
            }
            else {
                curr->next = rightNode;
                rightNode = rightNode->next;
            }
            curr = curr->next;
        }
        if (!leftNode) curr->next = rightNode;
        if (!rightNode) curr->next = leftNode;

        return root;
    }
};