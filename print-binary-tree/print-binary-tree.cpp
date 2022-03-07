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
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getHeight(root);
        int n = (1 << m) - 1;
        vector<vector<string>> treeMatrix(m, vector<string>(n));

        populateTreeMatrix(root, treeMatrix, 0, (n-1)/2, m, n);
        return treeMatrix;
    }

private:
    int getHeight(TreeNode* currentNode) {
        if (!currentNode) return 0;
        return max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;
    }
    
    void populateTreeMatrix(TreeNode* node, vector<vector<string>>& treeMatrix, int r, int c, int m, int n) {
        if (r < 0 or c < 0 or r == m or c == n) return;
        
        treeMatrix[r][c] = to_string(node->val);
        
        if (node->left) {
            populateTreeMatrix(node->left, treeMatrix, r+1, c - (1 << (m - r - 2)), m, n);
        }
        if (node->right) {
            populateTreeMatrix(node->right, treeMatrix, r+1, c + (1 << (m - r - 2)), m, n);
        }
    }
};