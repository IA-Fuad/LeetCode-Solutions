/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string x = "";
        getSerializedString(root, x);
        return x;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream s(data);
        return rec(s);
    }
    
private:
    void getSerializedString(Node* node, string& current) {
        if (!node) return;
        current += (" " + to_string(node->val) + " " + to_string(node->children.size()));
        for (auto child : node->children) {
            getSerializedString(child, current);
        }
    }
    
    Node* rec(stringstream& s) {
        string nodeValue;
        if (s >> nodeValue) {
            auto node = new Node(stoi(nodeValue));
            int childSize;
            s >> childSize;
            
            for (int i = 0; i < childSize; i++) {
                node->children.push_back(rec(s));
            }
            return node;
        }
        else {
            return nullptr;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));