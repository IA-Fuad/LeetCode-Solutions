class Solution {
    vector<vector<int>> powerSet;
    
    void rec(vector<int>& nums, int i, vector<int>& subSet) {
        if (i == nums.size()) {
            powerSet.push_back(subSet);
            return;
        }
        
        subSet.push_back(nums[i]);
        rec(nums, i+1, subSet);
        subSet.pop_back();
        rec(nums, i+1, subSet);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subSet;
        rec(nums, 0, subSet);
        return powerSet;
    }
};