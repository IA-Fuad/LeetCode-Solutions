class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        
        for (int i = 0; i < 32; i++) {
            int ones = 0;
            for (int n : nums) {
                if (n & (1<<i)) {
                    ones++;
                }
            }
            if (ones > nums.size()/2) {
                candidate |= (1 << i);
            }
        }
        
        return candidate;
    }
};