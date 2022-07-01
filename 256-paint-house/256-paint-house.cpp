class Solution {
    int getPrevMin(vector<vector<int>>& costs, int i, int j) {
        if (j == 0) return min(costs[i-1][j+1], costs[i-1][j+2]);
        if (j == 1) return min(costs[i-1][j-1], costs[i-1][j+1]);
        return min(costs[i-1][j-1], costs[i-1][j-2]);
    }
    
public:
    int minCost(vector<vector<int>>& costs) {
        for (int i = 1; i < costs.size(); i++) {
            for (int j = 0; j < costs[i].size(); j++) {
                costs[i][j] += getPrevMin(costs, i, j);
            }
        }
        
        int n = costs.size();
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};