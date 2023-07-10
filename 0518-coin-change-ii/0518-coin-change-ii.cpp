class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int k = 1; k <= amount; k++) {
                if (k >= coin) {
                    dp[k] += dp[k - coin];
                }
                //cout << dp[k] << ' ';
            }
            //cout << endl << endl;
        }
        
        return dp[amount];
    }
};

/*

1
1 = 1
2 = 1
3 = 1

2
dp[2] = 

*/