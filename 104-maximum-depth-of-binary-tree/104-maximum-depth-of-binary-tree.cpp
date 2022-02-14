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
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        stack<pair<TreeNode*, int>> nodes;
        nodes.push({root, 1});
        int mxDepth = 1;
        
        while (!nodes.empty()) {
            TreeNode* node = get<0>(nodes.top());
            int depth = get<1>(nodes.top());
            nodes.pop();
            mxDepth = max(mxDepth, depth);
            
            if (node->left) {
                nodes.push({node->left, depth + 1});
            }
            if (node->right) {
                nodes.push({node->right, depth + 1});
            }
        }
        
        return mxDepth;
    }
};