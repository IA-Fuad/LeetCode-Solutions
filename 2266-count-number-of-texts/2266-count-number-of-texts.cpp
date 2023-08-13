class Solution {
    const int mod = 1e9 + 7;
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            if (i > 1 and pressedKeys[i-1] == pressedKeys[i-2]) {
                dp[i] = (dp[i] + dp[i-2]) % mod;
                if (i > 2 and pressedKeys[i-1] == pressedKeys[i-3]) {
                    dp[i] = (dp[i] + dp[i-3]) % mod;
                    if (i > 3 and pressedKeys[i-1] == pressedKeys[i-4] and (pressedKeys[i-1] == '7' or pressedKeys[i-1] == '9')) {
                        dp[i] = (dp[i] + dp[i-4]) % mod;
                    }
                }
            }
        }
        
        return dp[n];
    }
};

/*

22233

aaadd
abdd
badd
cdd

aaae
abe
bae
ce





*/