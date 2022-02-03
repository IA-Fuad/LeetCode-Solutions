class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> pairSum;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                pairSum[n1+n2]++;
            }
        }
        
        int tupleCount = 0;
        
        for (int n3 : nums3) {
            for (int n4 : nums4) {
                int numberNeedToMakeZero = -(n3 + n4);
                tupleCount += pairSum[numberNeedToMakeZero];
            }
        }
        
        return tupleCount;
    }
};