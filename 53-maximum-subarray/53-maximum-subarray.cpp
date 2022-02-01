class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > sum+nums[i]) sum = nums[i];
            else sum += nums[i];
            
            mx = max(mx, sum);
        }
        return mx;
    }
};