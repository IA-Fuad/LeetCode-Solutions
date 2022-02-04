class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int mxSumAfterOp = 0, mxSumWithoutOp = 0, sum = 0, mx = 0;
        
        for (int n : nums) {
            mxSumAfterOp = max(mxSumAfterOp + n, sum + (n * n));
            sum += n;
            if (sum < 0) sum = 0;
            mxSumWithoutOp = max(mxSumWithoutOp, sum);
            mx = max(mx, mxSumAfterOp);
            //cout << mxSumWithoutOp << ' ' << mxSumAfterOp << endl;
        }
        
        return mx;
    }
};