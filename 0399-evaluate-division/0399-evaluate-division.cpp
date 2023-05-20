class Solution {
    double divide(vector<vector<pair<int, double>>>& graph, vector<bool>& vis, int varX, int varY, double ans) {
        if (varX == varY) {
            return ans;
        }
        for (auto[var, val] : graph[varX]) {
            if (!vis[var]) {
                vis[var] = true;
                double div = divide(graph, vis, var, varY, ans * val);
                if (div != -1) {
                    return div;
                }
            }
        }
        
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<vector<pair<int, double>>> graph(100);
        unordered_map<string, int> var;
        int varId = 0;
        
        for (int i = 0; i < values.size(); i++) {
            int x, y;
            if (var.find(equations[i][0]) == var.end()) {
                var[equations[i][0]] = varId++;
            }    
            if (var.find(equations[i][1]) == var.end()) {
                var[equations[i][1]] = varId++;
            }
            x = var.find(equations[i][0])->second;
            y = var.find(equations[i][1])->second;
            
            graph[x].push_back({y, values[i]});
            graph[y].push_back({x, 1.0/values[i]});
        }
        
        vector<double> division;
        
        for (auto& query : queries) {
            auto x = var.find(query[0]);
            auto y = var.find(query[1]);
            
            if (x == var.end() or y == var.end()) {
                division.push_back(-1);
                continue;
            }
            vector<bool> vis(varId);
            vis[x->second] = true;
            division.push_back(divide(graph, vis, x->second, y->second, 1));       
        }
        
        return division;
    }
};
