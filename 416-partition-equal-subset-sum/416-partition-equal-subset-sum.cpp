class Solution {    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum&1) return false;
        
        int target = totalSum / 2;
        
        //vector<bool> c(target+1, false), p(target+1, false);
        vector<bool>* currRow = new vector<bool>(target+1, false);
        vector<bool>* prevRow = new vector<bool>(target+1, false);
        
        (*prevRow)[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {
                (*currRow)[t] = (*prevRow)[t];
                int need = t - nums[i-1];
                if (need < 0) continue;
                (*currRow)[t] = (*currRow)[t] | (*prevRow)[need];
            }
            swap(currRow, prevRow);
        }
        return (*prevRow)[target];
    }
};