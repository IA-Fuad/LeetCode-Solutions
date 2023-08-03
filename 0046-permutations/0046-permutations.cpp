class Solution {
    void rec(vector<vector<int>>& ans, vector<int>& nums, int k) {
        if (k == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = k; i < nums.size(); i++) {
            swap(nums[i], nums[k]);
            rec(ans, nums, k + 1);
            swap(nums[i], nums[k]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(ans, nums, 0);
        return ans;
    }
};