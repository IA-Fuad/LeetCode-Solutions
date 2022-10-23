class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> numCount;
        
        for (int i = 0; i < nums.size(); i++) {
            numCount[nums[i]]++;
        }
        
        int missing = -1, duplicate = -1;
        
        for (int k = 1; k <= nums.size() and (missing == -1 or duplicate == -1); k++) {
            if (numCount.find(k) == numCount.end()) {
                missing = k;
            }
            else if (numCount[k] == 2) {
                duplicate = k;
            }
        }
        
        return {duplicate, missing};
    }
};