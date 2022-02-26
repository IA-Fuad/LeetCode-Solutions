class Solution {
    int endMask;
    vector<vector<int>> dp;
    int rec(vector<vector<int>>& graph, int i, int mask) {
        if (mask == endMask) return 0;
        if (dp[i][mask] != -1) return dp[i][mask];
        
        dp[i][mask] = INT_MAX - 1;
        for (int& node : graph[i]) {
            dp[i][mask] = min(dp[i][mask], 1 + min(rec(graph, node, mask), rec(graph, node, mask | (1 << node))));
        }
        return dp[i][mask];
    }
    
    struct State {
        int node;
        int mask;
        int steps;
    };
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        endMask = (1 << n) - 1;
        int mask = (1 << n) - 1;
        dp.resize(n, vector<int>(endMask+1, -1));
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, rec(graph, i, (1 << i)));
        }
        return mn;
        
//         int n = graph.size();
//         int endMask = (1 << n) - 1;
//         vector<vector<bool>> seen(n, vector<bool>(endMask+1, false));

//         queue<State> Q;
//         for (int i = 0; i < n; i++) {
//             Q.push({i, 1 << i, 0});
//             seen[i][(1 << i)] = true;
//         }

//         while (!Q.empty()) {
//             auto currState = Q.front();
//             Q.pop();
            
//             for (int k : graph[currState.node]) {
//                 int currMask = currState.mask | (1 << k);

//                 if (!seen[k][currMask]) {
//                     if (currMask == endMask) return currState.steps + 1;
//                     seen[k][currMask] = true;
//                     Q.push({k, currMask, currState.steps + 1});
//                 }
//             }
//         }
        
//         return 0;
    }
};