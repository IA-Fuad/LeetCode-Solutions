class Solution {
    bool rec(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (target < 0 || i == nums.size()) return false;
        if (dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = rec(nums, i+1, target, dp) | rec(nums, i+1, target-nums[i], dp);
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (n == 1 || totalSum&1) return false;
        
        int half = totalSum / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(half+1, false));
        //return rec(nums, 0, half, dp);
        
        for (int i = 1; i <= n; i++) {
            dp[i-1][0] = true;
            for (int t = 1; t <= half; t++) {
                if (nums[i-1] > t) dp[i][t] = dp[i-1][t];
                else dp[i][t] = dp[i-1][t] | dp[i-1][t-nums[i-1]];
            }
        }
        
        return dp[n][half];
    }
};