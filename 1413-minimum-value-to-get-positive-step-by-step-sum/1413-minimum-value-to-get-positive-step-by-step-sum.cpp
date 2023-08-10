class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minValue = INT_MAX;
        for (int num : nums) {
            sum += num;
            minValue = min(minValue, sum);
        }
        
        return max(1 - minValue, 1);
    }
};