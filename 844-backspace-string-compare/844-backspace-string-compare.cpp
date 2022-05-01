class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        for (int c : s) {
            if (c == '#') {
                if (ss.size() > 0) ss.pop_back();
            }
            else ss += c;
        }
        for (int c : t) {
            if (c == '#') {
                if (tt.size() > 0) tt.pop_back();
            }
            else tt += c;
        }

        return ss == tt;
    }
};