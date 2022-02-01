class Solution {
    vector<vector<int>> dp;
    
    int rec(vector<vector<int>>& costs, int houseInd, int exclueColorInd) {
        if (houseInd == costs.size()) return 0;
        int* x = &dp[houseInd][exclueColorInd];
        if (*x != -1) return *x;
        
        int mnCost = INT_MAX;
        for (int i = 0; i < 3; i++) {
            if (exclueColorInd == i) continue;
            mnCost = min(mnCost, rec(costs, houseInd+1, i) + costs[houseInd][i]);
        }
        
        return *x = mnCost;
    }
    
public:
    int minCost(vector<vector<int>>& costs) {
        // dp.resize(costs.size(), vector<int>(3, -1));
        // int mnCost = INT_MAX;
        // for (int i = 0; i < 3; i++) {
        //     mnCost = min(mnCost, rec(costs, 0, i));
        // }
        // return mnCost;
        
        // dp.resize(costs.size()+1, vector<int>(3, INT_MAX));
        // dp[0][0] = dp[0][1] = dp[0][2] = 0;
        vector<int> colorCost(3, 0);
        int n = costs.size();
        
        for (int i = 1; i <= n; i++) {
            auto currentColorCost = colorCost;
            for (int k = 0; k < 3; k++) {
                int mnCost = INT_MAX;
                for (int j = 0; j < 3; j++) {
                    if (j == k) continue;
                    mnCost = min(mnCost, currentColorCost[j]);
                }
                colorCost[k] = mnCost + costs[i-1][k];
            }
        }
        
        return min({colorCost[0], colorCost[1], colorCost[2]});
    }
};