class Solution {
    string buildString(vector<string>& words, vector<int>& ind) {
        string S = "";
        for (int i : ind) {
           // cout << i << ' ';
            const string& word = words[i];
            int a = 0, b = 0;
            if (S.find(word) != string::npos) continue;
            for (int k = word.size()-1; k > 0; k--) {
                string x = word.substr(0, k);
                if (S.size() < x.size()) continue;
                bool ok = true;
                for (int p = x.size()-1, q = S.size()-1; p >= 0 and q >= 0; p--, q--) {
                    if (x[p] != S[q]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    b = k;
                    break;
                }
            }
            
            for (int k = b; k < word.size(); k++) S += word[k];
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
                //cout << words[i] << ' ' << words[j] << ' ' << overlap[i][j] << endl;
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
                                //cout << mask << ' ' << preMask << ' ' << last << ' ' << preLast << ' ' << dp[mask][last] << endl;
                                parent[mask][last] = preLast;
                            }
                        }
                    }
                }
            }
        }
        
        int maxOverlap = 0, lastIndex = 0;
        for (int i = 0; i < n; i++) {
           // cout << dp[N][i] << ' ';
            if (dp[N][i] > maxOverlap) {
                maxOverlap = dp[N][i];
                lastIndex = i;
            }
        }

        int mask = (1 << n) - 1;
       // cout << mask << ' ' << parent[mask][lastIndex] << endl;
        while (lastIndex != -1) {
          //  cout << lastIndex << ' ';
            ind.push_back(lastIndex);
            int temp = lastIndex;
            lastIndex = parent[mask][lastIndex];
            mask ^= (1 << temp);
        }
        
        reverse(ind.begin(), ind.end());
        
        return buildString(words, ind);
    }
};