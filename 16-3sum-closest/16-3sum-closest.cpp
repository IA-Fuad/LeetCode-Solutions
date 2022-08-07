class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = INT_MAX, ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            for (int l = i+1, r = nums.size()-1; l < r;) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum == target) return sum;
                
                if (sum < target) l++;
                else r--;
                
                if (abs(target - sum) < closestSum) {
                    closestSum = abs(target - sum);
                    ans = sum;
                }
            }
        }
        
        return ans;
    }
};