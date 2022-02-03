class Solution {
    unordered_map<int, int> kSumCount;
    
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<vector<int>> nums = {nums1, nums2, nums3, nums4};
        kSum(nums, 0, 0);
        return getKSumCount(nums, nums.size()/2, 0);
    }
    
    void kSum(const vector<vector<int>>& nums, int i, int sum) {
        if (i == nums.size()/2) {
            kSumCount[sum]++;
            return;
        }
        for (int k = 0; k < nums[i].size(); k++) {
            kSum(nums, i+1, sum + nums[i][k]);
        }
    }
    
    int getKSumCount(const vector<vector<int>>& nums, int i, int complement) {
        if (i == nums.size()) {
            auto it = kSumCount.find(complement);
            return it == kSumCount.end() ? 0 : it->second;
        }
        int count = 0;
        for (int k = 0; k < nums[i].size(); k++) {
            count += getKSumCount(nums, i+1, complement - nums[i][k]);
        }
        return count;
    }
};