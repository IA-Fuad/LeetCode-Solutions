class Solution {
    const int maxNum = 1e9;
    
    vector<int> sum;

    void getSections(vector<vector<pair<int, int>>>& sections, vector<pair<int, int>>& section, int left, int right, int k, int K) {
        if (left > right) return;
        if (k == 1) {
            section.push_back({left, right});
            sections.push_back(section);
            section.pop_back();
            return;
        }
        
        for (int i = left; i <= right; i++) {
            if (i != left and i - left + 1 < K) continue;
            section.push_back({left, i});
            getSections(sections, section, i+1, right, k-1, K);
            section.pop_back();
        }
    }
    
    vector<vector<pair<int, int>>> dp;

    pair<int, int> rec(vector<int>& stones, int left, int right, int k) {
        if (left == right or (right - left + 1) == k) {
            if (left == right) return {0, 0};
            return {sum[right+1] - sum[left], 0};
        }
        if ((right - left) + 1 < k) {
            return {maxNum, 0};
        }
        if (dp[left][right].first != -1) {
            return dp[left][right];
        }
        
        vector<vector<pair<int, int>>> sections;
        vector<pair<int, int>> section;
        
        getSections(sections, section, left, right, k, k);
        int minCost = maxNum, minAc = 0, minTc = maxNum;
        
        for (auto sec : sections) {
            int cost = 0, ac = 0;
            for (auto[l, r] : sec) {
                auto currCost = rec(stones, l, r, k);
                if (currCost.first == maxNum) {
                    cost = maxNum;
                    break;
                }
                
                cost += currCost.first;
                if (currCost.first == 0) cost += stones[l], ac -= stones[l];
                ac += currCost.second;
                //if (l != r) cost += currCost;
            }
            ac += cost;
           // cout << cost << ' ' << ac << endl;
            if (cost + ac < minTc) {
                minCost = cost;
                minAc = ac;
                minTc = cost + ac;
            } 
        }
        return dp[left][right] = {minCost, minAc};
    }
    
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        sum.resize(n+1, 0);
        dp.resize(n+1, vector<pair<int,int>>(n+1, {-1, -1}));
        
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + stones[i];
        }
        
        auto cost = rec(stones, 0, n-1, k);
        return cost.first == maxNum ? -1 : cost.first + cost.second;
    }
};