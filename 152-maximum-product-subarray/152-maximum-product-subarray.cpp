class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0], currentMin = nums[0], mxProduct = nums[0], n = nums.size();
        for (int i = 1; i < n; i++) {
            int mxProd = currentMax * nums[i];
            int mnProd = currentMin * nums[i];
            
            currentMax = max(max(mxProd, mnProd), nums[i]);
            currentMin = min(min(mxProd, mnProd), nums[i]);
            
            mxProduct = max(mxProduct, currentMax);
        }
        return mxProduct;
    }
};