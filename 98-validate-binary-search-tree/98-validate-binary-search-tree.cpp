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
    bool rec(TreeNode* curr, int64_t leftRange, int64_t rightRange) {
        if (!curr) return true;
        if (curr->val < leftRange or curr->val > rightRange) return false;
        
        return rec(curr->left, leftRange, (int64_t)curr->val-1) and rec(curr->right, (int64_t)curr->val+1, rightRange);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return rec(root, INT_MIN, INT_MAX);
    }
};