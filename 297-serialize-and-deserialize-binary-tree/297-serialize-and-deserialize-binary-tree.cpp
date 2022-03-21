/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree;
        serialize(root, tree);
        tree.pop_back();
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }

private:
    void serialize(TreeNode* root, string& tree) {
        if (!root) {
            tree += "N ";
            return;
        }
        tree += to_string(root->val) + ' ';
        serialize(root->left, tree);
        serialize(root->right, tree);
    }
    
    TreeNode* deserialize(stringstream& ss) {
        TreeNode* root;
        
        string node;
        while (ss >> node) {
            //cout << node << ' ';
            if (node == "N") {
                return nullptr;
            }
            else {
                root = new TreeNode(stoi(node));
                root->left = deserialize(ss);
                root->right = deserialize(ss);
                return root;
            }
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));