class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mark;
        mark[0] = -1;
        int sum = 0, mxLen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] == 0 ? -1 : 1;
            sum += x;
            auto sumInd = mark.find(sum);
            if (sumInd == mark.end()) {
                mark[sum] = i;
            }
            else {
                mxLen = max(mxLen, i - sumInd->second);
            }
        }
        
        return mxLen;
    }
};