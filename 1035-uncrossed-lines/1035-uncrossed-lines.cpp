class Solution {
    unordered_map<int, vector<int>> indices;
    vector<vector<int>> dp;
    
    int getMxUnCrossedLines(vector<int>& nums, int n1, int n2, int i, int j) {
        if (i == n1 || j == n2) return 0;
        if (dp[i][j+1] != -1) return dp[i][j+1];
        
        int taken = 0, notTaken = 0;
        auto inds = indices.find(nums[i]);
        if (inds != indices.end()) {
            int indx = upper_bound(inds->second.begin(), inds->second.end(), j) - inds->second.begin();
            if (indx != inds->second.size()) {
                taken = getMxUnCrossedLines(nums, n1, n2, i+1, inds->second[indx]) + 1;
            }
        }
        notTaken = getMxUnCrossedLines(nums, n1, n2, i+1 ,j);
        
        return dp[i][j+1] = max(taken, notTaken);
    }
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); i++) {
            indices[nums2[i]].push_back(i);
        }
        dp.resize(nums1.size(), vector<int>(nums2.size()+1, -1));
        return getMxUnCrossedLines(nums1, nums1.size(), nums2.size(), 0, -1);
    }
};