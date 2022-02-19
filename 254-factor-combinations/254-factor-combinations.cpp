class Solution {
    vector<vector<int>> allFactors;
    vector<int> factor;
    
    void rec(int n, int start) {
        if (factor.size() > 0) {
            allFactors.push_back(factor);
            factor.pop_back();
        }
        for (int k = start; k * k <= n; k++) {
            if (n % k == 0) {
                factor.push_back(k);
                factor.push_back(n/k);
                rec(n/k, k);
                factor.pop_back();
                // factor.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> getFactors(int n) {
        rec(n, 2);
        return allFactors;
    }
};