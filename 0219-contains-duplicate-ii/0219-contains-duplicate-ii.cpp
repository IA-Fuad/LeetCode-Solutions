class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numInd;
        
        for (int i = 0; i < nums.size(); i++) {
            auto it = numInd.find(nums[i]);
            if (it != numInd.end() and abs(it->second-i) <= k) {
                return true;
            }
            numInd[nums[i]] = i;
        }
        
        return false;
    }
};