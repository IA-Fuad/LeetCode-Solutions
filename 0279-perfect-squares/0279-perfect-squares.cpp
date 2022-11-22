class Solution {
    vector<int> dp;
    
    int rec(vector<int>& nums, int n) {
        if (n == 0) return 0;
        if (n < 0) return 1e5;
        if (dp[n] != -1) return dp[n];
        
        int mn = 1e5;
        
        for (int i = nums.size()-1; i >= 0; i--) {
            mn = min(mn, rec(nums, n-nums[i]) + 1);
        }
        
        return dp[n] = mn;
    }
    
public:
    int numSquares(int n) {
        dp.resize(n+1, 100000);
        vector<int> nums;
        
        for (int i = 1; i * i <= n; i++) {
            nums.push_back(i*i);
        }
        
        //   return rec(nums, n);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int sq : nums) {
                if (sq > i) break;
                dp[i] = min(dp[i], dp[i-sq] + 1);
            }
        }
        
        return dp[n];
    }
};