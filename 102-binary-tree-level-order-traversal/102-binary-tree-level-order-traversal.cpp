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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> nodes;
        vector<vector<int>> ans;
        nodes.push(root);
        
        while (!nodes.empty()) {
            int currSize = nodes.size();
            vector<int> level;
            
            for (int i = 0; i < currSize; i++) {
                auto node = nodes.front();
                nodes.pop();
                
                level.push_back(node->val);
                
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};