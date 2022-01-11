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
//         rec(root, 0);
//         return sum;
        
        stack<pair<TreeNode*, int>> nodes;
        nodes.push({root, 0});
        
        while (!nodes.empty()) {
            TreeNode* node = nodes.top().first;
            int number = nodes.top().second;
            nodes.pop();
            number = (number << 1) | node->val;
            if (!node->left && !node->right) {
                sum += number;
            }
            else {
                if (node->right) nodes.push({node->right, number});
                if (node->left) nodes.push({node->left, number});
            }
        }
        
        return sum;
    }
};