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
    ListNode* mergeList(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode();
        ListNode* curr = head;

        while (a or b) {
            if (b == nullptr or (a and a->val < b->val)) {
                curr->next = a;
                a = a->next;
            }
            else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        
        return head->next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size(), interval = 1;
        if (k == 0) return nullptr;
        
        while (interval < k) {
            for (int i = 0; i + interval < k; i += interval * 2) {
                lists[i] = mergeList(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
};

/*

0 1 2 3 4 5 6 7 8 9



*/