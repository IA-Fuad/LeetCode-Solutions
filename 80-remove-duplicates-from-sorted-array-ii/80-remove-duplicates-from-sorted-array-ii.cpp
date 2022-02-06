class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j, cnt;
        for (i = 1, j = 1, cnt = 1; j < nums.size(); j++) {
            if (nums[j] == nums[j-1]) cnt++;
            else cnt = 1;
            nums[i] = nums[j];
            if (cnt < 3) i++;
        }
        return i;
    }
};