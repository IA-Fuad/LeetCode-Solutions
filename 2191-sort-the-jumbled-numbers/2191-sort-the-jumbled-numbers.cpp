class Solution {
    int convertNum(vector<int>& mapping, int num) {
        if (num == 0) return mapping[0];
        stack<int> digits;
        while (num > 0) {
            digits.push(mapping[num % 10]);
            num /= 10;
        }
        int cNum = 0;
        while (!digits.empty()) {
            cNum = (cNum * 10) + (digits.top());
            digits.pop();
        }
        return cNum;
    }
    
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mappedNums;
        for (int num : nums) {
            mappedNums[num] = convertNum(mapping, num);
        }
        
        sort(nums.begin(), nums.end(), [&](int x, int y) {
           return mappedNums[x] < mappedNums[y];
        });
        return nums;
    }
};