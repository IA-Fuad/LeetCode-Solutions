class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftCount(n, 0), rightCount(n, 0);
        
        int maxConsecutiveOnes = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            else leftCount[i] = leftCount[max(0, i-1)] + 1;
            maxConsecutiveOnes = max(maxConsecutiveOnes, leftCount[i]);
        }

        for (int i = n-1; i >= 0; i--) {
            if (nums[i] == 0) {
                int consecutiveOnes = leftCount[max(0, i-1)] + rightCount[min(n-1, i+1)] + 1;
                maxConsecutiveOnes = max(maxConsecutiveOnes, consecutiveOnes);
            }
            else rightCount[i] = rightCount[min(n-1, i+1)] + 1;
        }
        
        return maxConsecutiveOnes;
    }
};