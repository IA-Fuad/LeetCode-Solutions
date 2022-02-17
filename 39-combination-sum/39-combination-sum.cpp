class Solution {
    void rec(int n, int k, vector<int>& nums, vector<int>& comb, vector<vector<int>>& combs) {
        if (n < 0) return;
        if (n == 0) {
            combs.push_back(comb);
            return;
        }
        for (int i = k; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            rec(n-nums[i], i, nums, comb, combs);
            comb.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> combs;
        
        rec(target, 0, candidates, comb, combs);
        
        return combs;
    }
};