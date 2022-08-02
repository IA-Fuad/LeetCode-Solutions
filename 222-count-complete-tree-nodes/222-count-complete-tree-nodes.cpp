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
    bool exists(TreeNode* curr, int nodeNumber, int maxLevel) {
        int left = 1, right = (1 << (maxLevel-1)), mid;
        //cout << right << endl;
        for (int i = 1; i < maxLevel and curr; i++) {
            mid = left + (right - left) / 2;
            
            if (nodeNumber > mid) {
                left = mid + 1;
                curr = curr->right;
            }
            else {
                right = mid;
                curr = curr->left;
            }
        }
        
        return curr != nullptr;
    }
    
    int getMaxLevel(TreeNode* curr, int d) {
        if (!curr) return d;
        return getMaxLevel(curr->left, d + 1);
    }
    
public:
    int countNodes(TreeNode* root) {
        int maxLevel = getMaxLevel(root, 0);
        if (maxLevel <= 1) return maxLevel;
        
        int left = 1, right = (1 << (maxLevel-1));
        int ans;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            //cout << left << ' ' << mid << ' ' << right << endl;
            if (exists(root, mid, maxLevel)) {
                
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return (1 << (maxLevel-1)) - 1 + ans;
    }
};