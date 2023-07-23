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
    unordered_map<int, vector<TreeNode*>> binTrees;
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (n == 1) return {new TreeNode()};
        
        auto bt = binTrees.find(n);
        if (bt != binTrees.end()) {
            return bt->second;
        }
        
        vector<TreeNode*> fbt;
        
        for (int k = 1; k < n; k += 2) {
            auto leftTrees = allPossibleFBT(k);
            auto rightTrees = allPossibleFBT(n - k - 1);
            
            for (auto lt : leftTrees) {
                for(auto rt : rightTrees) {
                    auto node = new TreeNode(0, lt, rt);
                    fbt.push_back(node);
                } 
            }
        }
        
        return binTrees[n] = fbt;
    }
};