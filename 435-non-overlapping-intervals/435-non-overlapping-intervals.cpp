class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) {
            return x[1] < y[1];
        });
        
        int erasedIntervalCount = 0;
        for (int i = 1, k = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[k][1]) {
                erasedIntervalCount++;
            }
            else {
                k = i;
            }
        }
        
        return erasedIntervalCount;
    }
};