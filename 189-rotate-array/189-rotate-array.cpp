class Solution {
    void reverseNums(vector<int>& nums, int i, int j) {
        for (;i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverseNums(nums, 0, n-1);
        reverseNums(nums, 0, k-1);
        reverseNums(nums, k, n-1);
    }
};