class Solution {
    vector<int> dp;
    
    int rec(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        
        return dp[i] = max(rec(nums, i+1), rec(nums, i+2) + nums[i]);
    }
    
public:
    int rob(vector<int>& nums) {
        // dp.resize(nums.size(), -1);
        // return rec(nums, 0);
        
        if (nums.size() == 1) return nums[0];
        
        int prevPrev = nums[0], prev = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int temp = prev;
            prev = max(prev, prevPrev + nums[i]);
            prevPrev = temp;
        }
        
        return prev;
    }
};