class Solution {
    void getOp(vector<int>& nums, int target, int& minOp) {
        int n = nums.size();
        for (int l = 0, r = 0, sum = 0; r < n; r++) {
            sum += nums[r];
            while (l <= r and sum > target) {
                sum -= nums[l++];
            }
            if (sum == target) {
                minOp = min(minOp, l + (n - r - 1));
            }
        }
    }
    
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x, minOp = INT_MAX;
        
        getOp(nums, target, minOp);
        reverse(nums.begin(), nums.end());
        getOp(nums, target, minOp);
        
        return minOp == INT_MAX ? -1 : minOp;
    }
};


/*

2 3 1 2 2 4 4

*/