class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int closestFromLeft[n], closestFromRight[n];
        for (int i = 0, k = -n*2; i < n; i++) {
            if (seats[i] == 1) k = i;
            else closestFromLeft[i] = k;
        }
        for (int i = n-1, k = n*2; i >= 0; i--) {
            if (seats[i] == 1) k = i;
            else closestFromRight[i] = k;
        }
        int maxDist = 1;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) continue;
            maxDist = max(maxDist, min(i - closestFromLeft[i], closestFromRight[i] - i));
        }
        return maxDist;
    }
};