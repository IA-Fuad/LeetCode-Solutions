class Solution {
    bool hasPPairs(vector<int>& nums, int p, int diff) {
        int pairs = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] <= diff) {
                pairs++;
                i++;
            }
        }
        return pairs >= p;
    }
    
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n-1] - nums[0];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (hasPPairs(nums, p, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return right;
    }
};

/*

1 1 2 3 7 10

0 4 7 9 9 10

4 3 2 0 1

0 1 2 3 4

*/