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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();

            if (n == u) {
                return q.front();
            }
            if (n != nullptr) {
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            else {
                q.push(nullptr);
            }
        }
        
        return nullptr;
    }
};