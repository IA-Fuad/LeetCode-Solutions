class Solution {
    vector<int> dp;
    int rec(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(rec(nums, i+2) + nums[i], rec(nums, i+1));
    }
    
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return rec(nums, 0);
    }
};