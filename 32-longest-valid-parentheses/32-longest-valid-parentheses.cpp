class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int maxLen = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i < 2 ? 0 : dp[i-2]) + 2;
                }
                else if (i - dp[i-1] - 1 >= 0 and s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + (i - dp[i-1] - 2 < 0 ? 0 : dp[i - dp[i-1] - 2]) + 2;
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        
        return maxLen;
    }
};