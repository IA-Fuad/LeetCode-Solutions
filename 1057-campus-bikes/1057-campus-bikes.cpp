class Solution {
    struct DistanceInfo {
        int wi;
        int bi;
        int dist;
        
        DistanceInfo(int wi, int bi, int dist) {
            this->wi = wi;
            this->bi = bi;
            this->dist = dist;
        }
    };
    
    int getManhattanDistance(vector<int> a, vector<int> b) {
        int xDist = abs(a[0] - b[0]);
        int yDist = abs(a[1] - b[1]);
        return xDist + yDist;
    }

public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // auto sortComparer = [](const DistanceInfo& x, const DistanceInfo& y)->bool {
        //     if (x.dist == y.dist) {
        //         if (x.wi == y.wi) {
        //             return x.bi > y.bi;
        //         }
        //         return x.wi > y.wi;
        //     }
        //     return x.dist > y.dist;
        // };

        //typedef priority_queue<DistanceInfo, vector<DistanceInfo>, decltype(sortComparer)> PQ;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
        
        for (int b = 0; b < bikes.size(); b++) {
            for (int w = 0; w < workers.size(); w++) {
                Q.push({getManhattanDistance(bikes[b], workers[w]), b, w});
            }
        }
        
        unordered_set<int> bikeTaken, workerTaken;
        vector<int> ans(workers.size());
        int k = 0;

        while (k < workers.size()) {
            int wi = get<2>(Q.top());
            int bi = get<1>(Q.top());
            Q.pop();
            if (bikeTaken.find(bi) == bikeTaken.end() and workerTaken.find(wi) == workerTaken.end()) {
                bikeTaken.insert(bi);
                workerTaken.insert(wi);
                ans[wi] = bi;
                k++;
            }
        }
        
        return ans;
    }
};