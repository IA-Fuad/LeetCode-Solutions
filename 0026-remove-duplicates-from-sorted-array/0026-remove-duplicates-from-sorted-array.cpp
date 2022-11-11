class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (j < nums.size()-1 and nums[j] == nums[j+1]) {
                int num = nums[j];
                while (j < nums.size() and num == nums[j]) {
                    j++;
                }
                j--;
                
                nums[k++] = num;
            }
            else {
                nums[k++] = nums[j];
            }
        }
        return k;
    }
};