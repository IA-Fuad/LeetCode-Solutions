class Solution {
    double getMedian(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int mi = (n + m + 1) / 2;
        int left = 0, right = n;
        bool isOdd = (n + m) & 1;
        
        while (left <= right) {
            int x = left + (right - left) / 2;
            int y = mi - x;
            //cout << isOdd << ' ' << mi << ' ' << x << ' ' << y << endl;
            
            int minA = x == 0 ? INT_MIN : nums1[x-1];
            int minB = y == 0 ? INT_MIN : nums2[y-1];
            int maxA = x >= n ? INT_MAX : nums1[x];
            int maxB = y >= m ? INT_MAX : nums2[y];
            
            if (minA <= maxB and minB <= maxA) {
                return isOdd ? max(minA, minB) : (max(minA, minB) + min(maxA, maxB)) / 2.0;
            }
            if (minA > maxB) {
                right = x - 1;
            }
            else {
                left = x + 1;
            }
        }
        
        return -1;
    } 
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) return getMedian(nums1, nums2);
        return getMedian(nums2, nums1);
    }
};

/*

2 5 8
1 3 7

0 - 2
3 - 5

0 - 4
5 - 5



*/