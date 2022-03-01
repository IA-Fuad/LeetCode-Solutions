class Solution {
public:
    vector<int> countBits(int n) {
        int offset = 1;
        vector<int> ans(n+1);
        
        for (int i = 1; i <= n; i++) {
            if ((offset<<1) == i) offset = i;
            ans[i] = ans[i-offset] + 1;
        }
        
        return ans;
    }
};