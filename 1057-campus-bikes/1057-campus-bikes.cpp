class Solution {
    int getManhattanDistance(vector<int> a, vector<int> b) {
        int xDist = abs(a[0] - b[0]);
        int yDist = abs(a[1] - b[1]);
        return xDist + yDist;
    }

public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int, int>>> distanceToPairs(2000);
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                distanceToPairs[getManhattanDistance(workers[i], bikes[j])].push_back({i, j});
            }
        }
        
        vector<int> assignedBikes(workers.size(), -1);
        unordered_set<int> bikeTaken;
        int pairCount = 0, d = 0;
        
        while (pairCount < workers.size()) {
            for (auto[w, b] : distanceToPairs[d]) {
                if (bikeTaken.find(b) == bikeTaken.end() and assignedBikes[w] == -1) {
                    assignedBikes[w] = b;
                    bikeTaken.insert(b);
                    pairCount++;
                }
            }
            d++;
        }
        
        return assignedBikes;
    }
};