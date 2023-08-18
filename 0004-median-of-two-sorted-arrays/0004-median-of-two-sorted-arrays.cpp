class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size(), n = nums2.size();
        int medianInd = (m + n + 1) / 2;
        int left = 0, right = m;
        bool isOdd = (m + n) & 1;
        
        while (left <= right) {
            int x = left + (right - left) / 2;
            int y = medianInd - x;
            
            int leftMaxA = x == 0 ? INT_MIN : nums1[x-1];
            int rightMinA = x == m ? INT_MAX : nums1[x];
            int leftMaxB = y == 0 ? INT_MIN : nums2[y-1];
            int rightMinB = y == n ? INT_MAX : nums2[y];
            
            if (leftMaxA <= rightMinB and leftMaxB <= rightMinA) {
                return isOdd ? max(leftMaxA, leftMaxB) : (max(leftMaxA, leftMaxB) + min(rightMinA, rightMinB)) / 2.0;
            }
            if (leftMaxA > rightMinB) {
                right = x - 1;
            }
            else {
                left = x + 1;
            }
        }
        
        return -1;
    }
};