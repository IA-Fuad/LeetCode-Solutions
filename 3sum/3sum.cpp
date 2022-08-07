class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int siz = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < siz; i++) {
            if (i == 0 or nums[i] != nums[i-1]) {
                for (int l = i+1, r = siz-1; l < r; ) {
                    int sum = nums[l] + nums[i] + nums[r];
                    
                    if (sum == 0 and (l == i+1 or nums[l] != nums[l-1])) {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        l++;
                    }
                    else if (sum < 0) l++;
                    else r--;
                }
            }
        }
        
        return ans;
    }
};