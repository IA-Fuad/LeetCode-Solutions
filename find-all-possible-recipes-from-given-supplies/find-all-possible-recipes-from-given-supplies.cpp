class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indxs;
        unordered_map<int, string> values;
        
        int ind = 1;
        for (string s : recipes) {
            values[ind] = s;
            indxs[s] = ind++;
        }
        for (auto& v : ingredients) {
            for (string s : v) {
                auto it = indxs.find(s);
                if (it == indxs.end()) {
                    values[ind] = s;
                    indxs[s] = ind++;
                }
            }
        }
        
        int n = recipes.size();
        vector<vector<int>> graph(ind);
        vector<int> degree(ind, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto s : ingredients[i]) {
                int u = indxs[recipes[i]], v = indxs[s];
                graph[v].push_back(u);
                degree[u]++;
            }
        }
        
        queue<int> q;
        for (int i = 1; i < ind; i++) {
            //cout << degree[i] << ' ';
            if (degree[i] == 0 && find(supplies.begin(), supplies.end(), values[i]) != supplies.end()) q.push(i);
        }     
        
        vector<string> ans;
        while (!q.empty()) {
            int u = q.front();
            //cout << u << ' ' << values[u] << endl;
            q.pop();
            if (u <= n) ans.push_back(values[u]);
            for (int v : graph[u]) {
                degree[v]--;
                if (degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
};