class Solution {
    int rec(vector<vector<vector<int>>>& dp, vector<int>& prices, int i, int k, bool canBuy) {
        if (prices.size() == i or k == 0) return 0;
        if (dp[i][k][canBuy] != -1) return dp[i][k][canBuy];
        
        int buy = 0, sell = 0, hold = 0;
        
        if (canBuy) {
            buy = rec(dp, prices, i+1, k, false) - prices[i];    
        }
        else {
            sell = rec(dp, prices, i+1, k-1, true) + prices[i];
        }
        hold = rec(dp, prices, i+1, k, canBuy);
        
        return dp[i][k][canBuy] = max({buy, sell, hold});
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2, -1)));
        
        return rec(dp, prices, 0, k, true);
    }
};