class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int mx = nums[i], mn = nums[i];
            for (int j = i+1; j < n; j++) {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                
                ans += (mx - mn);
            }
        }
        
        return ans;
    }
};


/*

1 2 4 1 3

1 2 4 


*/