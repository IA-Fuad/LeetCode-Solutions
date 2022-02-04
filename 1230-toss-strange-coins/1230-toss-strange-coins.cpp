class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int coins = prob.size();
        vector<vector<double>> dp(coins + 1, vector<double>(target+1));
        dp[0][0] = 1.0;
        
        for (int c = 1; c <= coins; c++) {
            for (int t = 0; t <= target; t++) {
                dp[c][t] = dp[c-1][t] * (1 - prob[c-1]);
                if (t > 0) {
                    dp[c][t] += (dp[c-1][t-1] * prob[c-1]);
                }
            }
        }
        
        return dp[coins][target];
    }
};