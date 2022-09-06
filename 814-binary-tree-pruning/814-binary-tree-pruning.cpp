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
    bool rec(TreeNode* curr) {
        if (!curr) return false;
        
        bool hasOneInLeft = rec(curr->left);
        bool hasOneInRight = rec(curr->right);
        
        if (!hasOneInLeft) {
            curr->left = nullptr;
        }
        if (!hasOneInRight) {
            curr->right = nullptr;
        }
        
        return (hasOneInLeft | hasOneInRight | curr->val == 1);
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        auto dummyRoot = new TreeNode(-1, root, nullptr);
        rec(dummyRoot);
        return dummyRoot->left;
    }
};