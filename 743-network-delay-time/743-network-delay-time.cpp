class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        
        for (auto& time : times) {
            int u = time[0], v = time[1], t = time[2];
            adj[u].push_back({v, t});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        vector<int> delays(n+1, INT_MAX);
        delays[0] = 0;
        Q.push({0, k});
        delays[k] = 0;

        while (!Q.empty()) {
            auto[t, u] = Q.top();
            Q.pop();
 
            for (auto V : adj[u]) {
                auto[v, tt] = V;

                if (delays[v] > t + tt) {
                    //cout << u << ' ' << v << ' ' << t+tt << ' ' << delays[v] << endl;
                    delays[v] = t + tt;
                    Q.push({delays[v], v});
                }
            }
        }
        
        int maxDelay = *max_element(delays.begin(), delays.end());
        
        return maxDelay == INT_MAX ? -1 : maxDelay;
    }
};