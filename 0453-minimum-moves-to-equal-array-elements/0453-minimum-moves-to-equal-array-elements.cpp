class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int moves = 0;
        
        for (int i = nums.size()-1; i > 0; i--) {
            moves += (nums[i] - nums[0]);
        }
        
        return moves;
    }
};