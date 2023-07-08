class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> lessCount(n), greaterCount(n);
        int teams = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (rating[i] > rating[j]) {
                    teams += lessCount[j];
                    lessCount[i]++;
                }
                else {
                    teams += greaterCount[j];
                    greaterCount[i]++;
                }
            }
        }
        
        return teams;
    }
};