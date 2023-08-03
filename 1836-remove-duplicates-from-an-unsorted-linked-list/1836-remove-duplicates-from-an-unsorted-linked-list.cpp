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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> nodeCount;
        auto curr = head;
        while (curr) {
            nodeCount[curr->val]++;
            curr = curr->next;
        }
        auto dummyHead = new ListNode();
        dummyHead->next = head;
        curr = dummyHead;
        while (curr and curr->next) {
            if (nodeCount[curr->next->val] > 1) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        return dummyHead->next;
    }
};