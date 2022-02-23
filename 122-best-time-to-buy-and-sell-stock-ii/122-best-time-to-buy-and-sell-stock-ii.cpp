class Solution {
    int rec(vector<int>& prices, int i, bool canBuy, int (*dp)[2]) {
        if (i == prices.size()) return 0;
        if (dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int buy = INT_MIN, sell = INT_MIN, hold = INT_MIN;
        if (canBuy) {
            buy = rec(prices, i + 1, false, dp) - prices[i];
        }
        else {
            sell = rec(prices, i + 1, true, dp) + prices[i];
        }
        hold = rec(prices, i + 1, canBuy, dp);
        
        return dp[i][canBuy] = max({buy, sell, hold});
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2];
        memset(dp, -1, sizeof dp);
        
        return rec(prices, 0, true, dp);
    }
};