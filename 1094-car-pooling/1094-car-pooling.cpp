class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pls;
        for (auto &trip : trips) {
            while(!pls.empty()) {
                auto pl = pls.top();
                if (pl.first <= trip[1]) {
                    capacity += pl.second;
                    pls.pop();
                }
                else break;
            }
            //cout << capacity << ' ' << trip[0] << endl;
            if (capacity < trip[0]) return false;
            capacity -= trip[0];
            pls.push({trip[2], trip[0]});
        }
        return true;
    }
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[2] < b[2];
        return a[1] < b[1];
    }
};