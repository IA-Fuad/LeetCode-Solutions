class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, len = INT_MAX, i, j;
        for (i = 0, j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum - nums[i] >= target and i < j) {
                sum -= nums[i++];
            }
            if (sum >= target) {
                len = min(len, j - i + 1);
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};