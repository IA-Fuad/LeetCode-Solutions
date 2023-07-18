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
    ListNode* reverseList(ListNode* a) {
        ListNode* curr = a;
        ListNode* prev = nullptr;
        
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head1 = reverseList(l1);
        auto head2 = reverseList(l2);

        ListNode* sum = new ListNode();
        ListNode* head = sum;
        int carry = 0;
        
        while (head1 and head2) {
            int s = (head1->val + head2->val) + carry;
            sum->next = new ListNode(s % 10);
            carry = s / 10;

            head1 = head1->next;
            head2 = head2->next;
            sum = sum->next;

        }

        if (!head1) head1 = head2;
        while (head1) {
            int s = head1->val + carry;
            sum->next = new ListNode(s % 10);
            carry = s / 10;
            
            sum = sum->next;
            head1 = head1->next;
        }
        if (carry > 0) {
            sum->next = new ListNode(carry);
        }
        
        return reverseList(head->next);
    }
};