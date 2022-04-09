class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        for (int n : nums) {
            numCount[n]++;
        }
        
        vector<vector<int>> sortedByCount(nums.size());
        vector<int> ans;
        
        for (auto n : numCount) {
            sortedByCount[n.second-1].push_back(n.first);
        }
        
        for (int i = nums.size()-1; i >= 0 and k > 0; i--) {
            if (sortedByCount[i].size() > 0) {
                for (int j = 0; j < sortedByCount[i].size() and k > 0; j++) {
                    ans.push_back(sortedByCount[i][j]);
                    k--;
                }
            }
        }
        
        return ans;
    }
};