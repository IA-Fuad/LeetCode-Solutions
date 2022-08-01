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
    
    void getLeafs(TreeNode* curr) {
        if (!curr) {
            return;
        }
        if (!curr->left and !curr->right) {
            leafs.push_back(curr->val);
            return;
        }
        
        getLeafs(curr->left);
        getLeafs(curr->right);
    }
    
    void getLeftMostNodes(TreeNode* curr) {
        if (!curr or (!curr->left and !curr->right)) {
            return;
        }
        leftMostNodes.push_back(curr->val);
        
        if (!curr->left) getLeftMostNodes(curr->right);
        else getLeftMostNodes(curr->left);
    }
    
    void getRightMostNodes(TreeNode* curr) {
        if (!curr or (!curr->left and !curr->right)) {
            return;
        }
        rightMostNodes.push_back(curr->val);
        
        if (!curr->right) getRightMostNodes(curr->left);
        else getRightMostNodes(curr->right);
    }
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        if (!root->left and !root->right) return {root->val};
        
        leftMostNodes.push_back(root->val);
        getLeafs(root);
        getLeftMostNodes(root->left);
        getRightMostNodes(root->right);
        
        reverse(rightMostNodes.begin(), rightMostNodes.end());
        for (int n : leafs) leftMostNodes.push_back(n);
        for (int n : rightMostNodes) leftMostNodes.push_back(n);
        
        return leftMostNodes;
    }
};