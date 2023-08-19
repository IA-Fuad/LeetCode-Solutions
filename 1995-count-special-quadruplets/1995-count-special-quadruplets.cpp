class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        unordered_map<int, int> pairCount;
        pairCount[nums[0] + nums[1]] = 1;
        
        for (int i = 2; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cnt += pairCount[nums[j] - nums[i]];
            }
            
            for (int j = 0; j < i; j++) {
                pairCount[nums[j] + nums[i]]++;
            }
        }
        
        return cnt;
    }
};