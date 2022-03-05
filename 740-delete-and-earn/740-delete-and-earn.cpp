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

        int n = nums.size(), ans = 0;
        map<int, int> numCount;

        for (int num : nums) {
            numCount[num]++;
        }
        
        vector<vector<int>> earning(numCount.size()+1, vector<int>(2, 0));
        
        int i = 1, lastNumber = -1, take = 0, doNotTake = 0;
        
        for (auto it : numCount) {
            int gain = it.first * it.second;
            int prevTake = take, prevDoNotTake = doNotTake;
            
            if (lastNumber+1 == it.first) {
                take = max(prevTake, prevDoNotTake + gain);
            }
            else {
                take = gain + max(prevTake, prevDoNotTake);
            }
            
            doNotTake = max(prevTake, prevDoNotTake);
            lastNumber = it.first;
            i++;
        }
        
        return max(take, doNotTake);
    }
};