class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnTillNow = prices[0], ans = 0;
        for (int p : prices) {
            ans = max(ans, p - mnTillNow);
            mnTillNow = min(mnTillNow, p);
        }
        return ans;
    }
};