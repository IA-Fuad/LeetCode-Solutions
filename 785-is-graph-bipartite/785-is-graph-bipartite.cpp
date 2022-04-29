class Solution {
    vector<int> nodeColor;
    
    bool dfs(vector<vector<int>>& graph, int u, int adjColor) {
        if (nodeColor[u] == -1) {
            nodeColor[u] = adjColor == 1 ? 2 : 1;
            for (int v : graph[u]) {
                if (!dfs(graph, v, nodeColor[u])) {
                    return false;
                } 
            }
        }
        else if (nodeColor[u] == adjColor) {
            return false;
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        nodeColor.resize(n+1, -1);
        
        for (int i = 0; i < n; i++) {
            if (nodeColor[i] == -1) {
                if (!dfs(graph, i, -1)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};