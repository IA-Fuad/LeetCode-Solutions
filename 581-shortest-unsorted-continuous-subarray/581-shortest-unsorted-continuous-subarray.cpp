class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int l = nums.size(), r = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != sortedNums[i]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        
        return l > r ? 0 : r - l + 1;
    }
};