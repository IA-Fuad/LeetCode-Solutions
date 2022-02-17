class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+2);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        
        for (int k = 3; k <= n; k++) {
            for (int i = 1; i <= k; i++) {
                dp[k] += (dp[k-i] * dp[i-1]);
            }
        }
        
        return dp[n];
    }
};