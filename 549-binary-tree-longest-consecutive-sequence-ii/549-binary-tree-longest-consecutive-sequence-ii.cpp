/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isInc(int val, int prev) {
        return val-1 == prev;
    }
    
    bool isDec(int val, int prev) {
        return val+1 == prev;
    }
    
    int len = 0;
    
    pair<int, int> rec(TreeNode* curr, int prev) {
        if (!curr) return {0, 0};
        
        auto left = rec(curr->left, curr->val);
        auto right = rec(curr->right, curr->val);
        
        len = max(len, left.first + right.second + 1);
        len = max(len, left.second + right.first + 1);
        
        left.first = isInc(curr->val, prev) ? left.first + 1 : 0;
        left.second = isDec(curr->val, prev) ? left.second + 1 : 0;
        right.first = isInc(curr->val, prev) ? right.first + 1 : 0;
        right.second = isDec(curr->val, prev) ? right.second + 1 : 0;
        
       // cout << curr->val << ' ' << left.first << ' ' << left.second << ' ' << right.first << ' ' << right.second << endl;
        
        return {max(left.first, right.first), max(left.second, right.second)};
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        rec(root, INT_MIN);
        
        return len;
    }
};