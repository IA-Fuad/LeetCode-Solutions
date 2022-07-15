class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> dists(n, vector<int>(4, n));
        
        for (int i = 0, j = n-1; i < n; i++, j--) {
            for (int color = 1; color <= 3; color++) {
                if (colors[i] == color) dists[i][color] = 0;
                if (colors[j] == color) dists[j][color] = 0;
                if (i == 0) continue;
                dists[i][color] = min(dists[i-1][color]+1, dists[i][color]);
                dists[j][color] = min(dists[j+1][color]+1, dists[j][color]);
            }
        }
        
        vector<int> ans;
        for(auto& query : queries) {
            int dist = dists[query[0]][query[1]];
            ans.push_back(dist == n ? -1 : dist);
        }
        
        return ans;
    }
};