class Solution {
    const int64_t mod = 1e9 + 7;
    
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int64_t>> dp(n, vector<int64_t>(n, 0));
        
        for (int j = 0; j < n; j++) {
            dp[j][j] = 1;
            for (int i = j-1; i >= 0; i--) {
                if (s[i] != s[j]) {
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
                else {
                    dp[i][j] = (dp[i+1][j-1] * 2);
                    
                    int left = i + 1, right = j - 1;
                    
                    while (left <= right and s[left] != s[i]) left++;
                    while (right >= left and s[right] != s[i]) right--;
                    
                    if (left == right) dp[i][j]++;
                    else if (left > right) dp[i][j] += 2;
                    else {
                        dp[i][j] -= dp[left+1][right-1];
                    }
                }
                if (dp[i][j] < 0) dp[i][j] += mod;
                dp[i][j] %= mod;
            }
        }
        
        return dp[0][n-1];// % mod;
    }
};