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
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1->val > list2->val) swap(list1, list2);
        auto head = list1;
        
        while (list2) {
            if (!list1->next || list1->next->val >= list2->val) {
                auto temp = list1->next;
                list1->next = list2;
                list2 = list2->next;
                list1->next->next = temp;
            }
            else list1 = list1->next;
        }
        
        return head;
    }
    
    ListNode* merge(vector<ListNode*> lists, int s, int e) {
        if (s == e) return lists[s];
        
        int mid = s + (e - s) / 2;
        
        auto left = merge(lists, s, mid);
        auto right = merge(lists, mid+1, e);
        
        return mergeList(left, right);
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

//         ListNode* head = lists[0];
        
//         for (int i = 1; i < lists.size(); i++) {
//             head = mergeList(head, lists[i]);
//         }
        
//         return head;
        
         int k = lists.size(), interval = 1;
//         while (interval < k) {
//             for (int i = 0; i+interval < k; i += interval * 2) {
//                 lists[i] = mergeList(lists[i], lists[i+interval]);
//             }
//             interval *= 2;
//         }
        
//         return lists[0];
        
        return merge(lists, 0, k-1);
    }
};