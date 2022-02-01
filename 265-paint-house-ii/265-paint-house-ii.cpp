class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), K = costs[0].size();
        vector<int> colorCost(K, 0);
        
        for (int i = 1; i <= n; i++) {
            auto currentColorCost = colorCost;
            for (int k = 0; k < K; k++) {
                int mnCost = INT_MAX;
                for (int j = 0; j < K; j++) {
                    if (j == k) continue;
                    mnCost = min(mnCost, currentColorCost[j]);
                }
                colorCost[k] = mnCost + costs[i-1][k];
            }
        }
        
        return *min_element(colorCost.begin(), colorCost.end());
    }
};