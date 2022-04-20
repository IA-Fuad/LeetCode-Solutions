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
class BSTIterator {
    stack<TreeNode*> tree;
    TreeNode* currentNode;
public:
    BSTIterator(TreeNode* root) {
        currentNode = root;
    }
    
    int next() {
        auto root = currentNode;
        while (root) {
            tree.push(root);
            root = root->left;
        }
        int nextValue = tree.top()->val;
        
        currentNode = tree.top()->right;
        tree.pop();
        
        return nextValue;
    }
    
    bool hasNext() {
        if (!currentNode and tree.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */