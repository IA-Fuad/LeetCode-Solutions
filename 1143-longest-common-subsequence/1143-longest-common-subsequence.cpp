class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size(), s2 = text2.size();
        vector<int> dp(s2+1);
        
        for (int i = 1; i <= s1; i++) {
            int prev = 0;
            for (int j = 1; j <= s2; j++) {
                int temp = dp[j];
                if (text1[i-1] == text2[j-1]) {
                    dp[j] = prev + 1;
                }
                else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = temp;
            }
        }
        
        return dp[s2];
    }
};