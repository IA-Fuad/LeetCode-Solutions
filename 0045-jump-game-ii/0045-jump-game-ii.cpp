class Solution {
public:
    int jump(vector<int>& nums) {
        int currFurthest = 0, currEnd = 0;
        int jumpCount = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            currFurthest = max(currFurthest, i + nums[i]);
            
            if (i == currEnd) {
                jumpCount++;
                currEnd = currFurthest;
            }
        }
        
        return jumpCount;
    }
};