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
        dp.resize(costs.size(), vector<int>(3, -1));
        int mnCost = INT_MAX;
        for (int i = 0; i < 3; i++) {
            mnCost = min(mnCost, rec(costs, 0, i));
        }
        return mnCost;
    }
};