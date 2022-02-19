class Solution {
    int rec(vector<int>& nums, int target, unordered_map<string, int>& dp, int k, int sum) {
        if (k == nums.size()) {
            if (sum == target) return 1;
            return 0;
        }
        string key = to_string(k) + '/' + to_string(sum);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        int a = rec(nums, target, dp, k+1, sum-nums[k]);
        int b = rec(nums, target, dp, k+1, sum+nums[k]);
        
        dp[key] = a + b;
        return a + b;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return rec(nums, target, dp, 0, 0);
    }
};