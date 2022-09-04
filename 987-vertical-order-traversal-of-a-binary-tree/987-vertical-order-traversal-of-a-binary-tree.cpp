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
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> vNodes;
    int mn = 0, mx = 0;
    
    void rec(TreeNode* curr, int col) {
        if (!curr) return;
        
        mn = min(mn, col);
        mx = max(mx, col);
        
        vNodes[col].push(curr->val);
        
        rec(curr->left, col-1);
        rec(curr->right, col+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //rec(root, 0);
        vector<vector<int>> ans;
        
        unordered_map<int, vector<int>> vNodes;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        
        while (!Q.empty()) {
            int currSize = Q.size();
            unordered_map<int, priority_queue<int, vector<int>, greater<int>>> sortedNodes;
            
            for (int i = 0; i < currSize; i++) {
                auto[node, col] = Q.front();
                Q.pop();
                
                sortedNodes[col].push(node->val);
                mn = min(mn, col);
                mx = max(mx, col);
                
                if (node->left) {
                    Q.push({node->left, col-1});
                }
                if (node->right) {
                    Q.push({node->right, col+1});
                }
            }
            
            for (auto[col, nodes] : sortedNodes) {
                while (!nodes.empty()) {
                    vNodes[col].push_back(nodes.top());
                    nodes.pop();
                }
            }
        }
        
        for (int i = mn; i <= mx; i++) {
            vector<int> nodes;
            if (vNodes[i].size() > 0) {
                for (int n : vNodes[i]) {
                    nodes.push_back(n);
                }
            }
            ans.push_back(nodes);
        }
        
        return ans;
    }
};