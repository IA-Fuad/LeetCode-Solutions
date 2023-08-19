class Solution {
    void rec(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& powerset) {
        if (i == nums.size()) {
            powerset.push_back(sub);
            return;
        }
        
        sub.push_back(nums[i]);
        rec(nums, i + 1, sub, powerset);
        sub.pop_back();
        rec(nums, i + 1, sub, powerset);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> sub;
        
        rec(nums, 0, sub, powerset);
        
        return powerset;
    }
};