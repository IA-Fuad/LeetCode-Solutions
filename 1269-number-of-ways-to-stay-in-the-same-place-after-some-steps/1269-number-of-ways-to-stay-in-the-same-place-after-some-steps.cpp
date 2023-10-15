class Solution {
    vector<vector<int>> dp;
    const int mod = 1e9 + 7;
    
    int numWays(int steps, int arrLen, int pos) {
        if (pos < 0 or pos >= arrLen) return 0;
        if (steps == 0) return pos == 0;
        if (dp[steps][pos] != -1) return dp[steps][pos];
        
        return dp[steps][pos] = (((numWays(steps - 1, arrLen, pos + 1) + numWays(steps - 1, arrLen, pos - 1)) % mod) + numWays(steps - 1, arrLen, pos)) % mod;
    }
    
public:
    int numWays(int steps, int arrLen) {
        dp.resize(501, vector<int>(501, -1));
        return numWays(steps, arrLen, 0);
    }
};
