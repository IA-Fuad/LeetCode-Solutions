/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    unordered_map<TreeNode*, int> nodeLevel;
    unordered_map<TreeNode*, vector<TreeNode*>> parents;
    
    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 1});
        
        parents[root].push_back(nullptr);
        
        while (!Q.empty()) {
            auto[node, level] = Q.front();
            Q.pop();
            
            nodeLevel[node] = level;
            
            if (node->left) Q.push({node->left, level+1});
            if (node->right) Q.push({node->right, level+1});
            
            auto parent = node;
            
            for (int p = 0; ; p++) {
                if (node->left) parents[node->left].push_back(parent);
                if (node->right) parents[node->right].push_back(parent);
                
                if (p >= parents[parent].size()) break;
                parent = parents[parent][p];
            }
        }
    }
    
    TreeNode* getLCA(TreeNode* p, TreeNode* q) {
        if (nodeLevel[p] < nodeLevel[q]) swap(p, q);
        
        int log = 20;

        while (nodeLevel[p] > nodeLevel[q]) {
            if ((nodeLevel[p] - (1<<log)) >= nodeLevel[q]) {
                p = parents[p][log];
            }
            log--;
        }

        if (p == q) return p;
        
        log = 21;

        while (log-- >= 0) {
            if (log < parents[p].size()) {
                auto pp = parents[p][log];
                auto pq = parents[q][log];
               
                if (pp != pq) {
                    p = pp;
                    q = pq;
                }
            }
        }
        
        return parents[p][0];
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bfs(root);
        return getLCA(p, q);
    }
};