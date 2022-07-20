class Solution {
    const int mod = 1e9 + 7;
    
    int rec(vector<vector<int>>& memo, int n, int k) {
        if (n == 0) return 0;
        if (k == 0) return 1;
        if (memo[n][k] != -1) {
            return memo[n][k];
        }
        
        int pairs = 0;
        for (int i = 0; i <= k and i < n; i++) {
            pairs = (pairs + rec(memo, n-1, k-i)) % mod;
        }
        
        return memo[n][k] = pairs;
    }
    
public:
    int kInversePairs(int n, int k) {
        // vector<vector<int>> memo(n+1, vector<int>(k+1, -1));
        // int ans = rec(memo, n, k);
        // for (int i = 1; i <= k; i++) {
        //     cout << i << "   ";
        // }
        // cout << endl << endl;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= k; j++) {
        //         cout << memo[i][j];
        //         if (memo[i][j] > 99) cout << ' ';
        //         else if (memo[i][j] > 9) cout << "  ";
        //         else cout << "   ";
        //     }
        //     cout << endl;
        // }
        // return ans;
        vector<vector<int64_t>> pairs(n+1, vector<int64_t>(k+1, 0));
        for (int i = 0; i <= n; i++) pairs[i][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            int64_t currSum = 1, sumToRemove = 0;
            for (int j = 1, l = -1; j <= k; j++) {
                if (j >= i) sumToRemove = pairs[i-1][++l];
                currSum = (currSum + pairs[i-1][j] - sumToRemove);
                pairs[i][j] = currSum % mod;
            }
        }
        
        return pairs[n][k];
    }
};