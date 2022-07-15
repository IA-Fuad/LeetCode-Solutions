/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    Node* getLeftestChild(Node* node) {
        if (node->left) return getLeftestChild(node->left);
        return node;
    }
    
    Node* getRightParent(Node* node) {
        if (!node->parent) return nullptr;
        if (node->parent->left == node) return node->parent;
        return getRightParent(node->parent);
    }
    
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return node;
        if (node->right) return getLeftestChild(node->right);
        if (!node->parent) return nullptr;
        if (node->parent->left == node) return node->parent;
        return getRightParent(node);
    }
};