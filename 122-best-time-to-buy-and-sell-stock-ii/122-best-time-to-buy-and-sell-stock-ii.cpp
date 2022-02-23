class Solution {
    int rec(vector<int>& prices, int i, bool canBuy, bool canSell, int (*dp)[2][2]) {
        if (i == prices.size()) return 0;
        if (dp[i][canBuy][canSell] != -1) return dp[i][canBuy][canSell];
        
        int mx = INT_MIN;
        if (canBuy) {
            mx = rec(prices, i + 1, false, true, dp) - prices[i];
        }
        if (canSell) {
            mx = rec(prices, i + 1, true, false, dp) + prices[i];
        }
        mx = max(mx, rec(prices, i + 1, canBuy, canSell, dp));
        
        return dp[i][canBuy][canSell] = mx;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2][2];
        memset(dp, -1, sizeof dp);
        
        return rec(prices, 0, true, false, dp);
    }
};