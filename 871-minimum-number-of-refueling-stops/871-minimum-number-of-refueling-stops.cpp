class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> Q;
        int fuel = startFuel, refuel = 0, prevStation = 0;
        
        for (int i = 0; i <= n; i++) {
            int currDist = i < n ? stations[i][0] : target;
            int stationFuel = i < n ? stations[i][1] : 0;
            fuel -= (currDist - prevStation);

            while (!Q.empty() and fuel < 0) {
                fuel += Q.top();
                Q.pop();
                refuel++;
            }

            if (fuel < 0) {
                return -1;
            }
            
            Q.push(stationFuel);
            prevStation = currDist;
        }
        
        return refuel;
    }
};