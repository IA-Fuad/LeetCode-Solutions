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
    void mergeList(ListNode* list1, ListNode* list2) {
        auto x = list1;
        while (list2) {
            if (!list1->next || list1->next->val >= list2->val) {
                auto temp = list1->next;
                list1->next = new ListNode(list2->val);
                list1->next->next = temp;
                list1 = list1->next;
                list2 = list2->next;
            }
            else list1 = list1->next;
        }
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* mergedList = new ListNode();
        ListNode* head = mergedList;
        
        for (auto rootNode : lists) {
            mergeList(head, rootNode);
        }
        
        return head->next;
    }
};