class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j, cnt;
        for (i = 1, j = 1, cnt = 1; j < nums.size(); j++) {
            if (nums[j] == nums[i-1]) cnt++;
            else cnt = 1;
            swap(nums[i], nums[j]);
            //cout << i << ' ' << j << ' ' << cnt << endl;
            if (cnt < 3) i++;
        }
        return i;
    }
};