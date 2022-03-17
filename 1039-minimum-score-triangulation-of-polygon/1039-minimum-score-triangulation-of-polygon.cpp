class Solution {
    int rec(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int minScore = INT_MAX;
        
        for (int k = i+1; k < j; k++) {
            int score = rec(values, i, k, dp) + rec(values, k, j, dp) + (values[i] * values[k] * values[j]);
            minScore = min(minScore, score);
        }
        
        return dp[i][j] = minScore == INT_MAX ? 0 : minScore;
    }
    
public:
    int minScoreTriangulation(vector<int>& values) {
//         int n = values.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
        
//         return rec(values, 0, n-1, dp);
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n-3; i >= 0; i--) {
            for (int j = i+2; j < n; j++) {
                for (int k = i+1; k < j; k++) {
                    dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j], dp[i][k] + dp[k][j] + (values[i] * values[k] * values[j]));
                }
            }
        }
        
        return dp[0][n-1];
    }
};