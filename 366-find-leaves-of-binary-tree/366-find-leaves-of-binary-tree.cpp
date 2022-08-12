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
    unordered_map<TreeNode*, int> indegree;
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> leaves;
    
    vector<vector<int>> ans;
    
    void dfs(TreeNode* curr, TreeNode* p) {
        if (!curr) return;
        
        parent[curr] = p;
        if (p != nullptr) indegree[p]++;
        
        if (!curr->left and !curr->right) {
            leaves.push(curr);
            return;
        }
        
        dfs(curr->left, curr);
        dfs(curr->right, curr);
    }
    
    int rec(TreeNode* curr) {
        if (!curr) return 0;
        
        int ind = max(rec(curr->left), rec(curr->right));
        if (ans.size() == ind) {
            ans.push_back({curr->val});
        }
        else {
            ans[ind].push_back(curr->val);
        }
        
        return ind + 1;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
//        dfs(root, nullptr);
        
//         vector<vector<int>> ans;
        
//         while (!leaves.empty()) {
//             int currLeafCount = leaves.size();
//             vector<int> currentLeaves;
            
//             while (--currLeafCount >= 0) {
//                 auto leaf = leaves.front();
//                 leaves.pop();
                
//                 currentLeaves.push_back(leaf->val);
                
//                 auto leafParent = parent[leaf];
//                 if (--indegree[leafParent] == 0) {
//                     leaves.push(leafParent);
//                 }
//             }
            
//             ans.push_back(currentLeaves);
//         }
        rec(root);
        
        return ans;
    }
};