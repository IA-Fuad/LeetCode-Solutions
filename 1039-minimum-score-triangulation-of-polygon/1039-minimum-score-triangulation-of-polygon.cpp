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
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return rec(values, 0, n-1, dp);
    }
};