class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        nth_element(begin(costs), begin(costs) + n - 1, end(costs), [](auto& x, auto& y) {
           return x[1] - x[0] > y[1] - y[0]; 
        });
        
        int cityA = 0, cityB = 0;
        
        for (int i = 0; i < n; i++) {
            cityA += costs[i][0];
        }
        
        for (int i = n; i < n*2; i++) {
            cityB += costs[i][1];
        }
        
        return cityA + cityB;
    }
};