class Solution {
    vector<vector<int>> dp;
    
    int rec(vector<int>& cuts, int i, int j) {
        if (j - i <= 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int minCost = INT_MAX;
        
        for (int k = i+1; k < j; k++) {
            int cost = rec(cuts, i, k) + rec(cuts, k, j) + (cuts[j] - cuts[i]);  
            minCost = min(minCost, cost);
        }
        
        return dp[i][j] = minCost;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        dp.resize(cuts.size()+2, vector<int>(cuts.size()+2, -1));
        
        return rec(cuts, 0, cuts.size()-1);
    }
};