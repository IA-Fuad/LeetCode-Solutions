class Solution {
    int rec(int n, vector<int>& dp) {
        if (n < 4) return n;
        if (dp[n] != -1) return dp[n];
        
        int ans = INT_MIN;
        for (int k = n-1; k > 0; k--) {
            ans = max(ans, rec(k, dp) * (n-k));
        }
        
        return dp[n] = ans;
    }
    
public:
    int integerBreak(int n) {
        if (n < 4) return n-1;
        vector<int> dp(n+1, INT_MIN);
        //return rec(n, dp);

        dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int k = 4; k <= n; k++) {
            for (int i = 1; i < k; i++) {
                dp[k] = max(dp[k], dp[i] * (k - i));
            }
        }
        
        return dp[n];
    }
};