class Solution {
    bool canEatAll(vector<int>& piles, int h, int k) {
        int64_t hours = 0;
        for (int b : piles) {
            hours += ceil(b / (double)k);
            if (hours > h) return false;
        }
        return true;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MAX, mid, k;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (canEatAll(piles, h, mid)) right = mid-1, k = mid;
            else left = mid+1;
        }
        return k;
    }
};