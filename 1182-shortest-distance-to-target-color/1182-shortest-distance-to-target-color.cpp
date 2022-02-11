class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> shortestDistanceAtEachIndex(n, vector<int>(4, n));
        
        shortestDistanceAtEachIndex[0][colors[0]] = 0;
        for (int i = 1; i < n; i++) {
            for (int c = 1; c <= 3; c++) {
                shortestDistanceAtEachIndex[i][c] = shortestDistanceAtEachIndex[i-1][c] + 1;
            }
            shortestDistanceAtEachIndex[i][colors[i]] = 0;
        }
        shortestDistanceAtEachIndex[n-1][colors[n-1]] = 0;
        for (int i = n-2; i >= 0; i--) {
            for (int c = 1; c <= 3; c++) {
                shortestDistanceAtEachIndex[i][c] = min(shortestDistanceAtEachIndex[i][c], shortestDistanceAtEachIndex[i+1][c] + 1);
            }
            shortestDistanceAtEachIndex[i][colors[i]] = 0; 
        }
        
        vector<int> shortestDistances;
        for (auto q : queries) {
            int distance = shortestDistanceAtEachIndex[q[0]][q[1]];
            if (distance >= n) {
                distance = -1;
            }
            shortestDistances.push_back(distance);
        }
        
        return shortestDistances;
    }
};