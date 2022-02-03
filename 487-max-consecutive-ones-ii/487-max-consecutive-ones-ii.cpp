class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zeroCount = 0, lastZeroInd = 0, mxOnes = 0;
        for (int i = 0, l = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
                if (zeroCount > 1) {
                    zeroCount--;
                    l = lastZeroInd + 1;
                }
                lastZeroInd = i;
            }
            mxOnes = max(mxOnes, i - l + 1);
        }
        
        return mxOnes;
    }
};