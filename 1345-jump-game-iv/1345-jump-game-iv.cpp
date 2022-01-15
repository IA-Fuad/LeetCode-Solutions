class Solution {
    vector<vector<int>> graph;
    unordered_map<int, int> indexes;
    vector<int> depth;
    
    int bfs(vector<int>& arr, int n) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        depth[0] = 0;
        
        while (!q.empty()) {
            int u = q.front().first;
            int dep = q.front().second;
            q.pop();
            
            if (u == n-1) return dep;
            
            vector<int> nodes = graph[u];
            int firstIndex = indexes[arr[u]];
            if (depth[firstIndex] == -1 || depth[firstIndex] >= dep+1) {
                vector<int> nodes2 = graph[firstIndex];
                for (auto i: nodes2) {
                    if (i == firstIndex-1 || i == firstIndex+1) {
                        if (arr[i] == arr[u]) nodes.push_back(i);
                    }
                    else nodes.push_back(i);
                }
            }
            for (int i : nodes) {
                if (depth[i] == -1) {
                    depth[i] = dep+1;
                    q.push({i, dep+1});
                }
            }
        }
        return 0;
    } 
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        depth.resize(n, -1);
        graph.resize(n);

        for (int i = 0; i < n; i++) {
            if (indexes.find(arr[i]) != indexes.end()) {
                graph[indexes[arr[i]]].push_back(i);
            }
            else {
                graph[i].push_back(i);
                indexes[arr[i]] = i;
            }
            if (i > 0) graph[i].push_back(i-1);
            if (i < n-1) graph[i].push_back(i+1);
        }
        
        return bfs(arr, n);
    }
};