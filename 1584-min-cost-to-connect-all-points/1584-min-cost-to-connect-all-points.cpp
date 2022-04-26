class Solution {   
    typedef priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> PQ;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        PQ Q;
        n = points.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int cost = getCost(points[i], points[j]);
                //cout << i << ' ' << j << ' ' << cost << endl;
                Q.push({cost, i, j});
            }
        }
        
        return getMinCost(Q);
    }

private:
    int n;
    vector<int> parents;
    vector<int> rank;
    
    int getCost(vector<int>& x, vector<int>& y) {
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    }
    
    int getParent(int x) {
        if (parents[x] == x) return x;
        return parents[x] = getParent(parents[x]);
    }
    
    void makeUnion(int x, int y) {
        if (rank[x] > rank[y]) {
            parents[y] = x;
        }
        else if (rank[x] < rank[y]) {
            parents[x] = y;
        }
        else {
            parents[x] = y;
            rank[y]++;
        }
    }
    
    int getMinCost(PQ& Q) {
        parents.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        int totalCost = 0, totalConnection = 0;
        
        while (totalConnection < n-1) {
            auto[cost, pointA, pointB] = Q.top();
            Q.pop();
            
            int pa = getParent(pointA);
            int pb = getParent(pointB);
            
            if (pa != pb) {
                totalConnection++;
                totalCost += cost;
                //cout << pointA << ' ' << pointB << ' ' << cost << endl;
                makeUnion(pa, pb);
            }
        }
        
        return totalCost;
    }
};