class Solution {
    int getNumberOfBusesToDest(unordered_map<int, vector<int>>& routeToBus, vector<vector<int>>& routes, int source, int target) {
        vector<int> visited(routes.size(), false);
        queue<pair<int, int>> Q;
        
        for (int b : routeToBus[source]) {
            Q.push({b, 1});
            visited[b] = true;
        }

        while (!Q.empty()) {
            int currentBus = Q.front().first;
            int busesTillNow = Q.front().second;
            Q.pop();

            for (int r : routes[currentBus]) {
                if (r == target) {
                    return busesTillNow;
                }
                for (int b : routeToBus[r]) {
                    if (!visited[b]) {
                        visited[b] = true;
                        Q.push({b, busesTillNow + 1});
                    }
                }
            }
        }
        
        return -1;
    }
    
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        queue<pair<int, int>> bfs;
        bfs.push({S, 0});
        unordered_set<int> seen = {S};
        while (!bfs.empty()) {
            int stop = bfs.front().first, bus = bfs.front().second;
            bfs.pop();
            if (stop == T)
                return bus;
            for (int i : to_routes[stop]) {
                for (int j : routes[i]) {
                    if (seen.find(j) == seen.end()) {
                        seen.insert(j);
                        bfs.push({j, bus + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};