class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> inc(n), dec(n);
        dec[0] = inc[n-1] = 1;
        
        for (int i = 1, j = n-2; i < n; i++, j--) {
            dec[i] = (nums[i] <= nums[i-1]) ? (dec[i-1] + 1) : 1;
            inc[j] = (nums[j] <= nums[j+1]) ? (inc[j+1] + 1) : 1;
        }

        vector<int> goodInd;
        for (int i = k; i < n-k; i++) {
            if (dec[i-1] >= k and inc[i+1] >= k) {
                goodInd.push_back(i);
            }
        }
        
        return goodInd;
    }
};