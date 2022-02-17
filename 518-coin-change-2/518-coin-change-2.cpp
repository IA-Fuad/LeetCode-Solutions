class Solution {
    vector<vector<int>> dp;
    
    int rec(int n, int k, vector<int>& coins) {
        int combs = 0;

        if (dp[n][k] != -1) {
            return dp[n][k];
        }
        
        for (int i = k; i < coins.size(); i++) {
            if (coins[i] > n) break;
            if (coins[i] == n) combs++;
            else {
                combs += rec(n - coins[i], i, coins);
            }
        }
        
        return dp[n][k] = combs;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        dp.resize(amount+1, vector<int>(coins.size(), -1));
        sort(coins.begin(), coins.end());
        return rec(amount, 0, coins);
    }
};