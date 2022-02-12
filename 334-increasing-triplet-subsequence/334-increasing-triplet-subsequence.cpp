class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        int smallest = nums[0], secondSmallest = INT_MAX;

        for (int i = 1; i < n; i++) {
            if (nums[i] > secondSmallest) return true;
            if (nums[i] < smallest) {
                smallest = nums[i];
            }
            else if (nums[i] < secondSmallest && nums[i] != smallest) {
                secondSmallest = nums[i];
            }
        }
        
        return false;
    }
};