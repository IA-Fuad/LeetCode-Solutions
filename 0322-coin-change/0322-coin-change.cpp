class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int k = 1; k <= amount; k++) {
            for (int coin : coins) {
                if (coin > k) continue;
                if (dp[k - coin] == INT_MAX) continue;
                dp[k] = min(dp[k], dp[k - coin] + 1);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};