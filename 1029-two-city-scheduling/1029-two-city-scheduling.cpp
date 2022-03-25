class Solution {
    vector<vector<int>> dp;
    
    int rec(vector<vector<int>>& costs, int i, int A, int B) {
        if (i == costs.size()) {
            return 0;
        }
        if (dp[i][A] != -1) return dp[i][A];
        
        int cityA = INT_MAX, cityB = INT_MAX;
        
        if (A > 0) {
            cityA = rec(costs, i+1, A-1, B) + costs[i][0];
        }
        if (B > 0) {
            cityB = rec(costs, i+1, A, B-1) + costs[i][1];
        }
        
        return dp[i][A] = min(cityA, cityB);
    }
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size();
        dp.resize(N, vector<int>(N+1, -1));
        return rec(costs, 0, N/2, N/2);
    }
};

/*

[[10,15],[30,200],[20,50],[30,20]]

1 3 2 4
1 4 3 2

     A     B
    A B   A B

*/