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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> routeToBus;
        
        for (int b = 0; b < routes.size(); b++) {
            for (int r : routes[b]) {
                routeToBus[r].push_back(b);
            }
        }
        
        return getNumberOfBusesToDest(routeToBus, routes, source, target);
    }
};