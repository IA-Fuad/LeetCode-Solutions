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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};

        unordered_map<int, vector<int>> columnNodes;
        
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        
        int left = INT_MAX, right = INT_MIN;
        
        while (!Q.empty()) {
            auto[node, col] = Q.front();
            Q.pop();

            columnNodes[col].push_back(node->val);
            left = min(left, col);
            right = max(right, col);
            
            if (node->left) Q.push({node->left, col-1});
            if (node->right) Q.push({node->right, col+1});
        }
        
        vector<vector<int>> ans((right-left+1));
       // cout << left << ' ' << (right-left+1) << endl;
        for (auto x : columnNodes) {
           // cout << x.first-left << ' ' << x.second.size() << endl;
            ans[x.first-left] = x.second;
        }
 
        return ans;
    }
};