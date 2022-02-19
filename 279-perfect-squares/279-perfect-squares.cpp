class Solution {
public:
    int numSquares(int n) {
        vector<int> sqs, dp(n+1, INT_MAX);
        for (int i = 1; i*i <= n; i++) sqs.push_back(i*i);
        
        dp[0] = 0;
        for (int k = 1; k <= n; k++) {
            for (int s : sqs) {
                if (s > k) break;
                dp[k] = min(dp[k], dp[k-s] + 1);
            }
        }
        
        return dp[n];
    }
};