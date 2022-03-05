class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
//         dp[i][0] = nums[i] + max(dp[j][0], dp[j][1])
//         dp[i][1] += max(dp[i-1][0], dp[i-1][1])
            
//         dp[0][0] = 2;
//         dp[0][1] = 0;
        
//         dp[1][0] = 4;
//         dp[1][1] = 2;
        
//         dp[2][0] = 3;
//         dp[2][1] = 4;
        
//         dp[3][0] = 6;
//         dp[3][1] = 4;
        
//         dp[4][0] = 9;
//         dp[4][1] = 6;
        
//         dp[5][0] = 4;
//         dp[5][1] = 9;

        int n = nums.size();
        vector<vector<int>> earning(n+1, vector<int>(2, 0));
        
        sort(nums.begin(), nums.end());
        
        earning[1][0] = nums[0];
        
        for (int i = 2, j; i <= n; i++) {
            if (nums[i-1] - 1 != nums[i-2]) j = i-1;
            else {
                j = lower_bound(nums.begin(), nums.end(), nums[i-1]-1) - nums.begin();
            }
            earning[i][0] = nums[i-1] + ((nums[i-1] == nums[i-2]) ? earning[i-1][0] : max(earning[j][0], earning[j][1]));
            earning[i][1] = max(earning[i-1][0], earning[i-1][1]);
        }
        
        return max(earning[n][0], earning[n][1]);
    }
};