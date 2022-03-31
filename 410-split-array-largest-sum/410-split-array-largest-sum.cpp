class Solution {
    vector<vector<int>> dp;
    
    int rec(vector<int>& prefixSum, int i, int m) {
        if (dp[i][m] != -1) {
            return dp[i][m];
        }
        if (m == 1) {
            return dp[i][m] = prefixSum[prefixSum.size()-1] - prefixSum[i];
        }
        dp[i][m] = INT_MAX;
        for (int k = i; k < prefixSum.size() - m; k++) {
            int sum = prefixSum[k+1] - prefixSum[i];
            dp[i][m] = min(dp[i][m], max(sum, rec(prefixSum, k+1, m-1)));
        }
        
        return dp[i][m];
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        dp.resize(nums.size()+1, vector<int>(m+1, -1));
        
        vector<int> prefixSum(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        
        return rec(prefixSum, 0, m);
    }
};