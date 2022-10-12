class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        
        for (int i = 0; i < nums.size()-2; i++) {
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            
            if (a + b > c and a + c > b and b + c > a) {
                return a + b + c;
            }
        }
        
        return 0;
    }
};