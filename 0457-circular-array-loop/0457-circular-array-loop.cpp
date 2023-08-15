class Solution {
    int getNext(vector<int>& nums, int i) {
        int k = i + nums[i];
        if (k < 0) return (k + nums.size()) % nums.size();
        return k % nums.size();
    }
    
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            
            int slow = i, fast = getNext(nums, i);
            
            while (nums[i] * nums[fast] > 0 and nums[i] * nums[getNext(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow != getNext(nums, slow)) return true;
                    break;
                }
                
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
            }
            
            int k = i;
            while (nums[k] > 0) {
                nums[k] = 0;
                k = getNext(nums, k);
            }
        }
        
        return false;
    }
};