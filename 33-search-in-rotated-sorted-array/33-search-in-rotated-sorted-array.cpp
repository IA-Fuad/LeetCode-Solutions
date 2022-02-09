class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1, mid, pivot = n-1;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
                pivot = mid;
            }
            else {
                right = mid - 1;
            }
        }

        if (target >= nums[0] && target <= nums[pivot]) {
            left = 0, right = pivot;
        }
        else {
            left = pivot + 1, right = n-1;
        }
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return -1;
    }
};