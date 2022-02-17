class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount+1, INT_MAX);
        
        minCoins[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] > i) continue;
                int needed = i - coins[j];
                if (minCoins[needed] != INT_MAX) {
                    minCoins[i] = min(minCoins[i], minCoins[needed] + 1);
                }
            }
        }
        
        return minCoins[amount] == INT_MAX ? -1 : minCoins[amount];
    }
};