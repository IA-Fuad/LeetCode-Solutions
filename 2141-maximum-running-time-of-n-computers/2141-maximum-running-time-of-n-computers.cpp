class Solution {
    bool canRun(vector<int>& bat, long long minutes, long long n) {
        long long minutesNeedToRun = minutes * n;
        for (long long b : bat) {
            minutesNeedToRun -= min(minutes, b);
        }
        return minutesNeedToRun <= 0;
    }
    
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalMinutes = accumulate(batteries.begin(), batteries.end(), 0ll);
        long long left = 1, right = totalMinutes;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRun(batteries, mid, n)) left = mid+1;
            else right = mid-1;
        }
        
        return right;
    }
};