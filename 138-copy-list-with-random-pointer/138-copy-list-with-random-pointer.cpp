/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
//         Node* copiedHead = new Node();
//         if (!head) return copiedHead;
        
//         Node* cCurr = copiedHead;
//         Node* oCurr = head;
        
//         while (oCurr) {
//             auto oNext = oCurr->next;
//             oCurr->next = cCurr;
//             cCurr->next = oNext;
            
//         }
        
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mapping;
        
        Node* oCurr = head;
        Node* newCopyHead = new Node(oCurr->val);
        auto cCurr = newCopyHead;
        
        mapping[oCurr] = cCurr;
        
        oCurr = oCurr->next;
        
        while (oCurr) {
            cCurr->next = new Node(oCurr->val);
            cCurr = cCurr->next;
            mapping[oCurr] = cCurr;
            oCurr = oCurr->next;
        }
        
        cCurr = newCopyHead;
        oCurr = head;
        
        while (cCurr) {
            cCurr->random = mapping[oCurr->random];
            cCurr = cCurr->next;
            oCurr = oCurr->next;
        }
        
        return newCopyHead;
    }
};