class Solution {
    int rec(vector<int>& prices, int i, bool canBuy, int (*dp)[2]) {
        if (i == prices.size()) return 0;
        if (dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int mx = INT_MIN;
        if (canBuy) {
            mx = rec(prices, i + 1, false, dp) - prices[i];
        }
        else {
            mx = rec(prices, i + 1, true, dp) + prices[i];
        }
        mx = max(mx, rec(prices, i + 1, canBuy, dp));
        
        return dp[i][canBuy] = mx;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2];
        memset(dp, -1, sizeof dp);
        
        return rec(prices, 0, true, dp);
    }
};