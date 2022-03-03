class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> arithmeticSlices(nums.size(), 0);
        int totalSlices = 0;
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                arithmeticSlices[i] = arithmeticSlices[i-1] + 1;
                totalSlices += arithmeticSlices[i];
            }
        }
        
        return totalSlices;
    }
};