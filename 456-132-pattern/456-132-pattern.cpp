class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        stack<int> ott;
        vector<int> minNums(n);
        minNums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            minNums[i] = min(minNums[i-1], nums[i]);
        }
        
        ott.push(nums[n-1]);
        
        for (int j = n-2; j > 0; j--) {
            if (minNums[j] == nums[j]) continue;
            while (!ott.empty() and ott.top() <= minNums[j]) {
                ott.pop();
            }
            if (!ott.empty() and ott.top() < nums[j]) {
                return true;
            }
            ott.push(nums[j]);
        }
        
        return false;
    }
};