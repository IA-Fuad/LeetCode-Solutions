class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProducts(n+2), suffixProducts(n+2), ans;
        
        prefixProducts[0] = 1;
        for (int i = 1; i <= n; i++) {
            prefixProducts[i] = nums[i-1] * prefixProducts[i-1];
        }
        
        suffixProducts[n+1] = 1;
        for (int i = n; i > 0; i--) {
            suffixProducts[i] = nums[i-1] * suffixProducts[i+1];
        }
        
        for (int i = 1; i <= n; i++) {
            ans.push_back(prefixProducts[i-1] * suffixProducts[i+1]);
        }
        
        return ans;
    }
};