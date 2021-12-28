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
    ListNode* reverseList(ListNode* head) {
        // ListNode* newHead = nullptr;
        // while(head) {
        //     ListNode* temp = head->next;
        //     head->next = newHead;
        //     newHead = head;
        //     head = temp;
        // }
        // return newHead;
        return reverseList(head, nullptr);
    }
private:
    ListNode* reverseList(ListNode* head, ListNode* prev) {
        if (!head) return prev;
        auto next = head->next;
        head->next = prev;
        return reverseList(next, head);
    }
};