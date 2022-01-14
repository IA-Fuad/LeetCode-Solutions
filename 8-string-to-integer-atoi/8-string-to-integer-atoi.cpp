class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1, ans = 0;
        while (i < n && s[i] == ' ') i++;
        if (i < n) {
            if (s[i] == '-') sign = -1;
            if (s[i] == '-' || s[i] == '+') i++;
        }
        int x = INT_MAX / 10;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            if (ans < x) {
                ans = (ans * 10) + (s[i] - '0');
            }
            else if (ans >= x) {
                if (ans == x && !(i < n-1 && s[i+1] >= '0' && s[i+1] <= '9')) {
                    ans = (ans * 10) + (min(s[i], '7') -'0');
                    if (sign == -1 && s[i] >= '8') {
                        ans = -ans;
                        ans--;
                        sign = 1;
                    }
                } 
                else {
                    ans = sign == -1 ? INT_MIN : INT_MAX;
                    sign = 1;
                }
                break;
            }
            i++;
        }
        return ans * sign;
    }
};