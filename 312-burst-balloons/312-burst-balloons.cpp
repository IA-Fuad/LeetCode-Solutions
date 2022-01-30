class Solution {
    vector<vector<int>> dp;
    
    int rec(vector<int>& nums, int l, int r) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int maxCoins = 0;
        for (int k = l; k <= r; k++) {
            int current = nums[k] * nums[l-1] * nums[r+1];
            int remaining = rec(nums, l, k-1) + rec(nums, k+1, r);
            maxCoins = max(maxCoins, current + remaining);
        }
        
        return dp[l][r] = maxCoins;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dp.resize(nums.size(), vector<int>(nums.size(), -1));
        return rec(nums, 1, nums.size()-2);
    }
};