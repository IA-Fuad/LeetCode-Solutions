class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), N = n*n;
        vector<int> kSmallest;
        
        for (int i = 0, l; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int lb = lower_bound(kSmallest.begin(), kSmallest.end(), matrix[i][j]) - kSmallest.begin();
                if (lb == kSmallest.size()) {
                    if (kSmallest.size() < k) {
                        kSmallest.push_back(matrix[i][j]);
                    }
                }
                else {
                    kSmallest.insert(kSmallest.begin()+lb, 1, matrix[i][j]);
                }
                
                if (kSmallest.size() > k) kSmallest.pop_back();
            }
        }
        
        return kSmallest.back();
    }
};