class Solution {
    int rec(vector<vector<int>>& dp, vector<vector<int>>& flights, vector<vector<int>>& days, int city, int week) {
        if (week == days[0].size()) return 0;
        if (dp[city][week] != -1) return dp[city][week];
        
        int maxVacation = INT_MIN;
        
        for (int c = 0; c < flights[city].size(); c++) {
            if (c == city or flights[city][c] == 1) {
                maxVacation = max(maxVacation, rec(dp, flights, days, c, week+1) + days[c][week]);
            }
        }
        
        return dp[city][week] = maxVacation;
    }
    
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        vector<vector<int>> dp(flights.size(), vector<int>(days.size(), -1));
        return rec(dp, flights, days, 0, 0);
    }
};

/*
   0 1 2
0 [0,1,1]
1 [1,0,1]
2 [1,1,0]

   1 2 3
0 [1,3,1]
1 [6,0,3]
2 [3,3,3]

int week = 1
for c = 1 to city[i]
    if city[i][c] == 1 or c == i:
        ans = max(ans, rec(c, week+1) + days[c][week])
        
        

                           0
                    0      1      2 (6+6 = 12)
                0   1   2 -> (3+3 = 6)
              0 1 2 -> (3)
*/