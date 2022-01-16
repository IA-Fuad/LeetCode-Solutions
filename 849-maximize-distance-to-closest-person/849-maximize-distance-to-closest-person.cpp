class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), ans = 1;
        for (int i = 0, j = 0, leftMostOne = -n*2, rightMostOne; j < n; j++) {
            if (seats[j] == 1 || j == n-1) {
                if (seats[i] == 1) leftMostOne = i;
                rightMostOne = j;
                if (j == n-1 && seats[j] == 0) rightMostOne = n*2;
                
                for (; i <= j; i++) {
                    ans = max(ans, min(i - leftMostOne, rightMostOne - i));
                }
                i--;
            }
        }
        return ans;
    }
};