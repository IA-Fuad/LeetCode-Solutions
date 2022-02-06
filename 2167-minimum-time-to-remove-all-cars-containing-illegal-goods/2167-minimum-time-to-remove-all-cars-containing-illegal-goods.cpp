class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> dp(n);

        dp[0] = s[0] == '1';
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                dp[i] = min(i+1, dp[i-1] + 2);
            }
            else {
                dp[i] = dp[i-1];
            }
        }

        int mn = dp[n-1];
        dp[n-1] = s[n-1] == '1';
        
        for (int i = n-2; i >= 0; i--) {
            int left = i > 0 ? dp[i-1] : 0;
            if (s[i] == '1') {
                dp[i] = min(n-i, dp[i+1] + 2);
            }
            else {
                dp[i] = dp[i+1];
            }
            mn = min(mn, left + dp[i]);
        }
        
        return mn;
    }
};