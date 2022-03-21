class Solution {
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    
    void merge(int a, int b) {
        if (ranks[a] >= ranks[b]) {
            parents[b] = a;
            ranks[a]++;
        }
        else {
            parents[a] = b;
            ranks[b]++;
        }
    }
    
    int findParent(int a) {
        if (parents[a] == a) return a;
        return parents[a] = findParent(parents[a]);
    }
    
    int getId(int i, int j, int n) {
        return n * i + j;
    }
    
    void initParents(int m, int n) {
        for (int i = 0; i <= n*m; i++) {
            parents[i] = -1;
            ranks[i] = 0;
        }
    }
    
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int islands = 0;
        vector<int> ans;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        initParents(m, n);
        
        for (auto position : positions) {
            int i = position[0];
            int j = position[1];
            int id = getId(i, j, n);
            
            if (parents[id] == -1) {
                parents[id] = id;
                islands++;
            }
            
            for (int k = 0; k < 4; k++) {
                int neighborI = dx[k] + i;
                int neighborJ = dy[k] + j;
                int neighborId = getId(neighborI, neighborJ, n);
                
                if (neighborI < 0 or neighborI == m or neighborJ < 0 or neighborJ == n or parents[neighborId] == -1) continue;

                int parentA = findParent(id);
                int parentB = findParent(neighborId);
                
                if (parentA != parentB) {
                    islands--;
                    merge(parentA, parentB);
                }
            }
            
            ans.push_back(islands);
        }
        
        return ans;
    }
};