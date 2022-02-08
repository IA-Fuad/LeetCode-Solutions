class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> setSizes(n, 1), parent(n, -1);
        int largestSetSize = 1, largestSetSizeAtIndex = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i]%nums[j] == 0 && setSizes[j]+1 > setSizes[i]) {
                    setSizes[i] = setSizes[j] + 1;
                    parent[i] = j;
                }
            }
            if (setSizes[i] > largestSetSize) {
                largestSetSize = setSizes[i];
                largestSetSizeAtIndex = i;
            }
        }
        
        vector<int> largestSubSet;
        largestSubSet.push_back(nums[largestSetSizeAtIndex]);
        
        int i = largestSetSizeAtIndex;
        while (parent[i] != -1) {
            i = parent[i];
            largestSubSet.push_back(nums[i]);
        }
        
        return largestSubSet;
    }
};