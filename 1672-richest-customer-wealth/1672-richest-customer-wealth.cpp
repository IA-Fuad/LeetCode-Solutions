class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mxWealth = 0;
        for (auto account : accounts) {
            int wealth = 0;
            for (int money : account) {
                wealth += money;
            }
            mxWealth = max(mxWealth, wealth);
        }
        return mxWealth;
    }
};