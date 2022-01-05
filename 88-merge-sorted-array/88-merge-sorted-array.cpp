class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n+m-1;
        for (int i = m-1, j = n-1;;) {
            if (i < 0 && j < 0) break;
            if (j < 0 || (i >= 0 && nums1[i] > nums2[j])) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};