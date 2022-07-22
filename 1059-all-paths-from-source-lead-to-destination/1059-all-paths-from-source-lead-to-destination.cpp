class Solution {
    vector<int> isOk;

    bool rec(vector<vector<int>>& graph, int s, int d) {
        if (s == d) return true;
        if (isOk[s] != -1 and isOk[s] != 2) return isOk[s];
        
        bool all = graph[s].size() > 0;
        for (int v : graph[s]) {
            if (isOk[v] == 2 and v != d) return false;
            isOk[v] = 2;
            all &= rec(graph, v, d);
            if (!all) break;
        }
        
        return isOk[s] = all;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        isOk.resize(n, -1);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        if (graph[destination].size() > 0 or (source != destination and graph[source].size() == 0)) return false;
        
        bool all = true;
        isOk[source] = 2;
        
        for (int s : graph[source]) {
            isOk[s] = 2;
            all &= rec(graph, s, destination);
            if (!all) break;
        }
        
        return all;
    }
};