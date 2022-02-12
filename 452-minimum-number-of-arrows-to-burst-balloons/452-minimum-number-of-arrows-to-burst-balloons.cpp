class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] < y[0];
        });
        
        int minArrowShots = 1, end = points[0][1];
        //cout << points[0][0] << ' ' << points[0][1] << endl;
        for (int i = 1; i < points.size(); i++) {
            //cout << points[i][0] << ' ' << points[i][1] << endl;
            if (points[i][0] > end) {
                minArrowShots++;
                end = points[i][1];
            }
            else end = min(end, points[i][1]);
        }
        
        return minArrowShots;
    }
};