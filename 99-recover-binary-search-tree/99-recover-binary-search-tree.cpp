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
    TreeNode *first, *second, *prev;
    
    void rec(TreeNode* curr) {
        if (!curr) return;
        
        rec(curr->left);
        
        if (prev and curr->val < prev->val) {
            first = curr;
            if (!second) second = prev;
            else return;
        }
        
        prev = curr;
        
        rec(curr->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        rec(root);
        swap(first->val, second->val);
    }
};