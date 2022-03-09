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
    bool isDuplicate(ListNode *&node) {
        if (!node or !node->next) return false;
        if (node->val != node->next->val) return false;
        
        ListNode* prev = node;
        node = node->next;
        bool duplicate = node->val == prev->val;
        
        while (node and node->val == prev->val) {
            node = node->next;
        }

        return duplicate;
    }
    
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head->next) return head;
        
        ListNode* dummyHead = new ListNode();
        ListNode* currentNode = head;
        ListNode* nonDuplicateList = dummyHead;
        
        while (currentNode) {
            while(isDuplicate(currentNode));

            nonDuplicateList->next = currentNode;
            nonDuplicateList = nonDuplicateList->next;
            currentNode = currentNode ? currentNode->next : currentNode;
        }
        
        return dummyHead->next;
    }
};