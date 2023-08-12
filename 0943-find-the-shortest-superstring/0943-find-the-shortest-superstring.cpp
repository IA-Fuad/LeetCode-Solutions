class Solution {
    string buildString(vector<string>& words, vector<int>& ind, vector<vector<int>>& overlap) {
        string S = words[ind[0]];
        for (int i = 1; i < ind.size(); i++) {
            int k = overlap[ind[i-1]][ind[i]];
            
            while (k < words[ind[i]].size()) {
                S.push_back(words[ind[i]][k++]);
            }
        }
        return S;
    }
    
    int getOverlapCount(const string& a, const string& b) {
        for (int k = b.size(); k > 0; k--) {
            string x = b.substr(0, k);
            if (x.size() > a.size()) continue;
            
            bool match = true;
            for (int i = a.size()-1, j = x.size()-1; i >= 0 and j >= 0; i--, j--) {
                if (a[i] != x[j]) {
                    match = false;
                    break;
                }
            }
            
            if (match) return k;
        }
        return 0;
    }

    
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<int> ind;
        
        int N = (1 << n) - 1;
        vector<vector<int>> dp(N+1, vector<int>(n, 0)), overlap(n, vector<int>(n, 0)), parent(N+1, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                overlap[i][j] = getOverlapCount(words[i], words[j]);
            }
        }

        for (int mask = 0; mask <= N; mask++) {
            for (int last = 0; last < n; last++) {
                if (((mask >> last) & 1) > 0) {
                    int preMask = mask ^ (1 << last);
                    if (preMask == 0) continue;
                    
                    for (int preLast = 0; preLast < n; preLast++) {
                        if (((preMask >> preLast) & 1) > 0) {
                            int newOverlap = dp[preMask][preLast] + overlap[preLast][last];
                            if (newOverlap >= dp[mask][last]) {
                                dp[mask][last] = newOverlap;
                                parent[mask][last] = preLast;
                            }
                        }
                    }
                }
            }
        }
        
        int maxOverlap = 0, lastIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[N][i] > maxOverlap) {
                maxOverlap = dp[N][i];
                lastIndex = i;
            }
        }

        int mask = (1 << n) - 1;
        while (lastIndex != -1) {
            ind.push_back(lastIndex);
            int temp = lastIndex;
            lastIndex = parent[mask][lastIndex];
            mask ^= (1 << temp);
        }
        
        reverse(ind.begin(), ind.end());
        
        return buildString(words, ind, overlap);
    }
};