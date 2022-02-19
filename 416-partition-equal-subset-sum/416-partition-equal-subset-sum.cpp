class Solution {
    bool rec(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (target < 0 || i == nums.size()) return false;
        if (dp[i][target] != -1) return dp[i][target];
        // bool can = false;
        // for (int k = i; k < nums.size(); k++) {
        //     can |= rec(nums, k+1, target-nums[k], dp);
        // }
        return dp[i][target] = rec(nums, i+1, target, dp) | rec(nums, i+1, target-nums[i], dp);
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if (n == 1 || totalSum&1) return false;
        
        int half = totalSum / 2;
        vector<vector<int>> dp(n+1, vector<int>(half+1, -1));
        return rec(nums, 0, half, dp);
        
//         
        
//         for (int i = 0)
    }
};