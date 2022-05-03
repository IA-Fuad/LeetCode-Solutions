class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), leftMin = INT_MAX, rightMax = INT_MIN;
        
        for (int i = 1; i < n; i++) {
            if (leftMin != INT_MAX or nums[i] < nums[i-1]) leftMin = min(leftMin, nums[i]);
        }
        
        if (leftMin == INT_MAX) return 0;
        
        for (int i = n-2; i >= 0; i--) {
            if (rightMax != INT_MIN or nums[i] > nums[i+1]) rightMax = max(rightMax, nums[i]);
        }
        
        cout << leftMin << ' ' << rightMax << endl;
        
        int l = -1, r = -1;
        
        for (int i = 0, j = n-1; i < n; i++, j--) {
            if (l == -1 and nums[i] > leftMin) l = i;
            if (r == -1 and nums[j] < rightMax) r = j;
        }

        return r - l + 1;
    }
};