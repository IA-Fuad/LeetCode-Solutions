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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* head = sum;
        int digitSum = 0, reminder = 0;
        
        while (l1 or l2) {
            int a = 0, b = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }

            digitSum = a + b + reminder;
            reminder = digitSum / 10;
            digitSum %= 10;
            
            sum->next = new ListNode(digitSum);
            sum = sum->next;
        }
        if (reminder > 0) sum->next = new ListNode(reminder);
        
        return head->next;
    }
};