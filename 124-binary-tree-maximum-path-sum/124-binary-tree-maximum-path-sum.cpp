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
    int mx = INT_MIN;
    int rec(TreeNode* root) {
        if (!root) return 0;
        
        int left = rec(root->left);
        int right = rec(root->right);
        
        mx = max({mx, max(left + right, 0) + root->val, left + root->val, right + root->val});
        return max({max(left, right) + root->val, left + root->val, right + root->val, root->val});
    }
    
public:
    int maxPathSum(TreeNode* root) {
        return max(rec(root), mx);
    }
};