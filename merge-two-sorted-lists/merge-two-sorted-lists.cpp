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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
        
//         if (!list1) return list2;
//         if (!list2) return list1;
        
//         if (list1->val > list2->val) swap(list1, list2);
//         ListNode* node = list1;
        
//         while (true) {
//             if (!list2) break;
//             if (node->next && node->next->val < list2->val) {
//                 node = node->next;
//             }
//             else {
//                 ListNode* temp = node->next;
//                 node->next = list2;
//                 list2 = list2->next;
//                 node->next->next = temp;
//             }
//         }
//         return list1;
    }
};