class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mark[501] = {0};
        int cnt = 0;
        for (int t : time) {
            for (int i = 1; i <= 500; i++) {
                if (mark[i] > 0) {
                    int x = t + i;
                    if (x % 60 == 0) cnt += mark[i];
                }
            }
            mark[t]++;
        }
        return cnt;
    }
};