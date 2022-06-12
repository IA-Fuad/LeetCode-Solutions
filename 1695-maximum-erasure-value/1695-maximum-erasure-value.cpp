class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> numToIndex;
        int maxSum = 0;
        
        for (int l = 0, r = 0, sum = 0; r < nums.size(); r++) {
            sum += nums[r];
            
            auto lastIndex = numToIndex.find(nums[r]);
            if (lastIndex != numToIndex.end()) {
                int d = lastIndex->second;
                while (l <= d) {
                    sum -= nums[l++];
                }
                numToIndex.erase(lastIndex);
            }
            numToIndex[nums[r]] = r;
            
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};