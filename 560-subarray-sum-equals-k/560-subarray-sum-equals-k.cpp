class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currentSum = 0, subArrays = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        
        for (int n : nums) {
            currentSum += n;
            auto it = prefixSumCount.find(currentSum - k);
            if (it != prefixSumCount.end()) {
                subArrays += it->second;
            }
            prefixSumCount[currentSum]++;
        }
        
        return subArrays;
    }
};