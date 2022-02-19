class Solution {
    int rec(int ind, vector<int>& costs, vector<int>& dp) {
        if (ind < 0) return 0;
        if (ind < 2) return costs[ind];
        if (dp[ind] != -1) return dp[ind];
        
        dp[ind] = min(rec(ind-1, costs, dp), rec(ind-2, costs, dp)) + costs[ind];
        return dp[ind];
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
//         int minCosts[n];
//         minCosts[0] = minCosts[1] = 0;
        
//         for (int i = 2; i < n; i++) {
//             int a = minCosts[i-1] + cost[i-1];
//             int b = minCosts[i-2] + cost[i-2];
//             if (a < b) minCosts[i] = a;
//             else minCosts[i] = b;
//         }
        
//         return min(minCosts[n-1] + cost[n-1], minCosts[n-2] + cost[n-2]);
        vector<int> dp(n, -1);
        int a = rec(n-1, cost, dp);
        int b = rec(n-2, cost, dp);
       // cout << a << ' ' << b << endl;
        return min(a, b);
    }
};