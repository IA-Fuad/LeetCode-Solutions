class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1.size(), m = nums2.size();
        int left = 0, right = n, medianInd = (n + m + 1) / 2;
        
        while (left <= right) {
            int x = (left + right) / 2;
            int y = medianInd - x;
            
            double leftMaxA = x == 0 ? INT_MIN : nums1[x-1];
            double rightMinA = x == n ? INT_MAX : nums1[x];
            double leftMaxB = y == 0 ? INT_MIN : nums2[y-1];
            double rightMinB = y == m ? INT_MAX : nums2[y];
            
            if (leftMaxA <= rightMinB and leftMaxB <= rightMinA) {
                return ((n + m) & 1) ? max(leftMaxA, leftMaxB) : (max(leftMaxA, leftMaxB) + min(rightMinA, rightMinB)) / 2.0;
            }
            if (leftMaxA > rightMinB) {
                right = x - 1;
            }
            else {
                left = x + 1;
            }
        }
        
        return 0;
    }
};