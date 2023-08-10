class Solution {
    const int mod = 1e9 + 7;
    
    int getProduct(vector<int64_t>& powers, int left, int right) {
        int64_t product = 1;
        for (int i = left; i <= right; i++) {
            product *= powers[i];
            product %= mod;
        }
        return product;
    }
    
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int tp = (1 << 30);
        vector<int64_t> powers;
        
        while (n > 0) {
            if (n >= tp) {
                n -= tp;
                powers.push_back(tp);
            }
            else {
                tp >>= 1;
            }
        }
        
        reverse(powers.begin(), powers.end());

        vector<int> result;
        for (auto& query : queries) {
            result.push_back(getProduct(powers, query[0], query[1]));
        }
        
        return result;
    }
};