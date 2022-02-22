class Solution {    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum&1) return false;
        
        int target = totalSum / 2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {
                dp[i][t] = dp[i-1][t];
                int need = t - nums[i-1];
                if (need < 0) continue;
                dp[i][t] = dp[i][t] | dp[i-1][need];
            }
        }
        
        return dp[n][target];
    }
};