class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = INT_MIN, buy = -prices[0], prevSell, n = prices.size();
        for (int i = 1; i < n; i++) {
            prevSell = max(0, sell);
            sell = max(sell, buy + prices[i] - fee);
            buy = max(buy, prevSell - prices[i]);
            //cout << prices[i] << ' ' << sell << ' ' << buy << endl;
        }
        return max(0, sell);
    }
};