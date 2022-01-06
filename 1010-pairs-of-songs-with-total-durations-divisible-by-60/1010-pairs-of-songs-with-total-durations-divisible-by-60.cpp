class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mark[501] = {0};
        int cnt = 0;
        for (int t : time) {
            int x = (60 - (t % 60)) % 60;
            cnt += mark[x];
            mark[t % 60]++;
        }
        return cnt;
    }
};