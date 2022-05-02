class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            if (n % 2 == 0) ans.push_back(n);
        }
        for (int n : nums) {
            if (n & 1) ans.push_back(n);
        }
        return ans;
    }
};