class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, x = -1, y = -1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                x = mid;
                r = mid - 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        if (x == -1) return {-1, -1};
        y = x, l = x, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                y = mid;
                l = mid + 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return {x, y};
    }
};