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
    vector<int> leafs, leftMostNodes, rightMostNodes;
    
    void getLeafs(TreeNode* curr, bool fromLeft, bool fromRight) {
        if (!curr) {
            return;
        }
        if (!curr->left and !curr->right) {
            leafs.push_back(curr->val);
            return;
        }
        if (fromLeft) {
            leftMostNodes.push_back(curr->val);
        }
        if (fromRight) {
            rightMostNodes.push_back(curr->val);
        }

        getLeafs(curr->left, (curr->left and fromLeft), (!curr->right and fromRight));
        getLeafs(curr->right, (!curr->left and fromLeft), (curr->right and fromRight));
    }
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        if (!root->left and !root->right) return {root->val};
        
        leftMostNodes.push_back(root->val);
        getLeafs(root->left, true, false);
        getLeafs(root->right, false, true);
        
        reverse(rightMostNodes.begin(), rightMostNodes.end());
        for (int n : leafs) leftMostNodes.push_back(n);
        for (int n : rightMostNodes) leftMostNodes.push_back(n);
        
        return leftMostNodes;
    }
};