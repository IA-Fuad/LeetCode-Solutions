class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> numCount;
        for (int num : nums) {
            numCount[num]++;
        }
        
        int lastNum = -1, prevTaken = 0, prevNotTaken = 0, take = 0, doNotTake = 0;
        
        for (auto it : numCount) {
            int gain = it.first * it.second;

            if (lastNum + 1 == it.first) {
                take = max(gain + prevNotTaken, prevTaken);
            }
            else {
                take = gain + max(prevTaken, prevNotTaken);
            }
            
            prevNotTaken = max(prevTaken, prevNotTaken);
            prevTaken = take;
            lastNum = it.first;
        }
        
        return max(prevTaken, prevNotTaken);
    }
};