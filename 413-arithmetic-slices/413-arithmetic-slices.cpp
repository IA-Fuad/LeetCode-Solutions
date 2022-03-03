class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int totalSlices = 0, slicesAtPrevInd = 0;
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                slicesAtPrevInd++;
                totalSlices += slicesAtPrevInd;
            }
            else {
                slicesAtPrevInd = 0;
            }
        }
        
        return totalSlices;
    }
};