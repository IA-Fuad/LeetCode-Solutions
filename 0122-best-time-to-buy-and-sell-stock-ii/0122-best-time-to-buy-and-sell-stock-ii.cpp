class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, curr = INT_MAX;
        
        for (int price : prices) {
            if (price < curr) {
                curr = price;
                continue;
            }
            profit += (price - curr);
            curr = price;
        }
        
        return profit;
    }
};