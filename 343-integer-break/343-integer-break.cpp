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
        vector<int> dp(n+1, -1);
        return rec(n, dp);
    }
};