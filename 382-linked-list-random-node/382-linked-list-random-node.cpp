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
    ListNode* root;
public:
    Solution(ListNode* head) {
        root = head;
    }
    
    int getRandom() {
        ListNode* curr = root;
        ListNode* randomNode = curr;
        int i = 1;
        while (curr) {
            int x = 1 + rand() % i;
            //cout << x << ' ';
            if (x == 1) randomNode = curr;
            i++;
            curr = curr->next;
        }
        //cout << endl;
        return randomNode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */