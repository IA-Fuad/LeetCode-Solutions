class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for (int i = 0; i < points.size(); i++) {
            auto p = points[i];
            q.push({p[0]*p[0]+p[1]*p[1], i});
        }
        vector<vector<int>> ans;
        while (k > 0) {
            ans.push_back(points[q.top().second]);
            q.pop(), k--;
        }
        return ans;
    }
};