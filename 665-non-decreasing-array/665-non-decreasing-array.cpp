class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool allowed = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                if (!allowed) return false;
                if (i == nums.size()-1) return true;
                if (nums[i+1] < nums[i-1]) {
                    if (i-1 > 0 and nums[i-2] > nums[i]) return false;
                }
                else {
                    nums[i] = nums[i-1];
                }
                allowed = false;
            }
        }
        return true;
    }
};