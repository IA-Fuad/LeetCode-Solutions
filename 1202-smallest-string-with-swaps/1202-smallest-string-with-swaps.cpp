class Solution {
    vector<int> parent, rank;
    
    int getParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }
    
    void makeUnion(int x, int y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else if (rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < pairs.size(); i++) {
            int x = pairs[i][0], y = pairs[i][1];
            
            int px = getParent(x);
            int py = getParent(y);
            
            if (px != py) {
                makeUnion(px, py);
            }
        }
        
        unordered_map<int, vector<int>> indices;
        
        for (int i = 0; i < n; i++) {
            indices[getParent(i)].push_back(i);
        }
        
        for (auto group : indices) {
            string groupLetters;
            for (int ind : group.second) {
                groupLetters.push_back(s[ind]);
            }
            sort(groupLetters.begin(), groupLetters.end());
            int k = 0;
            for (int ind : group.second) {
                s[ind] = groupLetters[k++];
            }
        }
        
        return s;
    }
};