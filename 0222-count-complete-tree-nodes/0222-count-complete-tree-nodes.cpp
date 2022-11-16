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
    int getTotalLevel(TreeNode* node, int level) {
        if (!node) return level;
        return getTotalLevel(node->left, level+1);
    }
    
    bool nodeExists(TreeNode* node, int nodeNumber, int height) {
        if (!node) return false;
        int leftBound = 1, rightBound = (1 << (height-1));
        
        for (int i = 1; i < height and node; i++) {
            int mid = (leftBound + rightBound) / 2;
            
            if (nodeNumber > mid) {
                node = node->right;
                leftBound = mid + 1;
            }
            else {
                node = node->left;
                rightBound = mid;
            }
        }
        return node != nullptr;
    }
    
public:
    int countNodes(TreeNode* root) {
        int height = getTotalLevel(root, 0);
        if (height < 2) return height;
        
        int lastLevelNodes = (1 << (height-1));
        
        int left = 1, right = lastLevelNodes, lastNode;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nodeExists(root, mid, height)) {
                lastNode = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
     //   cout << lastLevelNodes << ' ' << lastNode << ' ';
        return (1 << height) - (lastLevelNodes - lastNode) - 1;   
    }
};