class Solution {
    vector<vector<int>> ans;
    vector<int> comb;
    
    void rec(int i, int n, int k) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        for (int j = i+1; j <= n; j++) {
            comb.push_back(j);
            rec(j, n, k);
            comb.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        rec(0, n, k);
        return ans;
    }
};