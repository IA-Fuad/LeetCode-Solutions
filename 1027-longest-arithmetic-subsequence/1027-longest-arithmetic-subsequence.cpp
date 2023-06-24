class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), las = 1;
        vector<vector<int>> as(n, vector<int>(2000));

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                if (diff < 0) {
                    diff += 1000;
                }
                if (as[j][diff] + 1 > as[i][diff]) {
                    as[i][diff] = as[j][diff] + 1;
                    las = max(las, as[i][diff]);
                }
            }
        }

        return las + 1;
    }
};