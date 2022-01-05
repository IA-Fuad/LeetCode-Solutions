class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0, j = nums.size()-1; i <= j;) {
            if (abs(nums[i]) > nums[j]) ans.push_back(nums[i]*nums[i]), i++;
            else ans.push_back(nums[j]*nums[j]), j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};