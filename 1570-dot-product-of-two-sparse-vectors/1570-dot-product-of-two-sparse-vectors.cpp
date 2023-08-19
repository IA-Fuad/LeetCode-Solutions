class SparseVector {
    vector<pair<int, int>> sVec;
    
    int getDotProduct(vector<pair<int, int>>& nums1, vector<pair<int, int>>& nums2) {
        int i = 0, j = 0, product = 0;
        
        while (i < nums1.size() and j < nums2.size()) {
            if (nums1[i].first == nums2[j].first) {
                product += (nums1[i].second * nums2[j].second);
                i++;
                j++;
            }
            else if (nums1[i].first < nums2[j].first) i++;
            else j++;
        }
        
        return product;
    }
    
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                sVec.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        return getDotProduct(this->sVec, vec.sVec);
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);