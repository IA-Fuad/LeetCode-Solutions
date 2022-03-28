class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, pivot = 0;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target) return true;
            
            if (nums[lo] == nums[mid]) {
                lo++;
                continue;
            }
            
            bool pa = nums[lo] <= nums[mid];
            bool ta = nums[lo] <= target;
            
            if (pa != ta) {
                if (pa) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            else {
                if (nums[mid] < target) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
        
        return false;
    }
};

/*

2,5,6,0,0,1,2



6,6,7,0,1,2,4,4,4,5

lo = 0, hi = 3
lo = 1, hi = 3
lo = 2, hi = 3

*/