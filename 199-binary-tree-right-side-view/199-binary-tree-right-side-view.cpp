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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> ans;
        queue<TreeNode*> level;
        level.push(root);
        
        while (!level.empty()) {
            int currSize = level.size();
            int rightMost;
            
            for (int i = 0; i < currSize; i++) {
                auto node = level.front();
                level.pop();
                
                rightMost = node->val;
                
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
            }
            
            ans.push_back(rightMost);
        }
        
        return ans;
    }
};