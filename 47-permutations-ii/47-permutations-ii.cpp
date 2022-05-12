class Solution {
    vector<vector<int>> ans;
    vector<bool> vis;
    
    void rec(vector<int> nums, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int k = i; k < nums.size(); k++) {
            if (i != k and nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            rec(nums, i+1);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        rec(nums, 0);
        
        return ans;
    }
};