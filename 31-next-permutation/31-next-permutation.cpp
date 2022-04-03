class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size()-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                int nextLarge = nums[i], nli = i;
                for (int j = nums.size()-1; j >= i; j--) {
                    nli = j;
                    if (nums[j] > nums[i-1]) break;
                }
                //cout << i-1 << ' ' << nli << endl;
                swap(nums[i-1], nums[nli]);
                reverse(nums.begin()+i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};