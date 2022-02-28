class Solution {
    string getRange(vector<int>& nums, int i, int j) {
        if (i == j) {
            return to_string(nums[i]);
        }
        return to_string(nums[i]) + "->" + to_string(nums[j]);
    }
    
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> ranges;
        int i, j;
        for (i = 0, j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[j-1] + 1) {
                string range = getRange(nums, i, j-1);
                ranges.push_back(range);
                i = j;
            }
        }
        ranges.push_back(getRange(nums, i, j-1));
        return ranges;
    }
};