class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int triplets = 0;
        
        for (int k = 2; k < nums.size(); k++) {
            int left = 0, right = k - 1;
            
            while (left < right) {
                if (nums[left] + nums[right] + nums[k] < target) {
                    triplets += (right - left);
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return triplets;
    }
};

/*

-2 0 0 2 2

*/