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
    int cnt = 0;
    
    void rec(TreeNode* root, int maxValue) {
        if (!root) return;
        
        if (root->val >= maxValue) {
            cnt++;
            maxValue = root->val;
        }
        
        rec(root->left, maxValue);
        rec(root->right, maxValue);
    }
    
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        
        rec(root, root->val);
        return cnt;
    }
};