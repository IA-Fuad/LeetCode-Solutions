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
    void inOrder(vector<int>& tree, TreeNode* root) {
        if (!root) return;
        inOrder(tree, root->left);
        tree.push_back(root->val);
        inOrder(tree, root->right);
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2, tree;
        
        inOrder(tree1, root1);
        inOrder(tree2, root2);

        int i = 0, j = 0;
        
        while(true) {
            if (i == tree1.size() && j == tree2.size()) break;
            if (i == tree1.size()) tree.push_back(tree2[j++]);
            else if (j == tree2.size()) tree.push_back(tree1[i++]);
            else if (tree1[i] < tree2[j]) tree.push_back(tree1[i++]);
            else tree.push_back(tree2[j++]);
        }
        
        return tree;
    }
};