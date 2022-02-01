class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), K = costs[0].size();
        vector<int> colorCost(K, 0);
        
        int mnCost = 0, secondMnCost = 0, mnColor = 0;
        
        for (int i = 1; i <= n; i++) {
            auto currentColorCost = colorCost;
            int currentMnCost = INT_MAX, currentSecondMnCost = INT_MAX, currentMnColor = 0;
            for (int k = 0; k < K; k++) {
                if (mnColor == k) colorCost[k] = secondMnCost + costs[i-1][k];
                else colorCost[k] = mnCost + costs[i-1][k];
                
                if (colorCost[k] < currentMnCost) {
                    currentSecondMnCost = min(currentSecondMnCost, currentMnCost);
                    currentMnCost = colorCost[k];
                    currentMnColor = k;
                }
                else if (colorCost[k] < currentSecondMnCost) {
                    currentSecondMnCost = colorCost[k];
                }
            }
            mnCost = currentMnCost, secondMnCost = currentSecondMnCost, mnColor = currentMnColor;
        }
        
        return *min_element(colorCost.begin(), colorCost.end());
    }
};