class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 1));
        
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] > nums[i]) {
                    if (dp[j][0]+1 > dp[i][1]) {
                        dp[i][1] = dp[j][0] + 1;
                    }
                }
                if (nums[j] < nums[i]) {
                    if (dp[j][1]+1 > dp[i][0]) {
                        dp[i][0] = dp[j][1] + 1;
                    }
                }
            }
            //cout << dp[i][0] << ' ' << dp[i][1] << endl;
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};