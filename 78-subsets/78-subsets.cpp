class Solution {
    vector<vector<int>> powerSet;
    
    void rec(vector<int>& nums, int i, vector<int> subSet) {
        if (i == nums.size()) {
            powerSet.push_back(subSet);
            return;
        }
        
        auto taken = subSet;
        taken.push_back(nums[i]);
        rec(nums, i+1, taken);
        rec(nums, i+1, subSet);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        rec(nums, 0, {});
        return powerSet;
    }
};