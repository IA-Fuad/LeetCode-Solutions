class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1, mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo)/2;

            if (mid <= arr[mid]) hi = mid;
            else lo = mid + 1;
        }
        
        return arr[hi] == hi ? hi : -1;
    }
};