class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mark[501] = {0};
        int cnt = 0;
        for (int t : time) {
            int x = 60 - (t % 60);
            for (int i = x; i <= 500; i += 60) {
                cnt += mark[i];
            }
            mark[t]++;
        }
        return cnt;
    }
};