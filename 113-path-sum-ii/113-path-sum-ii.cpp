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
    void rec(vector<vector<int>>& paths, vector<int>& path, TreeNode* curr, int target) {
        if (!curr) return;
        
        target -= curr->val;
        path.push_back(curr->val);
        
        if (!curr->left and !curr->right) {
            if (target == 0) {
                paths.push_back(path);
            }
            path.pop_back();
            return;
        }
        
        rec(paths, path, curr->left, target);
        rec(paths, path, curr->right, target);
        
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        
        rec(paths, path, root, targetSum);
        
        return paths;
    }
};