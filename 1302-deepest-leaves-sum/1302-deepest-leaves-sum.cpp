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
    int maxDepth, currentSum;

    void dfs(TreeNode* node, int dep) {
        if (!node) return;
        if (dep > maxDepth) {
            maxDepth = dep;
            currentSum = node->val;
        }
        else if (dep == maxDepth) {
            currentSum += node->val;
        }
        
        dfs(node->left, dep+1);
        dfs(node->right, dep+1);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        
        return currentSum;
    }
};