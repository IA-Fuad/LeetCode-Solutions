class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {        
        int64_t cnt = 0, product = 1, remove = 1;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            while (product / remove >= k and left < right) {
                remove *= nums[left++];
            }
            
            if (product / remove < k) {
                cnt += (right - left + 1);
            }
            
            product /= remove;
            remove = 1;
        }
        
        return cnt;
    }
};


/*

10 50 100 600

10 50


*/