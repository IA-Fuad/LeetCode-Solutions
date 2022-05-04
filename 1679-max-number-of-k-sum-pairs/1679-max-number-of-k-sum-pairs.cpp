class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int op = 0;
        
        for (int i = 0, j = nums.size()-1; i < j;) {
            if (nums[i] + nums[j] == k) {
                op++;
                i++, j--;
            }
            else if (nums[i] + nums[j] < k) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return op;
    }
};