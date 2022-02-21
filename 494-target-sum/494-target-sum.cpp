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
        // unordered_map<string, int> dp;
        // return rec(nums, target, dp, 0, 0);
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (target < -total or target > total) return 0;
        
        int n = nums.size();

        vector<int> dp(total*2+1);
        
        dp[total] = 1;

        for (int k = n-1; k >= 0; k--) {
            vector<int> curr(total*2+1);
            for (int s = -total; s <= total; s++) {
                int shiftedS = s + total;
                int positive = shiftedS + nums[k];
                int negative = shiftedS - nums[k];
                if (positive >= 0 and positive <= 2*total) {
                    curr[shiftedS] = dp[positive];
                }
                if (negative >= 0 and negative <= 2*total) {
                    curr[shiftedS] += dp[negative];
                }
            }
            dp = curr;
        }

        return dp[target+total];
    }
};