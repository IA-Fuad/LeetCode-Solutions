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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<Node*> Q;
        Q.push(root);
        
        while (!Q.empty()) {
            int currSize = Q.size();
            vector<int> nodes;
            
            while (currSize-- > 0) {
                auto curr = Q.front();
                Q.pop();
                
                nodes.push_back(curr->val);

                for (auto child : curr->children) {
                    Q.push(child);
                }
            }
            
            ans.push_back(nodes);
        }
        
        return ans;
    }
};