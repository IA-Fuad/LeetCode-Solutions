class Solution {
    typedef unordered_map<string, vector<pair<string, double>>> Graph;
    typedef unordered_map<string, bool> StringToBool;
    
    double rec(Graph& graph, StringToBool& visited, string variable, string& target, double product) {
        if (variable == target) {
            return product;
        }

        visited[variable] = true;
        
        double ans = -1.0;
        for (auto& v : graph[variable]) {
            if (visited[v.first]) continue;
            ans = rec(graph, visited, v.first, target, product * v.second);
            
            if (ans != -1) break;
        }

        //visited[variable] = false;
        return ans;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        Graph graph;
        StringToBool visited;
        int n = values.size();
        
        for (int i = 0; i < n; i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], (1.0/values[i])});
        }
        
        vector<double> answers;

        for (auto query : queries) {
            visited.clear();
            double result;
            if (graph[query[0]].size() == 0 or graph[query[1]].size() == 0) result = -1;
            else result = rec(graph, visited, query[0], query[1], 1.0);
            answers.push_back(result);
        }
        
        return answers;
    }
};

/*

a -> b = 2
b -> a = 0.5

b -> c = 3
c -> b = 0.33

c -> d = 2
d -> c = 0.5

a/b = 2
b/c = 3

a/b * b/c = 3 * 2

a/c = 6


*/