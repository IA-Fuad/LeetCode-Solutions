class Solution {
    vector<vector<int>> dp;
    
    int getMxUnCrossedLines(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == nums1.size() || j == nums2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (nums1[i] == nums2[j]) {
            dp[i][j] = getMxUnCrossedLines(nums1, nums2, i+1, j+1) + 1;
        }
        else {
            dp[i][j] = max(getMxUnCrossedLines(nums1, nums2, i+1, j), getMxUnCrossedLines(nums1, nums2, i, j+1));
        }
        
        return dp[i][j];
    }
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
        // return getMxUnCrossedLines(nums1, nums2, 0, 0);
        
        dp.resize(nums1.size()+1, vector<int>(nums2.size()+1));
        
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[nums1.size()][nums2.size()];
    }
};