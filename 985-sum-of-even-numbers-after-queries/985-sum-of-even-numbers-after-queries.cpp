class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                evenSum += num;
            }
        }
        
        vector<int> evenSums;
        
        for (auto& query : queries) {
            int val = query[0], ind = query[1];
            
            if (nums[ind] % 2 == 0) evenSum -= nums[ind];
            nums[ind] += val;
            
            if (nums[ind] % 2 == 0) evenSum += nums[ind];
            
            evenSums.push_back(evenSum);
        }
        
        return evenSums;
    }
};