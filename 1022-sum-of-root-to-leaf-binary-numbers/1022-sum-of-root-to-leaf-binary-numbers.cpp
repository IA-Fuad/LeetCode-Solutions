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
    int sum = 0;
    void rec(TreeNode* root, int number) {
        if (!root) return;
        number = (number << 1) | root->val;
        if (!root->left && !root->right) {
            sum += number;
            return;
        }
        rec(root->left, number);
        rec(root->right, number);
    }
    
public:
    int sumRootToLeaf(TreeNode* root) {
        rec(root, 0);
        return sum;
    }
};