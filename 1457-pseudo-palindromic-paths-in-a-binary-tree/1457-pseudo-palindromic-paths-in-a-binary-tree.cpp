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
    vector<int> numCount;
    int cnt = 0;
    
    bool isPalindrome() {
        int odd = 0, even = 0;
        for (int i = 1; i < 10; i++) {
            if (numCount[i]&1) {
                odd++;
                if (odd > 1) return false;
            }
        }
        
        return true;
    }
    
    void rec(TreeNode* root) {
        if (!root) return;
        
        numCount[root->val]++;
        
        if (!root->left and !root->right) {
            if (isPalindrome()) {
                cnt++;
            }
        }
        
        rec(root->left);
        rec(root->right);
        
        numCount[root->val]--;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        numCount.resize(10, 0);
        rec(root);
        
        return cnt;
    }
};