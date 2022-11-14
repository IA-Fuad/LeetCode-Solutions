class Solution {
    vector<vector<int>> graph;
    
    void dfs(int u, vector<bool>& visited, int& visitedCount) {
        visited[u] = true;
        visitedCount++;
        
        for (int v : graph[u]) {
            if (visited[v]) continue;
            dfs(v, visited, visitedCount);
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        graph.resize(stones.size(), vector<int>(stones.size()));
        for (int i = 0; i < stones.size(); i++) {
            for (int j = 0; j < stones.size(); j++) {
                if (i == j) continue;
                
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                }
            }
        }
        
        vector<bool> visited(stones.size());
        int canRemove = 0;
        
        for (int node = 0; node < stones.size(); node++) {
            int visitedCount = 0;
            
            if (!visited[node]) {
                dfs(node, visited, visitedCount);
                canRemove += (visitedCount - 1);
            }
        }
        
        return canRemove;
    }
};