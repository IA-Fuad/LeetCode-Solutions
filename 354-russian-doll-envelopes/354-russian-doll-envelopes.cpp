class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto& x, auto& y) {
            if (x[0] == y[0]) return x[1] > y[1];
            return x[0] < y[0];
        });
        
        vector<int> maxEnv;
        
        for (int i = 0; i < envelopes.size(); i++) {
            if (maxEnv.size() == 0 or maxEnv.back() < envelopes[i][1]) {
                maxEnv.push_back(envelopes[i][1]);
            }
            else {
                int pos = lower_bound(maxEnv.begin(), maxEnv.end(), envelopes[i][1]) - maxEnv.begin();
                if (maxEnv[pos] > envelopes[i][1]) {
                    maxEnv[pos] = envelopes[i][1];
                }
            }
        }
        
        return maxEnv.size();
    }
};

/*

[[5,4],[6,4],[6,7],[2,3]]

[2,3]
[5,4]
[6,4]
[6,7]

[2,33] - 1
[3,34] - 2
[4,30] - 1 
[7,4] - 1
[7,4] - 1
[7,39] - 1
[8,38] 

4 34

*/