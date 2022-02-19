class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        
        for (int n : nums) {
            int lp = lower_bound(lis.begin(), lis.end(), n) - lis.begin();
            if (lp == lis.size()) {
                lis.push_back(n);
            }
            else {
                lis[lp] = n;
            }
        }
        
        return lis.size();
    }
};