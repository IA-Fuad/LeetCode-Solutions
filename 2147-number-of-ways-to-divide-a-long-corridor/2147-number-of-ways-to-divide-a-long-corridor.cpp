class Solution {
    const int64_t mod = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int s = 0;
        for (char c : corridor) if (c == 'S') s++;
        if (s < 2 || s&1) return 0;
        
        int64_t ans = 1, p = 0;
        s = 0;
        
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                s++;
                if (s%2 == 1) {
                    ans = (ans * (p + 1)) % mod;
                }
                p = 0;
            }
            else if (s > 0) p++;
        }
        
        return ans;
    }
};