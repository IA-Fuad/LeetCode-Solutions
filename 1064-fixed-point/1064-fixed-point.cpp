class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int lo = 0, hi = arr.size(), mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo)/2;

            if (mid <= arr[mid]) hi = mid;
            else lo = mid + 1;
        }
        
        return hi < arr.size() && arr[hi] == hi ? hi : -1;
    }
};