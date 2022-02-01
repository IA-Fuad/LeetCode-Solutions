class Solution {
    int parent[200];
    int childCount[200];
    
    int findParent(int n) {
        if (parent[n] == n) return n;
        return findParent(parent[n]);
    }
    
    void uni(int a, int b) {
        parent[b] = a;
        childCount[a] += childCount[b];
    }
    
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            childCount[i] = 1;
        }
        
        for (auto log : logs) {
            int pa = findParent(log[1]);
            int pb = findParent(log[2]);
            
            if (pa != pb) {
                uni(pa, pb);
                if (childCount[pa] == n) return log[0];
            }
        }
        
        return -1;
    }
};