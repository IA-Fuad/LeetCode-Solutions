class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> minFromLeft(n+1), maxFromRight(n+2);
        minFromLeft[0] = INT_MAX;
        maxFromRight[n+1] = INT_MIN;
        
        for (int i = 1, j = n; i <= n; i++, j--) {
            minFromLeft[i] = min(minFromLeft[i-1], nums[i-1]);
            maxFromRight[j] = max(maxFromRight[j+1], nums[j-1]);
        }
        
        for (int i = 1; i <= n; i++) {
            if (nums[i-1] > minFromLeft[i-1] && nums[i-1] < maxFromRight[i+1]) {
                return true;
            }
        }
        
        return false;
    }
};