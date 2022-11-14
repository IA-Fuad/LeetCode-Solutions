class Solution {
    unordered_map<int, vector<int>> graph;
    
    void dfs(int u, unordered_set<int>& visited, int& visitedCount) {
        visited.insert(u);
        visitedCount++;
        
        for (int v : graph[u]) {
            if (visited.find(v) != visited.end()) continue;
            dfs(v, visited, visitedCount);
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            for (int j = 0; j < stones.size(); j++) {
                if (i == j) continue;
                
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                }
            }
        }
        
        unordered_set<int> visited;
        int canRemove = 0;
        
        for (auto& node : graph) {
            int visitedCount = 0;
            
            if (visited.find(node.first) == visited.end()) {
                dfs(node.first, visited, visitedCount);
                canRemove += (visitedCount - 1);
            }
        }
        
        return canRemove;
    }
};