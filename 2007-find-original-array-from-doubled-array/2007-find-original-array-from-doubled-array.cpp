class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};
        
        int mx = *max_element(changed.begin(), changed.end());
        vector<int> sorted(mx+1);
        
        for (int num : changed) {
            sorted[num]++;
        }
        if (sorted[0]&1) return {};

        vector<int> ans;
        
        for (int i = 0; i <= mx; i++) {
            if (sorted[i] == 0) continue;
            
            int dbl = (i << 1);
            //cout << i << ' ' << dbl << endl;
            if ((sorted[i] > 0 and dbl > mx) or sorted[i] > sorted[dbl]) return {};
            while (sorted[i] > 0) {
                ans.push_back(i);
                sorted[i]--;
                sorted[dbl]--;
            }
        }
        
        return ans;
    }
};