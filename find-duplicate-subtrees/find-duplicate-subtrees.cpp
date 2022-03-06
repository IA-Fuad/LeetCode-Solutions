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
    string rec(TreeNode* node, unordered_map<string, int>& cnt, vector<TreeNode*>& ans) {
        if (!node) {
            return "#";
        }
        string left = rec(node->left, cnt, ans);
        string right = rec(node->right, cnt, ans);
        string subTree = to_string(node->val) + "," + left + "," + right;

        cnt[subTree]++;
        if (cnt[subTree] == 2) {
            ans.push_back(node);
        }
        
        return subTree;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> cnt;
        vector<TreeNode*> ans;
        
        rec(root, cnt, ans);
        return ans;
    }
};