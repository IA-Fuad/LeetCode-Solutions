class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mark[61] = {0};
        int cnt = 0;
        for (int t : time) {
            int x = (60 - (t % 60));
            if (x == 60) x = 0;
            cnt += mark[x];
            mark[t % 60]++;
        }
        return cnt;
    }
};