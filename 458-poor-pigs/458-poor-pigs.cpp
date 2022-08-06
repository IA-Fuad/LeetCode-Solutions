class Solution {
    bool canTest(int buckets, int pigs, int state) {
        return pow(state, pigs) >= buckets;
    }
    
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int lo = 0, hi = buckets, mid, ans;
        int state = (minutesToTest / minutesToDie) + 1;
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if (canTest(buckets, mid, state)) {
                hi = mid - 1;
                ans = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};