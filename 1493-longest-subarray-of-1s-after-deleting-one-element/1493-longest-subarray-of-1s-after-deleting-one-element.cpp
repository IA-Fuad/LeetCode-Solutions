class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, consOne = 0, currLen = 0;
        bool hasZero = false;
        
        for (int i = 0; i <= n; i++) {
            if (i == n or nums[i] == 0) {
                maxLen = max(maxLen, currLen + consOne);
                currLen = consOne;
                consOne = 0;
                hasZero |= (i < n);
            }
            else {
                consOne++;
            }
        }
        if (!hasZero) {
            maxLen = max(0, maxLen - 1);
        }
        return maxLen;
    }
};