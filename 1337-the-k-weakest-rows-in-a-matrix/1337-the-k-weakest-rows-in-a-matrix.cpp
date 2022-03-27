class Solution {
    int getSoliderCount(const vector<int>& x) {
        return x.size() - (lower_bound(x.rbegin(), x.rend(), 1) - x.rbegin());
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> kwr;
        
        for (int i = 0; i < mat.size(); i++) {
            int score = getSoliderCount(mat[i]);
            
            if (kwr.empty() or kwr.size() < k) kwr.push({score, i});
            else if (score < kwr.top().first) {
                kwr.pop();
                kwr.push({score, i});
            }
        }
        
        vector<int> ans(k);
        
        while (!kwr.empty()) {
            ans[--k] = kwr.top().second;
            kwr.pop();
        }
        
        return ans;
    }
};