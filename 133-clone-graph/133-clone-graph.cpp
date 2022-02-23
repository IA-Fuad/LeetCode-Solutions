/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        
        Node* startNode = new Node(node->val);
        
        queue<pair<Node*, Node*>> Q;
        unordered_map<Node*, Node*> visited;
        
        Q.push({startNode, node});
        visited[node] = startNode;
        
        while (!Q.empty()) {
            auto currNode = Q.front().first;
            auto mainNode = Q.front().second;
            Q.pop();
            
            for (auto* n : mainNode->neighbors) {
                auto it = visited.find(n);
                if (it == visited.end()) {
                    Node* newNode = new Node(n->val);
                    currNode->neighbors.push_back(newNode);
                    Q.push({newNode, n});
                    visited[n] = newNode;
                }
                else {
                    currNode->neighbors.push_back(it->second);
                }
            }
        }

        return startNode;
    }
};