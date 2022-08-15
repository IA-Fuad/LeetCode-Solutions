class SparseVector {
    vector<int>* nums;
    vector<int> nonZeroValueIndices;
    
public:
    
    SparseVector(vector<int> &nums) {
        this->nums = &nums;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nonZeroValueIndices.push_back(i);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        
        for (int i = 0; i < nonZeroValueIndices.size(); i++) {
            product += (nums->at(nonZeroValueIndices[i]) * vec.nums->at(nonZeroValueIndices[i]));
        }
        
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);