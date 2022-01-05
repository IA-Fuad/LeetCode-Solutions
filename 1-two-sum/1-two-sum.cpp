class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mark;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mark.find(target-nums[i]);
            if (it != mark.end()) return {i, it->second};
            mark[nums[i]] = i;
        }
        return {};
    }
};