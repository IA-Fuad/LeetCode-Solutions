class Solution {
    int getMaxAmount(vector<int>& nums, int start, int end) {
        int currentMax = nums[start], prev = 0;
        
        for (int i = start+1; i < end; i++) {
            int temp = currentMax;
            currentMax = max(currentMax, prev + nums[i]);
            prev = temp;
        }
        
        return currentMax;
    }
    
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        return max(getMaxAmount(nums, 0, nums.size()-1), getMaxAmount(nums, 1, nums.size()));
    }
};