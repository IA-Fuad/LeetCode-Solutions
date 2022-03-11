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
    pair<ListNode*, int> getTotalNodes(ListNode* head) {
        auto fastPointer = head;
        auto lastNode = head;
        int n = 0;
        
        while (fastPointer and fastPointer->next) {
            n++;
            lastNode = fastPointer->next;
            fastPointer = fastPointer->next->next;
            lastNode = fastPointer ? fastPointer : lastNode;
        }
        n *= 2;
        if (fastPointer) n++;
        return {lastNode, n};
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head or !head->next) return head;
        
        auto totalNodes = getTotalNodes(head);
        auto lastNode = totalNodes.first;
        int n = totalNodes.second;
        k = k % n;
        
        if (k == 0) return head;

        ListNode* newLastNode = head;
        
        for (int i = 1; i < (n-k); i++) {
            newLastNode = newLastNode->next;
        }
        auto newHead = newLastNode->next;
        newLastNode->next = nullptr;
        lastNode->next = head;
        
        return newHead;
    }
};

/*

n = 5
k = 2

1) use fast and slow pointer to find total nodes n. set k = k % n.
2) store the last node
3) get the (n-k)th node and set it's next to null.
4) then set the last node's next to the head. 

*/