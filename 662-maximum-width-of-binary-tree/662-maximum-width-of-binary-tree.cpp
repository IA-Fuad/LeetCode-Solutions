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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, uint64_t>> Q;
        Q.push({root, 0});
        
        int maxWidth = 1;
        while (!Q.empty()) {
            uint64_t leftMostNodeNumber = Q.front().second;
            uint64_t rightMostNodeNumber = leftMostNodeNumber;
            queue<pair<TreeNode*, uint64_t>> nextLevel;
            
            while (!Q.empty()) {
                auto currNode = Q.front().first;
                uint64_t nodeNumber = Q.front().second;
                rightMostNodeNumber = nodeNumber;
                Q.pop();

                if (currNode->left) {
                    nextLevel.push({currNode->left, nodeNumber * 2});
                }
                if (currNode->right) {
                    nextLevel.push({currNode->right, nodeNumber * 2 + 1});
                }
            }

            Q = nextLevel;
            maxWidth = max(maxWidth, (int)(rightMostNodeNumber - leftMostNodeNumber) + 1);
        }
        
        return maxWidth;
    }
};