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
    int ans, currentElement;
    
    void rec(TreeNode* node, int k) {
        if (!node) return;
        rec(node->left, k);
        currentElement++;
        if (currentElement == k) {
            ans = node->val;
            return;
        }
        rec(node->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        rec(root, k);
        return ans;
    }
};