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
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        
        int maxWidth = 1;
        while (!Q.empty()) {
            int leftMostNodeNumber = Q.front().second;
            int rightMostNodeNumber = leftMostNodeNumber;
            queue<pair<TreeNode*, int>> nextLevel;

            while (!Q.empty()) {
                auto currNode = Q.front().first;
                int nodeNumber = Q.front().second - leftMostNodeNumber;
                rightMostNodeNumber = nodeNumber;
                Q.pop();

                if (currNode->left) {
                    nextLevel.push({currNode->left, (int64_t)nodeNumber * 2});
                }
                if (currNode->right) {
                    nextLevel.push({currNode->right, (int64_t)nodeNumber * 2 + 1});
                }
            }

            Q = nextLevel;
            maxWidth = max(maxWidth, (rightMostNodeNumber - (leftMostNodeNumber - leftMostNodeNumber)) + 1);
        }
        
        return maxWidth;
    }
};