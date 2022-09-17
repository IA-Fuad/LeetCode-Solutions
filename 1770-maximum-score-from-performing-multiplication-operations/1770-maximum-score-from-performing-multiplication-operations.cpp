class Solution {
    vector<vector<int>> dp;
    
    int rec(vector<int>& nums, vector<int>& multipliers, int i, int j, int k) {
        if (k == multipliers.size()) {
            return 0;
        }
        if (dp[k][i] != INT_MIN) {
            return dp[k][i];
        }
        
        int x = rec(nums, multipliers, i+1, j, k+1) + (nums[i] * multipliers[k]);
        int y = rec(nums, multipliers, i, j-1, k+1) + (nums[j] * multipliers[k]);
        
        return dp[k][i] = max(x, y);
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.resize(multipliers.size(), vector<int>(multipliers.size(), INT_MIN));
        
        return rec(nums, multipliers, 0, nums.size()-1, 0);
    }
};