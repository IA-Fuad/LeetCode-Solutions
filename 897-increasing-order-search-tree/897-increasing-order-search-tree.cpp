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
    TreeNode* curr;
    
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        root->left = nullptr;
        curr->right = root;
        curr = curr->right;
        inOrder(root->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode();
        curr = ans;
        inOrder(root);
        return ans->right;
    }
};