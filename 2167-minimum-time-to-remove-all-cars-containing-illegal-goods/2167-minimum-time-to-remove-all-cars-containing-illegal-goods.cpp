class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> left(n), right(n);
        
        int mn = INT_MAX, t1, t2;
        
        for (int i = 0, t = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i+1 <= t+2) {
                    while (i < n && s[i] == '1') {
                        t = i+1;
                        left[i] = t;
                        i++;
                    }
                    i--;
                    continue;
                }
                else {
                    t += 2;
                }
            }
            left[i] = t;
        }

        int mn2 = INT_MAX;
        for (int i = n-1, t = 0; i >= 0; i--) {
            if (s[i] == '1') {
                if ((n-i) <= t+2) {
                    while (i >= 0 && s[i] == '1') {
                        t = n-i;
                        right[i] = t;
                        i--;
                    }
                    i++;
                    continue;
                }
                else {
                    t += 2;
                }
            }
            right[i] = t;
        }
        
        mn = min(left[n-1], right[0]);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int x = INT_MAX, y = INT_MAX;
                if (i > 0) x = left[i-1] + right[i];
                if (i < n-1) y = left[i] + right[i+1];
                mn = min(mn, min(x, y));
            }
        }
        
        return mn;
    }
};