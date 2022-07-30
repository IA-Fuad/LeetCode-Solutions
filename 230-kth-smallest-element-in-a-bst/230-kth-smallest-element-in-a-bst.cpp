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
    TreeNode* ans;
    void rec(TreeNode* curr, int& k) {
        if (!curr) return;
        
        rec(curr->left, k);
        k--;
        if (k == 0) {
            ans = curr;
        }
        rec(curr->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        rec(root, k);
        
        return ans->val;
    }
};